#pragma once

#include <frontier.h>

namespace AI_Search {

template <typename T>
class AStar : public Frontier<T>
{
    static bool aStar(State<T>* first, State<T>* second)
    {
        return first->getDepth() + first->getHeuristic() < second->getDepth() + second->getHeuristic();
    }

public:
    AStar(State<T>* initialState) : Frontier<T>(initialState)
    {
    }
    virtual ~AStar()
    {
    }

    void sort()
    {
        std::sort(this->_states.begin(), this->_states.end(), aStar);
    }
};

}
