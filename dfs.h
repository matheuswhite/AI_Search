#pragma once

#include <frontier.h>

namespace AI_Search {

template <typename T>
class DFS : public Frontier<T>
{
protected:
    static bool dfs(State<T>* first, State<T>* second)
    {
        return first->getDepth() > second->getDepth();
    }
public:
    DFS(State<T>* initialState) : Frontier<T>(initialState)
    {

    }
    virtual ~DFS()
    {
    }

    void sort()
    {
        std::sort(this->_states.begin(), this->_states.end(), dfs);
    }
};

}
