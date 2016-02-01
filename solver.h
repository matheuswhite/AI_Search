#pragma once

#include <state.h>
#include <object.h>
#include <iostream>

namespace AI_Search {

class Solver : public Object
{
protected:
    Frontier* _frontier;
    State* _initialState;
    State* _finalState;
public:
    Solver(State* initialState, std::function<bool(State*, State*)> searchAlgorithm);
    virtual ~Solver();

    State* getInitialState() const;
    State* getFinalState() const;

    virtual std::string toString();

    virtual std::vector<Operator*> solve();
};

}
