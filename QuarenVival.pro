TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        QuarenvivalFunctions.cpp \
        QuarenvivalTextureManager.cpp \
        main.cpp

win32: LIBS += -L$$PWD/SDL2-2.0.12/i686-w64-mingw32/lib/ -lSDL2

INCLUDEPATH += $$PWD/SDL2-2.0.12/i686-w64-mingw32/include
DEPENDPATH += $$PWD/SDL2-2.0.12/i686-w64-mingw32/include

HEADERS += \
    QuarenvivalFunctions.h \
    QuarenvivalTextureManager.h \
    quarenvivalIncludes.h \
    quarenvivalStructures.h

DISTFILES += \
    assets/charSprite.bmp \
    assets/placeholder.bmp

win32: LIBS += -L$$PWD/SDL2_ttf-2.0.15/i686-w64-mingw32/lib/ -lSDL2_ttf

INCLUDEPATH += $$PWD/SDL2_ttf-2.0.15/i686-w64-mingw32/include
DEPENDPATH += $$PWD/SDL2_ttf-2.0.15/i686-w64-mingw32/include
