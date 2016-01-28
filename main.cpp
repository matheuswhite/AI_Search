#include <iostream>
#include <concreatestate.h>

using namespace AI_Search;
using namespace EightPuzzle;

bool BFS_Algorithm(State<std::string, std::string>* state1, State<std::string, std::string>* state2)
{
    return state1->getDepth() < state2->getDepth();
}

int main()
{
    //6x8241735
    State<std::string, std::string>* initialState = new ConcreateState("6x8241735", nullptr, "", 0, 0);
    Frontier<std::string, std::string>* frontier = new Frontier<std::string, std::string>(initialState);
    std::vector<std::string> listOfOperators;

    while(true)
    {
        std::pair<std::string, bool> result = frontier->getStates().at(0)->search(frontier, BFS_Algorithm);

        std::cout << result.first << "|" << result.second << "|" <<
                     frontier->getStates().at(0)->getDepth() << std::endl;

        if (result.second)
        {
            std::cout << std::endl;
            std::cout << "--Final State--" << std::endl ;
            std::cout << result.first << std::endl << std::endl;
            frontier->getStates().at(0)->getListOfOperators(&listOfOperators);
            std::reverse(listOfOperators.begin(), listOfOperators.end());

            std::cout << "--Operators--" << std::endl;
            for (int var = listOfOperators.size() - 1; var >= 0; --var) {
                std::cout << listOfOperators.at(var) << std::endl;
            }

            return 0;
        }

        frontier->removeFirst();
    }
}
