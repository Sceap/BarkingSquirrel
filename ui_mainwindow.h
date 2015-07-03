/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"
#include "spinbox.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *actionConnect;
    QPushButton *actionDisconnect;
    QPushButton *actionConfigure;
    QSpacerItem *horizontalSpacer_27;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *fileName;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *logToFile;
    QCheckBox *appendDate;
    QPushButton *viewLog;
    QSpacerItem *horizontalSpacer_28;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *cmdFreq;
    QPushButton *cmdBurst;
    QPushButton *cmdStream;
    QLabel *label_2;
    QSpinBox *cmdValue;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QLineEdit *cmdCusom;
    QPushButton *cmdCustomSend;
    QSpacerItem *horizontalSpacer_37;
    QSpacerItem *horizontalSpacer_36;
    QSpacerItem *horizontalSpacer_35;
    QSpacerItem *horizontalSpacer_34;
    QSpacerItem *horizontalSpacer_33;
    QSpacerItem *horizontalSpacer_26;
    QSpacerItem *horizontalSpacer_30;
    QSpacerItem *horizontalSpacer_29;
    QSpacerItem *horizontalSpacer_32;
    QSpacerItem *horizontalSpacer_31;
    QSpacerItem *horizontalSpacer_25;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_8;
    QPushButton *logUpdate;
    QPlainTextEdit *logConsole;
    QSpacerItem *horizontalSpacer_38;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *graphXAxis;
    QCustomPlot *graphYAxis;
    QCustomPlot *graphZAxis;
    QCustomPlot *graphXY;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_9;
    QCustomPlot *gyroX;
    QCustomPlot *gyroY;
    QVBoxLayout *verticalLayout_10;
    QCustomPlot *gyroZ;
    QWidget *widget;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    SpinBox *RTCYear;
    QLabel *label_4;
    SpinBox *RTCMonth;
    QLabel *label_5;
    SpinBox *RTCDay;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_6;
    SpinBox *RTCHour;
    QLabel *label_7;
    SpinBox *RTCMinute;
    QLabel *label_8;
    SpinBox *RTCSecond;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *getTime;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_23;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *syncSysTime;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *sendTime;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_18;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_40;
    QLabel *label_10;
    QLineEdit *fileNameSD;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_41;
    QCheckBox *logToFileSD;
    QCheckBox *appendDateSD;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_19;
    QSpacerItem *horizontalSpacer_42;
    QCheckBox *logBluetooth;
    QCheckBox *logUSB;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_39;
    QPushButton *applyLog;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *horizontalSpacer_24;
    QSpacerItem *verticalSpacer_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1163, 696);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMaximumSize(QSize(250, 16777215));
        groupBox->setStyleSheet(QStringLiteral(""));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        actionConnect = new QPushButton(groupBox);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));

        horizontalLayout_4->addWidget(actionConnect);

        actionDisconnect = new QPushButton(groupBox);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));

        horizontalLayout_4->addWidget(actionDisconnect);

        actionConfigure = new QPushButton(groupBox);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));

        horizontalLayout_4->addWidget(actionConfigure);


        horizontalLayout->addWidget(groupBox);

        horizontalSpacer_27 = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_27);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        fileName = new QLineEdit(groupBox_2);
        fileName->setObjectName(QStringLiteral("fileName"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fileName->sizePolicy().hasHeightForWidth());
        fileName->setSizePolicy(sizePolicy2);

        horizontalLayout_13->addWidget(fileName);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_13->addWidget(label_9);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        logToFile = new QCheckBox(groupBox_2);
        logToFile->setObjectName(QStringLiteral("logToFile"));

        horizontalLayout_3->addWidget(logToFile);

        appendDate = new QCheckBox(groupBox_2);
        appendDate->setObjectName(QStringLiteral("appendDate"));

        horizontalLayout_3->addWidget(appendDate);

        viewLog = new QPushButton(groupBox_2);
        viewLog->setObjectName(QStringLiteral("viewLog"));

        horizontalLayout_3->addWidget(viewLog);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addWidget(groupBox_2);

        horizontalSpacer_28 = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_28);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        horizontalLayout_5 = new QHBoxLayout(groupBox_3);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        cmdFreq = new QPushButton(groupBox_3);
        cmdFreq->setObjectName(QStringLiteral("cmdFreq"));

        horizontalLayout_6->addWidget(cmdFreq);

        cmdBurst = new QPushButton(groupBox_3);
        cmdBurst->setObjectName(QStringLiteral("cmdBurst"));

        horizontalLayout_6->addWidget(cmdBurst);

        cmdStream = new QPushButton(groupBox_3);
        cmdStream->setObjectName(QStringLiteral("cmdStream"));

        horizontalLayout_6->addWidget(cmdStream);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_6->addWidget(label_2);

        cmdValue = new QSpinBox(groupBox_3);
        cmdValue->setObjectName(QStringLiteral("cmdValue"));
        cmdValue->setMaximum(65535);

        horizontalLayout_6->addWidget(cmdValue);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_8->addWidget(label);

        cmdCusom = new QLineEdit(groupBox_3);
        cmdCusom->setObjectName(QStringLiteral("cmdCusom"));

        horizontalLayout_8->addWidget(cmdCusom);

        cmdCustomSend = new QPushButton(groupBox_3);
        cmdCustomSend->setObjectName(QStringLiteral("cmdCustomSend"));

        horizontalLayout_8->addWidget(cmdCustomSend);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_5->addLayout(verticalLayout_2);


        horizontalLayout->addWidget(groupBox_3);

        horizontalSpacer_37 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_37);

        horizontalSpacer_36 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_36);

        horizontalSpacer_35 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_35);

        horizontalSpacer_34 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_34);

        horizontalSpacer_33 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_33);

        horizontalSpacer_26 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_26);

        horizontalSpacer_30 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_30);

        horizontalSpacer_29 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_29);

        horizontalSpacer_32 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_32);

        horizontalSpacer_31 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_31);

        horizontalSpacer_25 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_25);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(-1, -1, 0, -1);
        logUpdate = new QPushButton(centralwidget);
        logUpdate->setObjectName(QStringLiteral("logUpdate"));
        logUpdate->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(logUpdate->sizePolicy().hasHeightForWidth());
        logUpdate->setSizePolicy(sizePolicy3);
        logUpdate->setMinimumSize(QSize(0, 10));
        logUpdate->setMaximumSize(QSize(246, 64));
        logUpdate->setBaseSize(QSize(0, 32));

        verticalLayout_8->addWidget(logUpdate);

        logConsole = new QPlainTextEdit(centralwidget);
        logConsole->setObjectName(QStringLiteral("logConsole"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(logConsole->sizePolicy().hasHeightForWidth());
        logConsole->setSizePolicy(sizePolicy4);
        logConsole->setMaximumSize(QSize(246, 16777215));

        verticalLayout_8->addWidget(logConsole);


        horizontalLayout_2->addLayout(verticalLayout_8);

        horizontalSpacer_38 = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_38);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_9 = new QHBoxLayout(tab);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        graphXAxis = new QCustomPlot(tab);
        graphXAxis->setObjectName(QStringLiteral("graphXAxis"));

        verticalLayout_3->addWidget(graphXAxis);

        graphYAxis = new QCustomPlot(tab);
        graphYAxis->setObjectName(QStringLiteral("graphYAxis"));

        verticalLayout_3->addWidget(graphYAxis);

        graphZAxis = new QCustomPlot(tab);
        graphZAxis->setObjectName(QStringLiteral("graphZAxis"));

        verticalLayout_3->addWidget(graphZAxis);


        horizontalLayout_9->addLayout(verticalLayout_3);

        graphXY = new QCustomPlot(tab);
        graphXY->setObjectName(QStringLiteral("graphXY"));

        horizontalLayout_9->addWidget(graphXY);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        horizontalLayout_7 = new QHBoxLayout(tab_3);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        gyroX = new QCustomPlot(tab_3);
        gyroX->setObjectName(QStringLiteral("gyroX"));

        verticalLayout_9->addWidget(gyroX);

        gyroY = new QCustomPlot(tab_3);
        gyroY->setObjectName(QStringLiteral("gyroY"));

        verticalLayout_9->addWidget(gyroY);


        horizontalLayout_7->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        gyroZ = new QCustomPlot(tab_3);
        gyroZ->setObjectName(QStringLiteral("gyroZ"));

        verticalLayout_10->addWidget(gyroZ);

        widget = new QWidget(tab_3);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout_10->addWidget(widget);


        horizontalLayout_7->addLayout(verticalLayout_10);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_10 = new QHBoxLayout(tab_2);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy5);
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_5 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_11->addWidget(label_3);

        RTCYear = new SpinBox(groupBox_4);
        RTCYear->setObjectName(QStringLiteral("RTCYear"));

        horizontalLayout_11->addWidget(RTCYear);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_11->addWidget(label_4);

        RTCMonth = new SpinBox(groupBox_4);
        RTCMonth->setObjectName(QStringLiteral("RTCMonth"));

        horizontalLayout_11->addWidget(RTCMonth);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_11->addWidget(label_5);

        RTCDay = new SpinBox(groupBox_4);
        RTCDay->setObjectName(QStringLiteral("RTCDay"));

        horizontalLayout_11->addWidget(RTCDay);

        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_4);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_11->addWidget(label_6);

        RTCHour = new SpinBox(groupBox_4);
        RTCHour->setObjectName(QStringLiteral("RTCHour"));

        horizontalLayout_11->addWidget(RTCHour);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_11->addWidget(label_7);

        RTCMinute = new SpinBox(groupBox_4);
        RTCMinute->setObjectName(QStringLiteral("RTCMinute"));

        horizontalLayout_11->addWidget(RTCMinute);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_11->addWidget(label_8);

        RTCSecond = new SpinBox(groupBox_4);
        RTCSecond->setObjectName(QStringLiteral("RTCSecond"));

        horizontalLayout_11->addWidget(RTCSecond);

        horizontalSpacer_3 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);

        horizontalSpacer_6 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_6);


        verticalLayout_6->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_19 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_19);

        horizontalSpacer_20 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_20);

        horizontalSpacer_16 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_16);

        horizontalSpacer_15 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_15);

        horizontalSpacer_11 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_11);

        horizontalSpacer_12 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_12);

        getTime = new QPushButton(groupBox_4);
        getTime->setObjectName(QStringLiteral("getTime"));

        horizontalLayout_12->addWidget(getTime);

        horizontalSpacer_10 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_10);

        horizontalSpacer_9 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_9);

        horizontalSpacer_23 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_23);

        horizontalSpacer_7 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_7);

        syncSysTime = new QPushButton(groupBox_4);
        syncSysTime->setObjectName(QStringLiteral("syncSysTime"));

        horizontalLayout_12->addWidget(syncSysTime);

        horizontalSpacer_8 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_8);

        sendTime = new QPushButton(groupBox_4);
        sendTime->setObjectName(QStringLiteral("sendTime"));

        horizontalLayout_12->addWidget(sendTime);

        horizontalSpacer_13 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_13);

        horizontalSpacer_14 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_14);

        horizontalSpacer_22 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_22);

        horizontalSpacer_21 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_21);

        horizontalSpacer_17 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_17);

        horizontalSpacer_18 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_18);


        verticalLayout_6->addLayout(horizontalLayout_12);


        verticalLayout_4->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy6);
        verticalLayout_7 = new QVBoxLayout(groupBox_5);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_7->addWidget(label_12);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalSpacer_40 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_40);

        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_15->addWidget(label_10);

        fileNameSD = new QLineEdit(groupBox_5);
        fileNameSD->setObjectName(QStringLiteral("fileNameSD"));

        horizontalLayout_15->addWidget(fileNameSD);

        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_15->addWidget(label_11);


        verticalLayout_7->addLayout(horizontalLayout_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_41 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_41);

        logToFileSD = new QCheckBox(groupBox_5);
        logToFileSD->setObjectName(QStringLiteral("logToFileSD"));

        horizontalLayout_14->addWidget(logToFileSD);

        appendDateSD = new QCheckBox(groupBox_5);
        appendDateSD->setObjectName(QStringLiteral("appendDateSD"));

        horizontalLayout_14->addWidget(appendDateSD);


        verticalLayout_7->addLayout(horizontalLayout_14);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_5);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_7->addWidget(label_13);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_42 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_42);

        logBluetooth = new QCheckBox(groupBox_5);
        logBluetooth->setObjectName(QStringLiteral("logBluetooth"));

        horizontalLayout_19->addWidget(logBluetooth);

        logUSB = new QCheckBox(groupBox_5);
        logUSB->setObjectName(QStringLiteral("logUSB"));

        horizontalLayout_19->addWidget(logUSB);


        verticalLayout_7->addLayout(horizontalLayout_19);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_39 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_39);

        applyLog = new QPushButton(groupBox_5);
        applyLog->setObjectName(QStringLiteral("applyLog"));

        horizontalLayout_17->addWidget(applyLog);


        verticalLayout_7->addLayout(horizontalLayout_17);


        verticalLayout_4->addWidget(groupBox_5);

        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_10->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, -1, 0, -1);
        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_24);


        horizontalLayout_10->addLayout(verticalLayout_5);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_2->addWidget(tabWidget);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Serial Port", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", 0));
        actionDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0));
        actionConfigure->setText(QApplication::translate("MainWindow", "Configure Port", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Log File", 0));
        label_9->setText(QApplication::translate("MainWindow", ".txt", 0));
        logToFile->setText(QApplication::translate("MainWindow", "Log to file", 0));
        appendDate->setText(QApplication::translate("MainWindow", "Append date to filename", 0));
        viewLog->setText(QApplication::translate("MainWindow", "View a log", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Send command", 0));
        cmdFreq->setText(QApplication::translate("MainWindow", "FREQUENCY", 0));
        cmdBurst->setText(QApplication::translate("MainWindow", "BURST", 0));
        cmdStream->setText(QApplication::translate("MainWindow", "STREAM", 0));
        label_2->setText(QApplication::translate("MainWindow", "Command value:", 0));
        label->setText(QApplication::translate("MainWindow", "Custom command: ", 0));
        cmdCustomSend->setText(QApplication::translate("MainWindow", "Send", 0));
        logUpdate->setText(QApplication::translate("MainWindow", "Fetch frames", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Accelerometer", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Gyroscope", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Configure RTC", 0));
        label_3->setText(QApplication::translate("MainWindow", "Year", 0));
        label_4->setText(QApplication::translate("MainWindow", "Month", 0));
        label_5->setText(QApplication::translate("MainWindow", "Day", 0));
        label_6->setText(QApplication::translate("MainWindow", "Time", 0));
        label_7->setText(QApplication::translate("MainWindow", ":", 0));
        label_8->setText(QApplication::translate("MainWindow", ":", 0));
        getTime->setText(QApplication::translate("MainWindow", "Get RTC time", 0));
        syncSysTime->setText(QApplication::translate("MainWindow", "Sync RTC to System time", 0));
        sendTime->setText(QApplication::translate("MainWindow", "Send custom time", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Log options", 0));
        label_12->setText(QApplication::translate("MainWindow", "SD Options", 0));
        label_10->setText(QApplication::translate("MainWindow", "SD log filename", 0));
        label_11->setText(QApplication::translate("MainWindow", ".txt", 0));
        logToFileSD->setText(QApplication::translate("MainWindow", "Log to SD", 0));
        appendDateSD->setText(QApplication::translate("MainWindow", "Append date to filename", 0));
        label_13->setText(QApplication::translate("MainWindow", "Communication options", 0));
        logBluetooth->setText(QApplication::translate("MainWindow", "Log through Bluetooth", 0));
        logUSB->setText(QApplication::translate("MainWindow", "Log through USB", 0));
        applyLog->setText(QApplication::translate("MainWindow", "Apply settings", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Control Panel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
