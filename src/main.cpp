#include <QApplication>
#include "main.h"

int main(int argc, char *argv[])
{
    int ret = 1;
    initialize_all();

    QApplication app(argc, argv);
    QUsbwall *mainwindow = new QUsbwall;

    mainwindow->show();
    ret = app.exec();
    return ret;
}
