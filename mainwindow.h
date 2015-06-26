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
    enum sessionSettings {
        FILENAME = 0,
        LOGTOFILE = 1,
        APPENDDATE = 2,
        CMDVALUE = 3,
        PORT = 4,
        BAUDRATE = 5,
        DATABITS = 6,
        PARITY = 7,
        STOPBITS = 8,
        FLOWCONTROL = 9
    };


    Q_OBJECT

    public:
        mainWindow();

    public slots:
        void openSerialPort();
        void closeSerialPort();

        void saveSession();

        void sendCommand(QString cmd);
        void sendCommandBox(QString cmd);

        void getSysTime();
        void getRTCTime();
        void sendRTCTime();

        void updateData();

        void update();
        void update_c();
    private:
        Ui::MainWindow *ui;

        void updateXAxis(double value, double time);
        void updateYAxis(double value);
        void updateTimeGraph(double value, int graph);
        void updateConsole(QString str);
        void restoreSession();

        void initActionsConnections();

        Protocole * protocole;

        SettingsDialog * settings;

        QCustomPlot * graph[10];

        QVector<double> *x[10], *y[10];
        QString str;

        QTimer * serialFetch, * guiUpdate;

        QFile * log;
        QFile * session;

    signals:
        void resync();
};

#endif // MAINWINDOW_H
