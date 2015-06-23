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
#include "logdialog.h"


class mainWindow : public QWidget
{
    Q_OBJECT

    public:
        mainWindow();

    public slots:
        void startStop();
        void openSerialPort();
        void closeSerialPort();

        void updateData();
    private:
        void updateXAxis(double value, double time);
        void updateYAxis(double value);
        void updateConsole(QString str);

        void initActionsConnections();

        Protocole * protocole;

        SettingsDialog * settings;

        QTextEdit * textEdit;
        QCustomPlot * graph[10];

        QPushButton * actionConnect, * actionDisconnect, * actionQuit, * actionConfigure, * actionLog, * stopStart;
        QCheckBox * logToFile, * appendDate;
        QLineEdit * fileName;

        QVector<double> *x[10], *y[10];

        QFile * log;
};

#endif // MAINWINDOW_H
