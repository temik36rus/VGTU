QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    place_inf.cpp \
    tr_uch_inf.cpp \
    xxxaddcomp.cpp \
    xxxaddplace.cpp \
    xxxaddtrener.cpp \
    xxxadduch.cpp

HEADERS += \
    mainwindow.h \
    place_inf.h \
    tr_uch_inf.h \
    xxxaddcomp.h \
    xxxaddplace.h \
    xxxaddtrener.h \
    xxxadduch.h

FORMS += \
    mainwindow.ui \
    place_inf.ui \
    tr_uch_inf.ui \
    xxxaddcomp.ui \
    xxxaddplace.ui \
    xxxaddtrener.ui \
    xxxadduch.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
