    QT       += widgets serialport
    QT       += multimedia
    QT       += printsupport

SOURCES += \
    main.cpp \
    protocole.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    settingsdialog.cpp \
    fileviewer.cpp \
    qzoomplot.cpp

HEADERS += \
    protocole.h \
    mainwindow.h \
    qcustomplot.h \
    settingsdialog.h \
    spinbox.h \
    fileviewer.h \
    qzoomplot.h

FORMS += \
    settingsdialog.ui \
    mainwindow.ui \
    fileviewer.ui

RESOURCES += \
    resources.qrc
