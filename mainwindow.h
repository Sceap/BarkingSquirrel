#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QVector>
#include <QTimer>
#include "qcustomplot.h"
#include "protocole.h"
#include "settingsdialog.h"


class mainWindow : public QWidget
{
    Q_OBJECT

    public:
    mainWindow();
    void initActionsConnections();


public slots:
    void startStop();
    void openSerialPort();
    void closeSerialPort();

    void updateData();
private:
    void changeData(double str, double t);
    void changeDataCos(double str);
    void appendHTML(QString str);

    SettingsDialog * settings;
    Protocole * protocole;
    QTextEdit * textEdit;
    QCustomPlot * graph[10];

    QPushButton * actionConnect, * actionDisconnect, * actionQuit, * actionConfigure;

    QVector<double> *x[10], *y[10];
};

#endif // MAINWINDOW_H
