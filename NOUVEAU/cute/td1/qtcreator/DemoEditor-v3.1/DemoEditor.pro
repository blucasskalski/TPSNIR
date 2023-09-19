QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

HEADERS		= dlgsearch.h \
    mainwindow.h \
    search.h \
    search_copy.h

SOURCES		= main.cpp mainwindow.cpp mainactions.cpp mainfiles.cpp maineditor.cpp dlgsearch.cpp \
    search.cpp

FORMS		= mainwindow.ui dlgsearch.ui \
    search.ui

RESOURCES	= DemoEditor.qrc

RC_FILE		= winres.rc

UI_DIR		= .uic
RCC_DIR		= .uic
MOC_DIR		= .moc
OBJECTS_DIR	= .obj

TEMPLATE	= app
CONFIG 	   += qt warn_on release
TARGET		= DemoEditor

macx:ICON = images/qam47.icns
