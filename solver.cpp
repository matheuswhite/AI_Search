#include "solver.h"

AI_Search::Solver::Solver(State* initialState, std::function<bool(State*, State*)> searchAlgorithm, bool isVerbose, bool isStepByStep)
{
    _initialState = initialState;
    _frontier = new Frontier(initialState, searchAlgorithm);
    _isVerbose = isVerbose || isStepByStep;
    _isStepByStep = isStepByStep;
}
AI_Search::Solver::~Solver()
{

}

AI_Search::State* AI_Search::Solver::getInitialState() const
{
    return _initialState;
}
AI_Search::State* AI_Search::Solver::getFinalState() const
{
    return _finalState;
}

std::vector<AI_Search::Operator*> AI_Search::Solver::solve()
{
    std::vector<Operator*> listOfOperators;
    listOfOperators.clear();

    while(!_frontier->getStates().empty())
    {
        State* firstState = _frontier->getStates().at(0);
        _frontier->removeFirst();

        if (_isVerbose) std::cout << "!--" << firstState->toString() << std::endl;
        if (_isStepByStep) std::getchar();

        std::pair<Id*, bool> result = firstState->search(_frontier);

        if (result.second)
        {
            firstState->getListOfOperators(&listOfOperators);
            std::reverse(listOfOperators.begin(), listOfOperators.end());

            _finalState = firstState;

            break;
        }
    }

    _frontier->clearStates();

    return listOfOperators;
}
