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


SOURCES += \
    EightPuzzle/eightpuzzlestate.cpp \
    EightPuzzle/eightpuzzleoperator.cpp \
    SubwayParis/subwayparisstate.cpp \
    SubwayParis/subwayparisoperator.cpp \
    SubwayParis/subwayparisinfo.cpp \
    TicTacToe/tictactoestate.cpp \
    TicTacToe/tictactoeid.cpp \
    TicTacToe/tictactoemain.cpp \
    TicTacToe/tictactoegame.cpp \
    EightPuzzle/eightpuzzlemain.cpp \
    SubwayParis/subwayparismain.cpp

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
    SubwayParis/subwayparisstate.h \
    SubwayParis/subwayparisoperator.h \
    SubwayParis/subwayparisinfo.h \
    minimax.h \
    minimaxstate.h \
    TicTacToe/tictactoestate.h \
    TicTacToe/tictactoeid.h \
    TicTacToe/tictactoegame.h
