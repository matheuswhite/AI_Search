#include <EightPuzzle/eightpuzzlestate.h>
#include <PriestNCannibal/priestncannibalstate.h>
#include <SubwayParis/subwayparisstate.h>
#include <solver.h>
#include <bfs.h>
#include <astar.h>
#include <iterativedfs.h>

using namespace AI_Search;
using namespace EightPuzzle;

void EightPuzzleProblem()
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
}

void PriestNCannibalProblem()
{
    int priest = 3;
    int cannibal = 3;
    State<PriestNCannibalId*>* initialState = new PriestNCannibalState(new PriestNCannibalId(priest,cannibal,0,0), nullptr, new PriestNCannibalOperator(nullptr, 0,0,true), 0, 0);
    State<PriestNCannibalId*>* finalState = new PriestNCannibalState(new PriestNCannibalId(0,0,priest,cannibal), nullptr, new PriestNCannibalOperator(nullptr, 0,0,true), 0, 0);
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

void SubwayParisProblem()
{
    int initialId = 8;
    int goalId = 7;
    State<int>* initialState = new SubwayParisState(initialId, nullptr, new SubwayParisOperator(nullptr, 0, LINE_COLOR::NONE), 0, 0, goalId);
    State<int>* finalState = new SubwayParisState(goalId, nullptr, new SubwayParisOperator(nullptr, 0, LINE_COLOR::NONE), 0, 0, 0);
    Solver<int>* solver = new Solver<int>(initialState, finalState, new AStar<int>(initialState), true, false);

    solver->solve();
    std::vector<Operator<int>*> traceOfOperator = solver->getTraceOfOperators();

    if (traceOfOperator.size() != 0)
    {
        std::cout << "\nInitial State: " << solver->getInitialState()->toString() << std::endl;
        std::cout << "\nFinal State: " << solver->getFinalState()->toString() << std::endl;

        std::cout << "\n--List of Operators--" << std::endl;
        for (Operator<int>* op : traceOfOperator)
        {
            SubwayParisOperator* op2 = dynamic_cast<SubwayParisOperator*>(op);
            if (op != nullptr) std::cout << op2->toString();
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "--No Solution--" << std::endl << std::endl;
    }
}

int main2(int argc, char* argv[])
{
    SubwayParisProblem();
}
