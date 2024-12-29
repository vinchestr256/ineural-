QT -= gui qt

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += \
        NerualNetwork/IGenetic.cpp \
        NerualNetwork/ILayerNeurons.cpp \
        NerualNetwork/INerualNetwork.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    NerualNetwork/IGenetic.h \
    NerualNetwork/ILayerNeurons.h \
    NerualNetwork/INerualNetwork.h
