#include "tictactoestate.h"

TicTacToeState::TicTacToeState(TicTacToePiece myPiece, TicTacToeId* id, int depth)
    : MiniMaxState<TicTacToeId*>(id, depth), _myPiece(myPiece)
{
}

TicTacToeState::~TicTacToeState()
{
    int size = _successors.size();
    for (int i = 0; i < size; ++i) {
        MiniMaxState<TicTacToeId*>* s = _successors[i];
        delete s;
    }
    _successors.clear();
}

TicTacToePiece TicTacToeState::getMyPiece() const
{
    return _myPiece;
}

void TicTacToeState::genSuccessors()
{
    TicTacToeId* tempId = nullptr;
    TicTacToePiece nextTurnPiece = (getId()->getCurrentTurnPiece() == TIC_TAC_TOE_PIECE::X ? TIC_TAC_TOE_PIECE::O : TIC_TAC_TOE_PIECE::X);

    for (int j = 0; j < 3; ++j)
    {
        for (int k = 0; k < 3; ++k)
        {
            if(getId()->getPiece(j, k) == TIC_TAC_TOE_PIECE::NONE)
            {
                tempId = new TicTacToeId(getId()->setPiece(j, k, getId()->getCurrentTurnPiece()), nextTurnPiece);
                _successors.push_back(new TicTacToeState(_myPiece, tempId, getDepth() + 1));
            }
        }
    }
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
    int xRow[3] = {0}, xCol[3] = {0}, xDia1 = 0, xDia2 = 0;
    int oRow[3] = {0}, oCol[3] = {0}, oDia1 = 0, oDia2 = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (id->getPiece(i, j) == TIC_TAC_TOE_PIECE::X)
            {
                xRow[i] += 1;
                xCol[j] += 1;
                if (i == 1 && j == 1)
                {
                    xDia1 += 1;
                    xDia2 += 1;
                }
                if ((i == 0 && j == 0) || (i == 2 && j == 2))
                {
                    xDia1 += 1;
                }
                if ((i == 0 && j == 2) || (i == 2 && j == 0))
                {
                    xDia2 += 1;
                }
            }
            else if (id->getPiece(i, j) == TIC_TAC_TOE_PIECE::O)
            {
                oRow[i] += 1;
                oCol[j] += 1;
                if (i == 1 && j == 1)
                {
                    oDia1 += 1;
                    oDia2 += 1;
                }
                if ((i == 0 && j == 0) || (i == 2 && j == 2))
                {
                    oDia1 += 1;
                }
                if ((i == 0 && j == 2) || (i == 2 && j == 0))
                {
                    oDia2 += 1;
                }
            }
        }
    }

    out = (_myPiece == TIC_TAC_TOE_PIECE::X ? xRow[0] + xRow[1] + xRow[2] + xCol[0] + xCol[1] + xCol[2] + xDia1 + xDia2 : oRow[0] + oRow[1] + oRow[2] + oCol[0] + oCol[1] + oCol[2] + oDia1 + oDia2);

    setUtility(out);

    return out;
}
