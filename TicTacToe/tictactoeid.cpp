#include "tictactoeid.h"

TicTacToeId::TicTacToeId(TicTacToePiece** board, TicTacToePiece currentTurnPiece)
    : _board(board), _currentTurnPiece(currentTurnPiece)
{
}

TicTacToeId::~TicTacToeId()
{
}

std::string TicTacToeId::getPieceName(TicTacToePiece piece)
{
    std::string out = "";

    switch (piece) {
    case TIC_TAC_TOE_PIECE::NONE:
        out = " ";
        break;
    case TIC_TAC_TOE_PIECE::X:
        out = "X";
        break;
    case TIC_TAC_TOE_PIECE::O:
        out = "O";
        break;
    default:
        break;
    }

    return out;
}

TicTacToePiece TicTacToeId::getCurrentTurnPiece() const
{
    return _currentTurnPiece;
}

TicTacToePiece TicTacToeId::getPiece(int row, int col)
{
    if (row < 3 && row >= 0 && col < 3 && col >= 0)
        return _board[row][col];
}

TicTacToePiece** TicTacToeId::setPiece(int row, int col, TicTacToePiece piece)
{
    TicTacToePiece** board = new TicTacToePiece*[3];
    for (int i = 0; i < 3; ++i) {
        board[i] = new TicTacToePiece[3];
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == row && j == col && board[i][j] == TIC_TAC_TOE_PIECE::NONE)
                board[i][j] = piece;
            else
                board[i][j] = _board[i][j];
        }
    }
    return board;
}

std::string TicTacToeId::toString()
{
    std::string out = "";

    for (int i = 0; i < 3; ++i)
    {
        out += "|";
        for (int j = 0; j < 3; ++j)
        {
            out += getPieceName(_board[i][j]) + "|";
        }
        out += "\n";
    }
    out += "\n";
    return out;
}

bool TicTacToeId::equal(Object* other)
{
    TicTacToeId* id = dynamic_cast<TicTacToeId*>(other);
    if (id != nullptr)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (_board[i][j] != id->getPiece(i,j))
                    return false;
            }
        }
        return true;
    }
    return false;
}

bool TicTacToeId::isX_Winner()
{
    short xRow[3], xCol[3], xDia1, xDia2;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (_board[i][j] == TIC_TAC_TOE_PIECE::X)
            {
                xRow[i] += 1;
                xCol[j] += 1;
                if (i == 2 && j == 2)
                {
                    xDia1 += 1;
                    xDia2 += 1;
                }
                if ((i == 0 && j == 0) || (i == 2 && j == 2)) xDia1 += 1;
                if ((i == 0 && j == 2) || (i == 2 && j == 0)) xDia2 += 1;
            }
        }
    }

    bool out = (xRow[0] == 3) || (xRow[1] == 3) || (xRow[2] == 3)
            || (xCol[0] == 3) || (xCol[1] == 3) || (xCol[2] == 3)
            || (xDia1 == 3) || (xDia2 == 3);
    return out;
}

bool TicTacToeId::isO_Winner()
{
    short oRow[3], oCol[3], oDia1, oDia2;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (_board[i][j] == TIC_TAC_TOE_PIECE::O)
            {
                oRow[i] += 1;
                oCol[j] += 1;
                if (i == 2 && j == 2)
                {
                    oDia1 += 1;
                    oDia2 += 1;
                }
                if ((i == 0 && j == 0) || (i == 2 && j == 2)) oDia1 += 1;
                if ((i == 0 && j == 2) || (i == 2 && j == 0)) oDia2 += 1;
            }
        }
    }

    bool out = (oRow[0] == 3) || (oRow[1] == 3) || (oRow[2] == 3)
            || (oCol[0] == 3) || (oCol[1] == 3) || (oCol[2] == 3)
            || (oDia1 == 3) || (oDia2 == 3);
    return out;
}

bool TicTacToeId::isFull()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (_board[i][j] == TIC_TAC_TOE_PIECE::NONE)
            {
                return false;
            }
        }
    }
    return true;
}

bool TicTacToeId::operator ==(TicTacToeId* other)
{
    return equal(other);
}
