#include "solver.h"

AI_Search::Solver::Solver(State* initialState, std::function<bool(State*, State*)> searchAlgorithm)
{
    _initialState = initialState;
    _frontier = new Frontier(initialState, searchAlgorithm);
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

std::string AI_Search::Solver::toString()
{
    std::string output = "";
    if (_initialState != nullptr)
        output += _initialState->toString();
    if (_finalState != nullptr)
        output += "|" + _finalState->toString();
    return "Solver:" + output;
}

std::vector<AI_Search::Operator*> AI_Search::Solver::solve()
{
    std::vector<Operator*> listOfOperators;
    listOfOperators.clear();

    while(!_frontier->getStates().empty())
    {
        State* firstState = _frontier->getStates().at(0);
        _frontier->removeFirst();

        std::cout << "1--" << firstState->toString() << std::endl;
        std::getchar();

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
