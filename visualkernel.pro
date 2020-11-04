QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    image.cpp \
    main.cpp \
    mainwindow.cpp \
    vars.cpp

HEADERS += \
    image.h \
    mainwindow.h \
    vars.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../opencv/build/x64/vc15/lib/ -lopencv_world450
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../opencv/build/x64/vc15/lib/ -lopencv_world450d
else:unix: LIBS += -L$$PWD/../../../../../../opencv/build/x64/vc15/lib/ -lopencv_world450

INCLUDEPATH += $$PWD/../../../../../../opencv/build/include
DEPENDPATH += $$PWD/../../../../../../opencv/build/include
