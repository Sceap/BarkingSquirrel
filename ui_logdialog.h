/********************************************************************************
** Form generated from reading UI file 'logdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGDIALOG_H
#define UI_LOGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_LogDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *selectBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *actionApply;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *fileName;
    QLabel *label;

    void setupUi(QDialog *LogDialog)
    {
        if (LogDialog->objectName().isEmpty())
            LogDialog->setObjectName(QStringLiteral("LogDialog"));
        LogDialog->resize(281, 128);
        gridLayout_3 = new QGridLayout(LogDialog);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        selectBox = new QGroupBox(LogDialog);
        selectBox->setObjectName(QStringLiteral("selectBox"));
        gridLayout = new QGridLayout(selectBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        actionApply = new QPushButton(selectBox);
        actionApply->setObjectName(QStringLiteral("actionApply"));

        horizontalLayout_2->addWidget(actionApply);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox = new QCheckBox(selectBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout->addWidget(checkBox);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        fileName = new QLineEdit(selectBox);
        fileName->setObjectName(QStringLiteral("fileName"));

        horizontalLayout_3->addWidget(fileName);

        label = new QLabel(selectBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        gridLayout_3->addWidget(selectBox, 0, 0, 1, 1);


        retranslateUi(LogDialog);

        QMetaObject::connectSlotsByName(LogDialog);
    } // setupUi

    void retranslateUi(QDialog *LogDialog)
    {
        LogDialog->setWindowTitle(QApplication::translate("LogDialog", "Log Settings", 0));
        selectBox->setTitle(QApplication::translate("LogDialog", "Choose log file name", 0));
        actionApply->setText(QApplication::translate("LogDialog", "Apply", 0));
        checkBox->setText(QApplication::translate("LogDialog", "Append Date to file name", 0));
        label->setText(QApplication::translate("LogDialog", ".txt", 0));
    } // retranslateUi

};

namespace Ui {
    class LogDialog: public Ui_LogDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGDIALOG_H
