/********************************************************************************
** Form generated from reading UI file 'fileviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEVIEWER_H
#define UI_FILEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qzoomplot.h"

QT_BEGIN_NAMESPACE

class Ui_FileViewer
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QZoomPlot *Accel_X_Y;
    QZoomPlot *Accel_Z;
    QVBoxLayout *verticalLayout;
    QZoomPlot *Accel_XY;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QZoomPlot *Gyro_X;
    QZoomPlot *Gyro_Y;
    QVBoxLayout *verticalLayout_6;
    QZoomPlot *Gyro_Z;
    QWidget *widget_12;
    QWidget *tab_2;
    QWidget *tab_4;
    QGridLayout *gridLayout_2;
    QListWidget *logFrame;

    void setupUi(QWidget *FileViewer)
    {
        if (FileViewer->objectName().isEmpty())
            FileViewer->setObjectName(QStringLiteral("FileViewer"));
        FileViewer->resize(949, 657);
        gridLayout = new QGridLayout(FileViewer);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(FileViewer);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(-1, -1, 10, -1);
        Accel_X_Y = new QZoomPlot(tab);
        Accel_X_Y->setObjectName(QStringLiteral("Accel_X_Y"));

        verticalLayout_2->addWidget(Accel_X_Y);

        Accel_Z = new QZoomPlot(tab);
        Accel_Z->setObjectName(QStringLiteral("Accel_Z"));

        verticalLayout_2->addWidget(Accel_Z);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Accel_XY = new QZoomPlot(tab);
        Accel_XY->setObjectName(QStringLiteral("Accel_XY"));

        verticalLayout->addWidget(Accel_XY);


        horizontalLayout->addLayout(verticalLayout);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        horizontalLayout_2 = new QHBoxLayout(tab_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        Gyro_X = new QZoomPlot(tab_3);
        Gyro_X->setObjectName(QStringLiteral("Gyro_X"));

        verticalLayout_5->addWidget(Gyro_X);

        Gyro_Y = new QZoomPlot(tab_3);
        Gyro_Y->setObjectName(QStringLiteral("Gyro_Y"));

        verticalLayout_5->addWidget(Gyro_Y);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        Gyro_Z = new QZoomPlot(tab_3);
        Gyro_Z->setObjectName(QStringLiteral("Gyro_Z"));

        verticalLayout_6->addWidget(Gyro_Z);

        widget_12 = new QWidget(tab_3);
        widget_12->setObjectName(QStringLiteral("widget_12"));

        verticalLayout_6->addWidget(widget_12);


        horizontalLayout_2->addLayout(verticalLayout_6);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_2 = new QGridLayout(tab_4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        logFrame = new QListWidget(tab_4);
        logFrame->setObjectName(QStringLiteral("logFrame"));

        gridLayout_2->addWidget(logFrame, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(FileViewer);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(FileViewer);
    } // setupUi

    void retranslateUi(QWidget *FileViewer)
    {
        FileViewer->setWindowTitle(QApplication::translate("FileViewer", "Form", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FileViewer", "Accelerometer", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("FileViewer", "Gyroscope", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("FileViewer", "Other values", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("FileViewer", "Frame Log", 0));
    } // retranslateUi

};

namespace Ui {
    class FileViewer: public Ui_FileViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEVIEWER_H
