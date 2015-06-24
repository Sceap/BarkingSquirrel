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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
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
    QSpacerItem *horizontalSpacer_28;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *cmdStart;
    QPushButton *cmdStop;
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
    QTextEdit *logConsole;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *graphXAxis;
    QCustomPlot *graphYAxis;
    QCustomPlot *graphXY;
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
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *horizontalSpacer_24;
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
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
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
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        fileName = new QLineEdit(groupBox_2);
        fileName->setObjectName(QStringLiteral("fileName"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fileName->sizePolicy().hasHeightForWidth());
        fileName->setSizePolicy(sizePolicy1);

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

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addWidget(groupBox_2);

        horizontalSpacer_28 = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_28);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(groupBox_3);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        cmdStart = new QPushButton(groupBox_3);
        cmdStart->setObjectName(QStringLiteral("cmdStart"));

        horizontalLayout_6->addWidget(cmdStart);

        cmdStop = new QPushButton(groupBox_3);
        cmdStop->setObjectName(QStringLiteral("cmdStop"));

        horizontalLayout_6->addWidget(cmdStop);

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
        logConsole = new QTextEdit(centralwidget);
        logConsole->setObjectName(QStringLiteral("logConsole"));
        logConsole->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(logConsole->sizePolicy().hasHeightForWidth());
        logConsole->setSizePolicy(sizePolicy2);
        logConsole->setMaximumSize(QSize(200, 16777215));
        logConsole->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: #FFFFFF;\n"
"}"));

        horizontalLayout_2->addWidget(logConsole);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Rounded);
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


        horizontalLayout_9->addLayout(verticalLayout_3);

        graphXY = new QCustomPlot(tab);
        graphXY->setObjectName(QStringLiteral("graphXY"));

        horizontalLayout_9->addWidget(graphXY);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_10 = new QHBoxLayout(tab_2);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy3);
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


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


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
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Send command", 0));
        cmdStart->setText(QApplication::translate("MainWindow", "START", 0));
        cmdStop->setText(QApplication::translate("MainWindow", "STOP", 0));
        cmdBurst->setText(QApplication::translate("MainWindow", "BURST", 0));
        cmdStream->setText(QApplication::translate("MainWindow", "STREAM", 0));
        label_2->setText(QApplication::translate("MainWindow", "Command value:", 0));
        label->setText(QApplication::translate("MainWindow", "Custom command: ", 0));
        cmdCustomSend->setText(QApplication::translate("MainWindow", "Send", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Accelerometer", 0));
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
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Advanced Commands", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
