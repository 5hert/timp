QT += testlib widgets
TARGET = tests

TEMPLATE = app

CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += test_task1.cpp \
           ../Client/task1.cpp

INCLUDEPATH += ../Client \
               C:\WorkFolder\Client\build\Desktop_Qt_6_8_2_MinGW_64_bit-Debug

HEADERS += ../Client/task1.h

FORMS += ../Client/task1.ui
