QT += core widgets network
QT -= gui

CONFIG += c++11 console
#macx:CONFIG -= app_bundle

# Mac OS X : pour cout, cerr ...
macx {
        QMAKE_CFLAGS_X86_64 += -mmacosx-version-min=10.7
        QMAKE_CXXFLAGS_X86_64 = $$QMAKE_CFLAGS_X86_64
}

unix:!macx {
        #QMAKE_LFLAGS += '-Wl,-rpath,\'\$$ORIGIN/libs\''
        QMAKE_LFLAGS += '-Wl,-rpath,\'\./libs/libQt\''
}


MOC_DIR		 = .moc
OBJECTS_DIR	 = .obj

QAMSOCKETS	 = ./libs/QamSockets
QAMMODBUSMAP = ./libs/QamModbusMap

INCLUDEPATH +=	. $${QAMSOCKETS} $${QAMMODBUSMAP}



# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    $${QAMMODBUSMAP}/qammodbusdata.cpp \
    $${QAMMODBUSMAP}/qammodbusmap.cpp \
    $${QAMMODBUSMAP}/qammodbusmapviewer.cpp \
    $${QAMSOCKETS}/qamtcpclient.cpp \
    $${QAMSOCKETS}/qamtcpconnection.cpp \
    $${QAMSOCKETS}/qamabstractserver.cpp \
    kartbtclient.cpp \
    main.cpp

HEADERS += kartbtclient.h\
    $${QAMMODBUSMAP}/qammodbusdata.h \
    $${QAMMODBUSMAP}/qammodbusmap.h \
    $${QAMMODBUSMAP}/qammodbusmapviewer.h \
    $${QAMSOCKETS}/qamtcpclient.h \
    $${QAMSOCKETS}/qamtcpconnection.h \ \
    $${QAMSOCKETS}/qamabstractserver.h \



TEMPLATE = app
DESTDIR = release
TARGET = kart2019

DISTFILES += \
    ./libs/QamModbusMap/qammodbusmap.pri \
    ./libs/QamSockets/qamsockets.pri \
