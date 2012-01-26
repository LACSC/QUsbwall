
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QString>
#include <iostream>
#include <libusbwall.h>
#include "qusbwall.hh"

using namespace Ui;

// Constructor
QUsbwallMaster::QUsbwallMaster(QWidget *parent __attribute__((unused)))
{
  setupUi((QMainWindow*)this);
  int ret = 0;
  int release = 0;

  // post setup of some widget
  list_keyfile->setColumnCount(4);
  // connecting slots
  connect( actionLoad_key_file, SIGNAL( triggered() ), this, SLOT( LoadKeyfile() ) );
  connect( button_loadkeyfile, SIGNAL( clicked() ), this, SLOT( LoadAllKeys() ) );

  // initialize libusbwall
  ret = usbwall_init();
  if (ret != 0) {
     std::cout << "Unable to initialize libusbwall !" << std::endl;
     exit(1);
  }
  // get back module release
  release = usbwall_get_release();
  label_release->setNum(release);
}

/*
 * \brief open the key file
 *
 *  Reacting to the File->open action. Open the keyfile and load its content.
 */
void QUsbwallMaster::LoadKeyfile(void)
{
    QString filename;
    QString line;
    std::cout << "Loading key file..." << std::endl;
    int i = 0;

    list_keyfile->setRowCount(0);
    // showing file selection dialog and get back file name
    filename = QFileDialog::getOpenFileName(this,
                                            tr("Open Key file"), "/etc", tr("Usbwall key lists (*.ukl)"));
    // set keyfile to filename.
    keyfile.setFileName(filename);

    // opening, reading and closing file.
    if (keyfile.open(QFile::ReadWrite)) {
        QTextStream stream( &keyfile );

        while (!stream.atEnd()) { // foreach line
            line = stream.readLine();
            QStringList stringlist = line.split(" ");
            QString id;
            id.setNum((i++) + 1);
            // add item to list
            int row = list_keyfile->rowCount();
            QTableWidgetItem *id_item = new QTableWidgetItem(id);
            list_keyfile->insertRow(row);
            list_keyfile->setItem(row, 0, id_item);
            // no file check by now ! to be added!
            for (int j = 0; j < 3; ++j) {
              QTableWidgetItem *item = new QTableWidgetItem(stringlist.at(j));
              list_keyfile->setItem(row, j + 1, item);
            }
            std::cout << "line: " << line.toStdString() << std::endl;
        }
        keyfile.close();
    }
    // Okay now we need to load the file content into list_keyfile (Ui managed QListView)
    std::cout << "Keyfile loaded." << std::endl;
}


void QUsbwallMaster::LoadAllKeys(void)
{
  int i = 0;
  uint16_t prodid = 0;
  uint16_t vendid = 0;
  std::string   serial;
  QTableWidgetItem *item = NULL;

  QString txt;

  std::cout << "loading keyfile into module usbwall" << std::endl;
  if (list_keyfile->rowCount() == 0) {
      std::cout << "no key to add!" << std::endl;
      return; // No key to add...
  }
  for (i = 0; i < list_keyfile->rowCount(); ++i) {
    // getting key infos
      item = list_keyfile->item(i, 1);
      txt = item->text();
      vendid = (uint16_t)txt.toInt();
      item = list_keyfile->item(i, 2);
      txt = item->text();
      prodid = (uint16_t)txt.toInt();
      item = list_keyfile->item(i, 3);
      txt = item->text();
      serial = txt.toStdString();
      std::cout << "adding key " << serial << std::endl;
      usbwall_key_add(vendid, prodid, serial.c_str());
  }
}
