#pragma once

#include <state.h>

namespace AI_Search {

class Solver
{
    Frontier* _frontier;
    State* _initialState;
    State* _finalState;
public:
    Solver(State* initialState, std::function<bool(State*, State*)> searchAlgorithm);
    virtual ~Solver();

    State* getInitialState() const;
    State* getFinalState() const;

    std::vector<Operator*> solver();
};

}
