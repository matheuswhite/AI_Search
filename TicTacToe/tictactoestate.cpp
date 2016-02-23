#include "tictactoestate.h"

TicTacToeState::TicTacToeState(TicTacToePiece myPiece, TicTacToeId* id, int depth)
    : MiniMaxState<TicTacToeId*>(id, depth), _myPiece(myPiece)
{
}

TicTacToeState::~TicTacToeState()
{
}

TicTacToePiece TicTacToeState::getMyPiece() const
{
    return _myPiece;
}

std::vector<MiniMaxState<TicTacToeId*>*> TicTacToeState::genSuccessors()
{
    std::vector<MiniMaxState<TicTacToeId*>*> successors;
    TicTacToeId* tempId = nullptr;
    TicTacToePiece nextTurnPiece = (getId()->getCurrentTurnPiece() == TIC_TAC_TOE_PIECE::X ? TIC_TAC_TOE_PIECE::O : TIC_TAC_TOE_PIECE::X);

    for (int j = 0; j < 3; ++j)
    {
        for (int k = 0; k < 3; ++k)
        {
            if(getId()->getPiece(j, k) == TIC_TAC_TOE_PIECE::NONE)
            {
                tempId = new TicTacToeId(getId()->setPiece(j, k, getId()->getCurrentTurnPiece()), nextTurnPiece);
                successors.push_back(new TicTacToeState(_myPiece, tempId, getDepth() + 1));
            }
        }
    }

    return successors;
}

std::string TicTacToeState::toString()
{
    return getId()->toString();
}

bool TicTacToeState::isFinal()
{
    return (getId()->isO_Winner() || getId()->isX_Winner() || getId()->isFull());
}

int TicTacToeState::genUtility()
{
    TicTacToeId* id = getId();
    int out = 0;

    if (_myPiece == TIC_TAC_TOE_PIECE::X)
    {
        if (id->isX_Winner()) out = 1;
        else if (id->isO_Winner()) out = -1;
    }
    else if (_myPiece == TIC_TAC_TOE_PIECE::O)
    {
        if (id->isO_Winner()) out = 1;
        else if (id->isX_Winner()) out = -1;
    }

    return out;
}
