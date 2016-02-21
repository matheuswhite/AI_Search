#pragma once

#include <object.h>

typedef short TicTacToePiece;

enum TIC_TAC_TOE_PIECE
{
    NONE = 0,
    X,
    O
};

class TicTacToeId : Object
{
    TicTacToePiece** _board;
    TicTacToePiece _currentTurnPiece;
public:
    TicTacToeId(TicTacToePiece** board, TicTacToePiece currentTurnPiece);
    ~TicTacToeId();

    std::string toString();
    bool equal(Object* other);

    static std::string getPieceName(TicTacToePiece piece);

    TicTacToePiece getCurrentTurnPiece() const;
    TicTacToePiece getPiece(int row, int col);
    TicTacToePiece** setPiece(int row, int col, TicTacToePiece piece);
    bool isX_Winner();
    bool isO_Winner();
    bool isFull();

    bool operator ==(TicTacToeId* other);
};
