#pragma once

#include <vector>
#include <functional>
#include <algorithm>

namespace AI_Search {

class State;

class Frontier
{
    std::vector<State*> _states;
    std::function<bool(State*, State*)> _sortAlgorithm;
public:
    Frontier(State* initialState, std::function<bool(State*, State*)> sortAlgorithm);
    virtual ~Frontier();

    void addStates(std::vector<State*> states);
    void removeFirst();
    void removeAt(unsigned int index);
    std::vector<State*> getStates() const;
};

}
