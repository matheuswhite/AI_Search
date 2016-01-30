#include "frontier.h"

AI_Search::Frontier::Frontier(State* initialState)
{
    _states.push_back(initialState);
}
AI_Search::Frontier::~Frontier()
{
    _states.clear();
}

void AI_Search::Frontier::addStates(std::vector<State*> states, std::function<bool(State*, State*)> sortAlgorithm)
{
    _states.insert(_states.end(), states.begin(), states.end());
    std::sort(_states.begin(), _states.end(), sortAlgorithm);
}
void AI_Search::Frontier::removeFirst()
{
    _states.erase(_states.begin());
}
void AI_Search::Frontier::removeAt(unsigned int index)
{
    _states.erase(_states.begin() + index);
}

std::vector<AI_Search::State*> AI_Search::Frontier::getStates() const
{
    return _states;
}
