#pragma once

#include <vector>

namespace AI_Search {

class State;

class Frontier
{
    std::vector<State*> _states;
public:
    Frontier(State* initialState)
    {
        _states.push_back(initialState);
    }
    virtual ~Frontier()
    {
        _states.clear();
    }

    void addStates(std::vector<State*> states, std::function<bool(State*, State*)> sortAlgorithm)
    {
        _states.insert(_states.end(), states.begin(), states.end());
        std::sort(_states.begin(), _states.end(), sortAlgorithm);
    }
    void removeFirst()
    {
        _states.erase(_states.begin());
    }
    void removeAt(unsigned int index)
    {
        _states.erase(_states.begin() + index);
    }

    std::vector<State*> getStates() const
    {
        return _states;
    }
};

}
