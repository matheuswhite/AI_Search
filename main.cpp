#include <iostream>
#include <eightpuzzlestate.h>
#include <solver.h>
#include <iterativesolver.h>
#include <searchalgorithms.h>

using namespace AI_Search;
using namespace EightPuzzle;

int main(int argc, char* argv[])
{
    //1534826x7
    State* initialState = new EightPuzzleState(new EightPuzzleId("1534826x7"), nullptr, new EightPuzzleOperator(""), 0, 0);
    Solver* solver;

    solver = new IterativeSolver(initialState, DFS_Algorithm, 14, true, false);
    //solver = new Solver(initialState, BFS_Algorithm, true, false);

    std::vector<Operator*> listOperator = solver->solve();

    if (listOperator.size() != 0)
    {
        std::cout << "Initial State: " << ((EightPuzzleId*)solver->getInitialState()->getId())->getIdValue() << std::endl;
        std::cout << "Final State: " << ((EightPuzzleId*)solver->getFinalState()->getId())->getIdValue() << std::endl;
        std::cout << "Steps made: " << ((IterativeSolver*)solver)->getStepsMade() << std::endl;

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
