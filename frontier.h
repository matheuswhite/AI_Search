#pragma once

#include <vector>
#include <functional>
#include <algorithm>

namespace AI_Search {

class State;

class Frontier
{
    std::vector<State*> _states;
public:
    Frontier(State* initialState);
    virtual ~Frontier();

    void addStates(std::vector<State*> states, std::function<bool(State*, State*)> sortAlgorithm);
    void removeFirst();
    void removeAt(unsigned int index);
    std::vector<State*> getStates() const;
};

}
