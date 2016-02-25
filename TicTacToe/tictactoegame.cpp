#include "tictactoegame.h"

TicTacToeGame::TicTacToeGame(TicTacToePiece playerPiece) : _playerPiece(playerPiece)
{
    _aiPiece = (playerPiece == TIC_TAC_TOE_PIECE::X) ? TIC_TAC_TOE_PIECE::O : TIC_TAC_TOE_PIECE::X;

    initializeBoard();
    resetGame();
}

TicTacToeGame::~TicTacToeGame()
{
}

bool TicTacToeGame::isMoveAllow(int row, int col)
{
    return _currentState->getId()->getPiece(row, col) == TIC_TAC_TOE_PIECE::NONE;
}

void TicTacToeGame::playerMove(int row, int col)
{
    _currentState = new TicTacToeState(_aiPiece, new TicTacToeId(_currentState->getId()->setPiece(row, col, _playerPiece), _aiPiece),
                                       _currentState->getDepth());
}

void TicTacToeGame::aiMove()
{
    _currentState = _minimax->getNextMovment(_currentState);
}

void TicTacToeGame::initializeBoard()
{
    _board = new TicTacToePiece*[3];
    for (int i = 0; i < 3; ++i) {
        _board[i] = new TicTacToePiece[3];
    }
}

void TicTacToeGame::resetGame()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            _board[i][j] = TIC_TAC_TOE_PIECE::NONE;
        }
    }

    this->_currentState = new TicTacToeState(_aiPiece, new TicTacToeId(_board, TIC_TAC_TOE_PIECE::X), 0);
    this->_minimax = new MiniMax<TicTacToeId*>(-1);
}

std::string TicTacToeGame::getCurrentBoardState()
{
    return _currentState->getId()->toString();
}

MiniMaxState<TicTacToeId*>* TicTacToeGame::getCurrentState() const
{
    return _currentState;
}
