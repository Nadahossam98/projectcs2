QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = save-the-doctor

SOURCES += \
    book.cpp \
    bookscore.cpp \
    bookspack.cpp \
    bullet.cpp \
    checkpoint.cpp \
    coin.cpp \
    coinscore.cpp \
    coinspack.cpp \
    enemy1.cpp \
    fakebook.cpp \
    game.cpp \
    gamecompletedwindow.cpp \
    gameoverwindow.cpp \
    health.cpp \
    level1.cpp \
    level2.cpp \
    level3.cpp \
    level4.cpp \
    level5.cpp \
    levelclass.cpp \
    levelcompletedwindow.cpp \
    main.cpp \
    platform.cpp \
    player.cpp \
    spikes.cpp

HEADERS += \
    book.h \
    bookscore.h \
    bookspack.h \
    bullet.h \
    checkpoint.h \
    coin.h \
    coinscore.h \
    coinspack.h \
    enemy1.h \
    fakebook.h \
    game.h \
    gamecompletedwindow.h \
    gameoverwindow.h \
    health.h \
    level1.h \
    level2.h \
    level3.h \
    level4.h \
    level5.h \
    levelclass.h \
    levelcompletedwindow.h \
    platform.h \
    player.h \
    spikes.h

FORMS += \
    gamecompletedwindow.ui \
    gameoverwindow.ui \
    levelcompletedwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ImgsResources.qrc \
    mario.qrc
