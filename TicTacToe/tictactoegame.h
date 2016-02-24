#pragma once

#include <TicTacToe/tictactoestate.h>
#include <minimax.h>

class TicTacToeGame
{
    MiniMaxState<TicTacToeId*>* _currentState;
    MiniMax<TicTacToeId*>* _minimax;
    TicTacToePiece _playerPiece;
    TicTacToePiece _aiPiece;
    TicTacToePiece** _board;

    void initializeBoard();
public:
    TicTacToeGame(TicTacToePiece playerPiece);
    virtual ~TicTacToeGame();

    void resetGame();
    bool isMoveAllow(int row, int col);
    void playerMove(int row, int col);
    void aiMove();
    std::string getCurrentBoardState();

    MiniMaxState<TicTacToeId*>* getCurrentState() const;
};
