#include "frontieriterative.h"

AI_Search::FrontierIterative::FrontierIterative(State* initialState, std::function<bool(State*, State*)> sortAlgorithm, unsigned int depthMax) : Frontier(initialState, sortAlgorithm)
{
    _depthMax = depthMax;
}

AI_Search::FrontierIterative::~FrontierIterative()
{

}

void AI_Search::FrontierIterative::addState(State* state)
{
    if (state->getDepth() <= _depthMax)
        _states.push_back(state);
}

void AI_Search::FrontierIterative::addStates(std::vector<State*> states)
{
    for (State* state : states)
    {
        addState(state);
    }
    std::sort(_states.begin(), _states.end(), _sortAlgorithm);
}
