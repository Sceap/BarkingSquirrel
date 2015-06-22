#include <QApplication>
#include <QObject>
#include <QtWidgets>

#include "protocole.h"
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    // Creating a Qt Application environment
    QApplication drsOrders(argc, argv);

    // Creating and showing a window
    mainWindow mWindow;
    mWindow.show();

    // Note: as for each Qt Application, the
    // main code appears in the "mainwindow.cpp"
    // file holding the code for handling the main
    // window

    return drsOrders.exec();
}
