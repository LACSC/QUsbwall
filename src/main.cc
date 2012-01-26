
#include <QApplication>
#include "qusbwall.hh"
#include "main.hh"

using namespace Ui;

int main(int argc, char *argv[])
{
    int ret = 1;

    QApplication app(argc, argv);
    QUsbwallMaster *mainwindow = new QUsbwallMaster;

    mainwindow->show();
    ret = app.exec();
    return ret;
}
