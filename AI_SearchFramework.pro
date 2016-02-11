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
    EightPuzzle/eightpuzzlestate.cpp \
    state.cpp \
    frontier.cpp \
    EightPuzzle/eightpuzzleid.cpp \
    EightPuzzle/eightpuzzleoperator.cpp \
    solver.cpp \
    object.cpp \
    ParisSubway/parissubwaystate.cpp

HEADERS += \
    EightPuzzle/eightpuzzlestate.h \
    state.h \
    frontier.h \
    id.h \
    operator.h \
    EightPuzzle/eightpuzzleid.h \
    EightPuzzle/eightpuzzleoperator.h \
    solver.h \
    searchalgorithms.h \
    object.h \
    ParisSubway/parissubwaystate.h
