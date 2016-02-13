#pragma once

#include <frontier.h>

namespace AI_Search {

template <typename T>
class AStar : public Frontier<T>
{
    std::vector<State<T>*> _visitedStates;

    static bool aStar(State<T>* first, State<T>* second)
    {
        return first->getDepth() + first->getHeuristic() < second->getDepth() + second->getHeuristic();
    }

public:
    AStar(State<T>* initialState) : Frontier<T>(initialState)
    {
        _visitedStates.push_back(initialState);
    }
    virtual ~AStar()
    {
    }

    void sort()
    {
        std::sort(this->_states.begin(), this->_states.end(), aStar);
    }

    void addStates(std::vector<State<T>*> states)
    {
        std::vector<State<T>*> tempList;
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
                tempList.push_back(state);
                _visitedStates.push_back(state);
            }
        }

        Frontier<T>::addStates(tempList);
    }
};

}
