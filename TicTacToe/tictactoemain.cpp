#include <TicTacToe/tictactoegame.h>

void showErrorMsg()
{
    std::cout << "Please, enter with a command valid!\n";
}

void showCommandsAllowed()
{
    std::cout << "Commands Allowed:\n$ [row] [col]\n$ exit\n$ reset\n\n";
}

int main(int argc, char* argv[])
{
    bool exit = false;
    std::string input = "";
    TicTacToeGame* game = new TicTacToeGame(TIC_TAC_TOE_PIECE::X);

    showCommandsAllowed();

    while (!exit)
    {
        std::cout << game->getCurrentBoardState();

        std::cout << "$ ";
        std::getline(std::cin, input);

        if ((input.substr(0,1).compare("1") == 0 || input.substr(0,1).compare("2") == 0 || input.substr(0,1).compare("3") == 0)
                && (input.substr(2,1).compare("1") == 0 || input.substr(2,1).compare("2") == 0 || input.substr(2,1).compare("3") == 0))
        {
            int row = std::atoi(input.substr(0,1).c_str()) - 1;
            int col = std::atoi(input.substr(2,1).c_str()) - 1;

            if (game->isMoveAllow(row, col))
            {
                game->playerMove(row, col);
                game->aiMove();
            }
            else
            {
                showErrorMsg();
            }
        }
        else if (input.compare("exit") == 0)
            exit = true;
        else if (input.compare("reset") == 0)
                game->resetGame();
        else
        {
            showErrorMsg();
            showCommandsAllowed();
        }

        if (game->isGameOver() && !exit)
        {
            std::string msg;
            if (game->getWinner() == TIC_TAC_TOE_PIECE::X) msg = "You win!";
            else if (game->getWinner() == TIC_TAC_TOE_PIECE::O) msg = "You lose!";
            else if (game->getWinner() == TIC_TAC_TOE_PIECE::NONE) msg = "Draw!";
            std::cout << msg << std::endl;
            game->resetGame();
        }
    }
}
