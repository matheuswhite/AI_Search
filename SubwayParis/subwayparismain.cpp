#include <SubwayParis/subwayparisstate.h>
#include <solver.h>
#include <bfs.h>
#include <astar.h>
#include <iterativedfs.h>

using namespace AI_Search;

int main2(int argc, char* argv[]) {

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

    return 0;
}
