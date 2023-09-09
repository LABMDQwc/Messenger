TEMPLATE = app

QT += widgets \
    network

TARGET = Messenger

SOURCES += \
    authorization.cpp \
    main.cpp \
    mainwindow.cpp \
    session.cpp

HEADERS += \
    authorization.hpp \
    mainwindow.hpp \
    session.hpp
