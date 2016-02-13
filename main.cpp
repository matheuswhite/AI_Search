#include <EightPuzzle/eightpuzzlestate.h>
#include <solver.h>
#include <bfs.h>
#include <astar.h>
#include <iterativedfs.h>

using namespace AI_Search;
using namespace EightPuzzle;

void EightPuzzleProblem()
{
    //6x3128745
    //4623187x5
    //123456x78
    State<std::string>* initialState = new EightPuzzleState("4623187x5", nullptr, new EightPuzzleOperator(nullptr, ""), 0, 0);
    State<std::string>* finalState = new EightPuzzleState("12345678x", nullptr, new EightPuzzleOperator(nullptr, ""), 0, 0);
    Solver<std::string>* solver = new Solver<std::string>(initialState, finalState, new IterativeDFS<std::string>(initialState, 15), true, false);

    solver->solve();
    std::vector<Operator<std::string>*> traceOfOperator = solver->getTraceOfOperators();

    if (traceOfOperator.size() != 0)
    {
        std::cout << "Initial State: " << solver->getInitialState()->getId() << std::endl;
        std::cout << "Final State: " << solver->getFinalState()->getId() << std::endl;

        std::cout << "--List of Operators--" << std::endl;
        for (Operator<std::string>* op : traceOfOperator)
        {
            std::cout << dynamic_cast<EightPuzzleOperator*>(op)->getValue() << std::endl;
        }
    }
    else
    {
        std::cout << "--No Solution--" << std::endl;
    }
}

int main(int argc, char* argv[])
{
    EightPuzzleProblem();
}
