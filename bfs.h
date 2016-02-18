#pragma once

#include <frontier.h>

namespace AI_Search {

template <typename T>
class BFS : public Frontier<T>
{
    static bool bfs(State<T>* first, State<T>* second)
    {
        return first->getDepth() < second->getDepth();
    }
public:
    BFS(State<T>* initialState) : Frontier<T>(initialState)
    {

    }
    virtual ~BFS()
    {
    }

    void sort()
    {
        std::sort(this->_states.begin(), this->_states.end(), bfs);
    }
};

}
