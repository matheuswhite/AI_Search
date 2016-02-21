#pragma once

#include <minimaxstate.h>
#include <TicTacToe/tictactoeid.h>

class TicTacToeState : public MiniMaxState<TicTacToeId*>
{
    TicTacToePiece _myPiece;
public:
    TicTacToeState(TicTacToePiece myPiece, TicTacToeId* id, int depth);
    virtual ~TicTacToeState();

    TicTacToePiece getMyPiece() const;

    std::vector<MiniMaxState<TicTacToeId*>*> genSuccessors();

    std::string toString();
    bool isFinal();
    int genUtility();
};
