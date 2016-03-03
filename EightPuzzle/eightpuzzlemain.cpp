#include <EightPuzzle/eightpuzzlestate.h>
#include <solver.h>
#include <bfs.h>
#include <astar.h>
#include <iterativedfs.h>

using namespace AI_Search;
using namespace EightPuzzle;

int main1(int argc, char* argv[])
{
    //1624387x5 ok/ok/ok(13)
    //6x3128745 ok/ok/ok(19)
    //4623187x5 ok/ok/ok(15)
    //123456x78 ok/ok/ok
    State<std::string>* initialState = new EightPuzzleState("1624387x5", nullptr, new EightPuzzleOperator(nullptr, ""), 0, 0);
    State<std::string>* finalState = new EightPuzzleState("12345678x", nullptr, new EightPuzzleOperator(nullptr, ""), 0, 0);
    Solver<std::string>* solver = new Solver<std::string>(initialState, finalState, new AStar<std::string>(initialState), true, false);

    solver->solve();
    std::vector<Operator<std::string>*> traceOfOperator = solver->getTraceOfOperators();

    if (traceOfOperator.size() != 0)
    {
        std::cout << "\nInitial State: " << solver->getInitialState()->getId() << std::endl;
        std::cout << "\nFinal State: " << solver->getFinalState()->getId() << std::endl;

        std::cout << "\n--List of Operators--" << std::endl;
        for (Operator<std::string>* op : traceOfOperator)
        {
            std::cout << dynamic_cast<EightPuzzleOperator*>(op)->getValue() << std::endl;
        }
    }
    else
    {
        std::cout << "--No Solution--" << std::endl;
    }

    return 0;
}
