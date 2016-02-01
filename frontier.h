#pragma once

#include <vector>
#include <functional>
#include <algorithm>
#include <object.h>

namespace AI_Search {

class State;

class Frontier : public Object
{
protected:
    std::vector<State*> _states;
    std::function<bool(State*, State*)> _sortAlgorithm;
public:
    Frontier(State* initialState, std::function<bool(State*, State*)> sortAlgorithm);
    virtual ~Frontier();

    std::function<bool(State*, State*)> getSortAlgorithm() const;

    virtual std::string toString();

    virtual void addStates(std::vector<State*> states);
    void removeFirst();
    void clearStates();
    std::vector<State*> getStates() const;
};

}
