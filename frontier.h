#pragma once

#include <state.h>

namespace AI_Search {

template <typename T>
class Frontier
{
protected:
    std::vector<State<T>*> _states;
public:
    Frontier(State<T>* initialState)
    {
        _states.push_back(initialState);
    }
    virtual ~Frontier()
    {
    }

    virtual void sort() = 0;

    bool isEmpty() const
    {
        return _states.empty();
    }

    virtual State<T>* getFirstState()
    {
        State<T>* output = _states.at(0);
        _states.erase(_states.begin());
        return output;
    }

    virtual void addStates(std::vector<State<T>*> states)
    {
        _states.insert(_states.end(), states.begin(), states.end());
        sort();
    }

    virtual void clear()
    {
        int size = _states.size();
        for (int var = 0; var < size; ++var) {
            delete _states.at(var);
        }
        _states.clear();
    }
};

}
