#pragma once

#include <object.h>
#include <vector>
#include <algorithm>

namespace AI_Search {

template <typename T>
class Operator;

template <typename T>
class State : public Object
{
    T _id;
    State* _father;
    Operator<T>* _fatherOperator;
    int _depth;
    double _cost;
protected:
    double _heuristic;
public:
    State(T id, State<T>* father, Operator<T>* fatherOperator, int depth, double cost)
        : _id(id), _father(father), _fatherOperator(fatherOperator), _depth(depth), _cost(cost)
    {
        genHeuristic();
    }
    virtual ~State() {}

    virtual std::string toString() = 0;
    virtual std::vector<Operator<T>*> getAllowedOperators() = 0;
    virtual std::vector<State<T>*> genChilds(std::vector<Operator<T>*> allowedOperators) = 0;
    virtual void genHeuristic()
    {
        _heuristic = 0;
    }

    T getId() const
    {
        return _id;
    }
    State<T>* getFather() const
    {
        return _father;
    }
    Operator<T>* getFatherOperator() const
    {
        return _fatherOperator;
    }
    int getDepth() const
    {
        return _depth;
    }
    double getCost() const
    {
        return _cost;
    }
    double getHeuristic() const
    {
        return _heuristic;
    }

    std::vector<Operator<T>*> getTraceOfOperators()
    {
        std::vector<Operator<T>*> output;
        State<T>* father = this;
        while(father != nullptr)
        {
            output.push_back(father->getFatherOperator());
            father = father->getFather();
        }
        std::reverse(output.begin(), output.end());

        return output;
    }

    bool equal(Object* other)
    {
        State<T>* s = dynamic_cast<State<T>*>(other);
        if (s != nullptr)
        {
            return _id == s->getId();
        }
        return false;
    }
};

}
