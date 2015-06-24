#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QVector>
#include <QTimer>
#include <QFile>
#include "qcustomplot.h"
#include "protocole.h"
#include "settingsdialog.h"
#include "spinbox.h"

QT_USE_NAMESPACE

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class mainWindow : public QMainWindow
{


    Q_OBJECT

    public:
        mainWindow();

    public slots:
        void openSerialPort();
        void closeSerialPort();

        void sendCommand(QString cmd);
        void sendCommandBox(QString cmd);

        void getSysTime();
        void getRTCTime();
        void sendRTCTime();

        void updateData();
    private:
        Ui::MainWindow *ui;

        void updateXAxis(double value, double time);
        void updateYAxis(double value);
        void updateConsole(QString str);

        void initActionsConnections();

        Protocole * protocole;

        SettingsDialog * settings;

        QCustomPlot * graph[10];

        QVector<double> *x[10], *y[10];

        QFile * log;
};

#endif // MAINWINDOW_H
