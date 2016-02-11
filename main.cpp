#include <iostream>
#include "EightPuzzle/eightpuzzlestate.h"
#include <solver.h>
#include <iterativesolver.h>
#include <searchalgorithms.h>

using namespace AI_Search;
using namespace EightPuzzle;

int main(int argc, char* argv[])
{
    //6x3128745
    //4623187x5
    //123456x78
    State* initialState = new EightPuzzleState(new EightPuzzleId("6x3128745"), nullptr, new EightPuzzleOperator(""), 0, 0);
    Solver* solver;

    //solver = new IterativeSolver(initialState, DFS_Algorithm, 15, true, false);
    solver = new Solver(initialState, AStar, true, false);

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
