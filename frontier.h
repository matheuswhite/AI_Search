#pragma once

#include <state.h>

namespace AI_Search {

template <typename T>
class Frontier
{
protected:
    std::vector<State<T>*> _states;
    std::vector<State<T>*> _visitedStates;
public:
    Frontier(State<T>* initialState)
    {
        _states.push_back(initialState);
        _visitedStates.push_back(initialState);
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
        for (State<T>* state : states)
        {
            bool isVisited = false;
            for (State<T>* visitedState : _visitedStates)
            {
                if (state->equal(visitedState))
                {
                    isVisited = true;
                    break;
                }
            }
            if (!isVisited)
            {
                _visitedStates.push_back(state);
                _states.push_back(state);
            }
        }

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
