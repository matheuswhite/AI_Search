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
    EightPuzzle/eightpuzzleoperator.cpp \
    PriestNCannibal/priestncannibalid.cpp \
    PriestNCannibal/priestncannibalstate.cpp \
    PriestNCannibal/priestncannibaloperator.cpp

HEADERS += \
    EightPuzzle/eightpuzzlestate.h \
    state.h \
    operator.h \
    EightPuzzle/eightpuzzleoperator.h \
    solver.h \
    object.h \
    frontier.h \
    bfs.h \
    astar.h \
    dfs.h \
    iterativedfs.h \
    PriestNCannibal/priestncannibalid.h \
    PriestNCannibal/priestncannibalstate.h \
    PriestNCannibal/priestncannibaloperator.h
