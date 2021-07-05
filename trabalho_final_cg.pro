QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canvas.cpp \
    cena/cena.cpp \
    cenario/piso.cpp \
    objetos/inimigo.cpp \
    objetos/personagem.cpp \
    main.cpp \
    mainwindow.cpp \
    objetos/quadrado.cpp

HEADERS += \
    canvas.h \
    cena/cena.h \
    cenario/piso.h \
    objetos/inimigo.h \
    objetos/personagem.h \
    mainwindow.h \
    objetos/quadrado.h

FORMS += \
    mainwindow.ui

LIBS = -lGLU

INCLUDEPATH += glm

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
