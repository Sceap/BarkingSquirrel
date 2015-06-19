#include <QApplication>
#include <QObject>
#include <QtWidgets>

#include "protocole.h"
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication ctroSim(argc, argv);

    mainWindow mWindow;


    mWindow.show();

    return ctroSim.exec();
}
