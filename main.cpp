#include <EightPuzzle/eightpuzzlestate.h>
#include <PriestNCannibal/priestncannibalstate.h>
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
    Solver<std::string>* solver = new Solver<std::string>(initialState, finalState, new BFS<std::string>(initialState, 15), true, false);

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
}

void PriestNCannibalProblem()
{
    State<PriestNCannibalId*>* initialState = new PriestNCannibalState(new PriestNCannibalId(3,3,0,0), nullptr, new PriestNCannibalOperator(nullptr, 0,0,true), 0, 0);
    State<PriestNCannibalId*>* finalState = new PriestNCannibalState(new PriestNCannibalId(0,0,3,3), nullptr, new PriestNCannibalOperator(nullptr, 0,0,true), 0, 0);
    Solver<PriestNCannibalId*>* solver = new Solver<PriestNCannibalId*>(initialState, finalState, new BFS<PriestNCannibalId*>(initialState), true, false);

    solver->solve();
    std::vector<Operator<PriestNCannibalId*>*> traceOfOperator = solver->getTraceOfOperators();

    if (traceOfOperator.size() != 0)
    {
        std::cout << "\nInitial State: " << solver->getInitialState()->toString() << std::endl;
        std::cout << "\nFinal State: " << solver->getFinalState()->toString() << std::endl;

        std::cout << "\n--List of Operators--" << std::endl;
        for (Operator<PriestNCannibalId*>* op : traceOfOperator)
        {
            PriestNCannibalOperator* op2 = dynamic_cast<PriestNCannibalOperator*>(op);
            if (op != nullptr) std::cout << op2->toString() << std::endl;
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
