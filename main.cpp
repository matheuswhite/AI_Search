#include <iostream>
#include <eightpuzzlestate.h>
#include <solver.h>

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
    Solver* solver = new Solver(initialState, BFS_Algorithm);

    std::vector<Operator*> listOperator = solver->solve();

    if (listOperator.size() != 0)
    {
        std::cout << "Initial State: " << ((EightPuzzleId*)solver->getInitialState()->getId())->getIdValue() << std::endl;
        std::cout << "Final State: " << ((EightPuzzleId*)solver->getFinalState()->getId())->getIdValue() << std::endl;

        std::cout << "--List of Operators--" << std::endl;
        for (Operator* op : listOperator)
        {
            std::cout << ((EightPuzzleOperator*)op)->getOperatorValue() << std::endl;
        }
    }
    else
    {
        std::cout << "--No Solution--" << std::endl;
    }
}
