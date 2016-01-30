#pragma once

#include <state.h>

namespace AI_Search {

class FrontierIterative : Frontier
{
    unsigned int _depthMax;

    void addState(State* state);

public:
    FrontierIterative(State* initialState, std::function<bool(State*, State*)> sortAlgorithm, unsigned int depthMax);
    virtual ~FrontierIterative();

    void addStates(std::vector<State*> states)
    {
        for (State* state : states)
        {
            addState(state);
        }
        std::sort(_states.begin(), _states.end(), _sortAlgorithm);
    }
};

}
