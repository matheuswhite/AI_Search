#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

namespace AI_Search {

template <typename...> class State;

template <typename T, typename Op>
class Frontier
{
    std::vector<State<T, Op>*> _states;
public:
    Frontier(State<T, Op>* initialState)
    {
        _states.push_back(initialState);
    }
    virtual ~Frontier()
    {
        _states.clear();
    }

    void addStates(std::vector<State<T, Op>*> states, std::function<bool(State<T, Op>*, State<T, Op>*)> sortAlgorithm)
    {
        _states.insert(_states.end(), states.begin(), states.end());
        std::sort(_states.begin(), _states.end(), sortAlgorithm);
    }
    void removeFirst()
    {
        _states.erase(_states.begin());
    }

    std::vector<State<T, Op>*> getStates() const
    {
        return _states;
    }
};

template <typename T, typename Op>
class State<T, Op>
{
    T _id;
    State<T, Op>* _father;
    std::vector<State<T, Op>*> _childs;
    Op _fatherOperator;
    int _depth;
    double _cost;
public:
    State(T id, State<T, Op>* father, Op fatherOperator, int depth, double cost)
    {
        _id = id;
        _father = father;
        _fatherOperator = fatherOperator;
        _depth = depth;
        _cost = cost;
    }
    virtual ~State()
    {
        _father = nullptr;
        _fatherOperator = nullptr;
        _childs.clear();
    }

    virtual bool isFinal() = 0;
    virtual std::vector<Op> getAllowedOperators() = 0;
    virtual std::vector<State<T, Op>*> genChilds(std::vector<Op> allowedOperators) = 0;

    T getId() const
    {
        return _id;
    }
    State<T, Op>* getFather() const
    {
        return _father;
    }
    Op getFatherOperator() const
    {
        return _fatherOperator;
    }
    std::vector<State<T, Op>*> getChilds() const
    {
        return _childs;
    }
    int getDepth() const
    {
        return _depth;
    }
    double getCost() const
    {
        return _cost;
    }

    std::pair<T, bool> search(Frontier<T, Op>* frontier, std::function<bool(State<T, Op>*, State<T, Op>*)> sortAlgorithm)
    {
        if (isFinal())
        {
            return std::pair<T, bool>(_id, true);
        }
        _childs = genChilds(getAllowedOperators());
        frontier->addStates(_childs, sortAlgorithm);

        return std::pair<T, bool>(_id, false);
    }

    void getListOfOperators(std::vector<Op>* list)
    {
        if (_father == nullptr)
        {
            return ;
        }
        list->push_back(_fatherOperator);
        _father->getListOfOperators(list);
    }
};

}
