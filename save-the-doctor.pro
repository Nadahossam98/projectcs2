QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = save-the-doctor

SOURCES += \
    book.cpp \
    bookscore.cpp \
    bookspack.cpp \
    checkpoint.cpp \
    coin.cpp \
    coinscore.cpp \
    coinspack.cpp \
    enemy1.cpp \
    fakebook.cpp \
    game.cpp \
    gameoverwindow.cpp \
    health.cpp \
    level1.cpp \
    levelclass.cpp \
    main.cpp \
    platform.cpp \
    player.cpp \
    spikes.cpp

HEADERS += \
    book.h \
    bookscore.h \
    bookspack.h \
    checkpoint.h \
    coin.h \
    coinscore.h \
    coinspack.h \
    enemy1.h \
    fakebook.h \
    game.h \
    gameoverwindow.h \
    health.h \
    level1.h \
    levelclass.h \
    platform.h \
    player.h \
    spikes.h

FORMS += \
    gameoverwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ImgsResources.qrc \
    mario.qrc
