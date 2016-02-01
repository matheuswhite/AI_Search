#pragma once

#include <state.h>

namespace AI_Search {

class IterativeFrontier : public Frontier
{
    unsigned int _depthMax;

    void addState(State* state);
public:
    IterativeFrontier(State* initialState, std::function<bool(State*, State*)> sortAlgorithm, unsigned int depthMax);
    virtual ~IterativeFrontier();

    void addStates(std::vector<State*> states);
};

}
