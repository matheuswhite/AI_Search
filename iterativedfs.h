#pragma once

#include <dfs.h>

namespace AI_Search {

template <typename T>
class IterativeDFS : public DFS<T>
{
    int _maxDeep;
public:
    IterativeDFS(State<T>* initialState, int maxDeep) : DFS<T>(initialState), _maxDeep(maxDeep)
    {
    }
    virtual ~IterativeDFS()
    {
    }

    void addStates(std::vector<State<T>*> states)
    {
        std::vector<State<T>*> tempList;
        for (State<T>* state : states)
        {
            if (state->getDepth() <= _maxDeep)
            {
                tempList.push_back(state);
            }
        }

        Frontier<T>::addStates(tempList);
    }
};

}
