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

    std::cout << game->getCurrentBoardState();

    while (!exit)
    {
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
                std::cout << game->getCurrentBoardState();

                if (!game->getCurrentState()->isFinal())
                    game->aiMove();

                if (game->getCurrentState() != nullptr)
                    std::cout << game->getCurrentBoardState();
            }
            else
            {
                showErrorMsg();
            }
        }
        else if (input.compare("exit") == 0)
            exit = true;
        else if (input.compare("reset") == 0)
        {
                game->resetGame();
                std::cout << game->getCurrentBoardState();
        }
        else
        {
            showErrorMsg();
            showCommandsAllowed();
        }

        if (game->getCurrentState()->isFinal() && !exit)
        {
            std::string msg = "init";
            if (game->getCurrentState()->getId()->isX_Winner()) msg = "You win!";
            else if (game->getCurrentState()->getId()->isO_Winner()) msg = "You lose!";
            else if (game->getCurrentState()->getId()->isFull()) msg = "Draw!";
            std::cout << msg << std::endl;
            game->resetGame();
            std::cout << game->getCurrentBoardState();
        }
    }
}
