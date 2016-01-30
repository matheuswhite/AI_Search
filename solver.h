#pragma once

#include <ai_search.h>

namespace AI_Search {

template <typename T>
class Solver
{
    Frontier<T, >* _frontier;
    State<T, Op>* _initialState;

public:
    Solver(T initialId)
    {
        _initialState = new Stat
    }
    virtual ~Solver()
    {

    }

    virtual std::string solve() = 0;

};

}
