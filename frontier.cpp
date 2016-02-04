#include "frontier.h"

AI_Search::Frontier::Frontier(State* initialState, std::function<bool(State*, State*)> sortAlgorithm)
{
    _states.push_back(initialState);
    _sortAlgorithm = sortAlgorithm;
}
AI_Search::Frontier::~Frontier()
{
    _states.clear();
}

std::function<bool(AI_Search::State*, AI_Search::State*)> AI_Search::Frontier::getSortAlgorithm() const
{
    return _sortAlgorithm;
}

void AI_Search::Frontier::addStates(std::vector<State*> states)
{
    for (State* state : _states)
    {

    }

    _states.insert(_states.end(), states.begin(), states.end());
    std::sort(_states.begin(), _states.end(), _sortAlgorithm);
}

void AI_Search::Frontier::removeFirst()
{
    if (_states.size() > 0)
        _states.erase(_states.begin());
}

void AI_Search::Frontier::clearStates()
{
    int size = _states.size();
    for (int var = 0; var < size; ++var) {
        delete _states.at(var);
    }
    _states.clear();
}

std::vector<AI_Search::State*> AI_Search::Frontier::getStates() const
{
    return _states;
}
