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

std::vector<AI_Search::Operator*> AI_Search::Solver::solver()
{
    std::vector<Operator*> listOfOperators;
    listOfOperators.clear();

    while(!_frontier->getStates().empty())
    {
        std::pair<Id*, bool> result = _frontier->getStates().at(0)->search(_frontier);

        if (result.second)
        {

            _frontier->getStates().at(0)->getListOfOperators(&listOfOperators);
            std::reverse(listOfOperators.begin(), listOfOperators.end());

            break;
        }

        _frontier->removeFirst();
    }

    return listOfOperators;
}
