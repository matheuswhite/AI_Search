#pragma once

#include <state.h>
#include <object.h>
#include <iostream>

namespace AI_Search {

class Solver
{
protected:
    Frontier* _frontier;
    State* _initialState;
    State* _finalState;
    bool _isVerbose;
    bool _isStepByStep;
public:
    Solver(State* initialState, std::function<bool(State*, State*)> searchAlgorithm, bool isVerbose, bool isStepByStep);
    virtual ~Solver();

    State* getInitialState() const;
    State* getFinalState() const;

    virtual std::vector<Operator*> solve();
};

}
