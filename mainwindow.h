#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QVector>
#include <QTimer>
#include <QFile>
#include "qcustomplot.h"
#include "protocole.h"
#include "settingsdialog.h"
#include "fileviewer.h"
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
        FileViewer * file_viewer;

        QCustomPlot * graph[10];

        QVector<double> *x[10], *y[10];
        QString str;

        QTimer * serialFetch, * guiUpdate;

        QFile * log;
        QFile * session;
};

#endif // MAINWINDOW_H
