#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

namespace AI_Search {

template <typename...> class State;

template <typename T, typename Op>
class Frontier
{
    std::vector<State<T, Op>*> _states;
public:
    Frontier(State<T, Op>* initialState)
    {
        _states.push_back(initialState);
    }
    virtual ~Frontier()
    {
        _states.clear();
    }

    void addStates(std::vector<State<T, Op>*> states, std::function<bool(State<T, Op>*, State<T, Op>*)> sortAlgorithm)
    {
        _states.insert(_states.end(), states.begin(), states.end());
        std::sort(_states.begin(), _states.end(), sortAlgorithm);
    }
    void removeFirst()
    {
        _states.erase(_states.begin());
    }

    std::vector<State<T, Op>*> getStates() const
    {
        return _states;
    }
};

}
