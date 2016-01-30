#-------------------------------------------------
#
# Project created by QtCreator 2016-01-22T09:52:25
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = AI_SearchFramework
CONFIG   += console \
    c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    eightpuzzlestate.cpp \
    state.cpp \
    frontier.cpp \
    eightpuzzleid.cpp \
    eightpuzzleoperator.cpp \
    solver.cpp

HEADERS += \
    eightpuzzlestate.h \
    state.h \
    frontier.h \
    id.h \
    operator.h \
    eightpuzzleid.h \
    eightpuzzleoperator.h \
    solver.h
