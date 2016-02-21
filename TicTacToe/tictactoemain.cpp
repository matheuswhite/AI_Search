#include <minimax.h>
#include <TicTacToe/tictactoestate.h>

std::string showErrorMsg()
{
    return "Please, enter with a command valid!\n";
}

std::string showCommandsAllowed()
{
    return "Commands Allowed:\n$ [row] [col]\n$ exit\n$ reset\n";
}

MiniMaxState<TicTacToeId*>* runGameLogic(int row, int col, MiniMax<TicTacToeId*>* minimax, MiniMaxState<TicTacToeId*>* currentState, TicTacToePiece playerPiece, TicTacToePiece aiPiece)
{
    //player move
    TicTacToeId* id = new TicTacToeId(currentState->getId()->setPiece(row - 1, col - 1, playerPiece), aiPiece);
    currentState = new TicTacToeState(aiPiece, id, currentState->getDepth());

    std::cout << currentState->getId()->toString();

    //AI move
    std::cout << "Thinking..." << std::endl;
    currentState = minimax->getNextMovment(currentState);

    return currentState;
}

int main(int argc, char* argv[])
{
    bool exit = false;
    std::string input = "";
    MiniMaxState<TicTacToeId*>* currentState = nullptr;
    MiniMax<TicTacToeId*>* minimax;
    TicTacToePiece playerPiece = TIC_TAC_TOE_PIECE::X;
    TicTacToePiece aiPiece = TIC_TAC_TOE_PIECE::O;
    TicTacToePiece** board;

    board = new TicTacToePiece*[3];
    for (int i = 0; i < 3; ++i) {
        board[i] = new TicTacToePiece[3];
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = TIC_TAC_TOE_PIECE::NONE;
        }
    }

    minimax = new MiniMax<TicTacToeId*>(-1);
    currentState = new TicTacToeState(aiPiece, new TicTacToeId(board, TIC_TAC_TOE_PIECE::X), 0);

    std::cout << showCommandsAllowed() << std::endl;

    while (!exit)
    {
        std::cout << currentState->getId()->toString();

        std::cout << "$ ";
        std::getline(std::cin, input);

        if ((input.substr(0,1).compare("1") == 0 || input.substr(0,1).compare("2") == 0 || input.substr(0,1).compare("3") == 0)
                && (input.substr(2,1).compare("1") == 0 || input.substr(2,1).compare("2") == 0 || input.substr(2,1).compare("3") == 0))
        {
            const char* row = input.substr(0,1).c_str();
            const char* col = input.substr(2,1).c_str();

            currentState = runGameLogic(std::atoi(row), std::atoi(col), minimax, currentState, playerPiece, aiPiece);
        }
        else if (input.compare("exit") == 0)
            exit = true;
        else if (input.compare("reset") == 0)
        {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    board[i][j] = TIC_TAC_TOE_PIECE::NONE;
                }
            }

            minimax = new MiniMax<TicTacToeId*>(-1);
            currentState = new TicTacToeState(aiPiece, new TicTacToeId(board, TIC_TAC_TOE_PIECE::X), 0);
        }
        else
        {
            std::cout << showErrorMsg();
            std::cout << showCommandsAllowed();
        }

        if (currentState->getId()->isFull())
            exit = true;
    }
}
