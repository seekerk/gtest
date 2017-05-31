include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     tst_test1.h \
    ../myfunc.h

SOURCES +=     main.cpp \
    ../myfunc.c
