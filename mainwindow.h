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
    QCustomPlot * graph;
    QCustomPlot * graph_cos;
    QCustomPlot * graph_xy;

    QPushButton * actionConnect, * actionDisconnect, * actionQuit, * actionConfigure;

    QVector<double> *x, *y;
    QVector<double> *y_cos, *x_cos, *xy_x, *xy_y;
};

#endif // MAINWINDOW_H
