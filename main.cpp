#include <iostream>
#include <eightpuzzlestate.h>
#include <frontier.h>
#include <algorithm>

using namespace AI_Search;
using namespace EightPuzzle;

bool BFS_Algorithm(State* state1, State* state2)
{
    return state1->getDepth() < state2->getDepth();
}

int main()
{
    //6x8241735
    State* initialState = new EightPuzzleState(new EightPuzzleId("123456x78"), nullptr, new EightPuzzleOperator(""), 0, 0);
    Frontier* frontier = new Frontier(initialState, BFS_Algorithm);
    std::vector<Operator*> listOfOperators;

    while(!frontier->getStates().empty())
    {
        std::pair<Id*, bool> result = frontier->getStates().at(0)->search(frontier);

        std::cout << ((EightPuzzleId*)result.first)->getIdValue() << "|" << result.second << "|" <<
                     frontier->getStates().at(0)->getDepth() << std::endl;

        if (result.second)
        {
            std::cout << std::endl;
            std::cout << "--Final State--" << std::endl ;
            std::cout << ((EightPuzzleId*)result.first)->getIdValue() << std::endl << std::endl;

            frontier->getStates().at(0)->getListOfOperators(&listOfOperators);
            std::reverse(listOfOperators.begin(), listOfOperators.end());

            std::cout << "--Operators--" << std::endl;
            for (int var = listOfOperators.size() - 1; var >= 0; --var) {
                std::cout << ((EightPuzzleOperator*)listOfOperators.at(var))->getOperatorValue() << std::endl;
            }

            return 0;
        }

        frontier->removeFirst();
    }
}
