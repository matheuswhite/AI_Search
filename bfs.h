#pragma once

#include <frontier.h>

namespace AI_Search {

template <typename T>
class BFS : public Frontier<T>
{
    std::vector<State<T>*> _visitedStates;

    static bool bfs(State<T>* first, State<T>* second)
    {
        return first->getDepth() < second->getDepth();
    }
public:
    BFS(State<T>* initialState) : Frontier<T>(initialState)
    {
        _visitedStates.push_back(initialState);
    }
    virtual ~BFS()
    {
    }

    void sort()
    {
        std::sort(this->_states.begin(), this->_states.end(), bfs);
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
