QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    InfoLugarDialog.cpp \
    buscarlugar.cpp \
    lugarbloque.cpp \
    main.cpp \
    mainwindow.cpp \
    mapa.cpp \
    menuprincipal.cpp

HEADERS += \
    Bloque.h \
    Grafo.h \
    InfoLugarDialog.h \
    ListaSimple.h \
    buscarlugar.h \
    lugarbloque.h \
    mainwindow.h \
    mapa.h \
    menuprincipal.h

FORMS += \
    InfoLugarDialog.ui \
    buscarlugar.ui \
    lugarbloque.ui \
    mainwindow.ui \
    menuprincipal.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitattributes \
    .gitignore

RESOURCES += \
    resources.qrc \
    resources.qrc
