#pragma once

#include <state.h>

namespace AI_Search {

template <typename T>
class Operator : public Object
{
    State<T>* _startState;
    State<T>* _targetState;
public:
    Operator(State<T>* startState) : _startState(startState) {}
    virtual ~Operator() {}

    State<T>* getStartState() const
    {
        return _startState;
    }
    State<T>* getTargetState() const
    {
        return _targetState;
    }
    void setTargetState(State<T>* state)
    {
        _targetState = state;
    }

    virtual std::string toString()
    {
        return "Start state\t" + _startState->toString() + "\nTarget state\t" + _targetState->toString();
    }

    virtual bool equal(Object* other)
    {
        Operator<T>* op = dynamic_cast<Operator<T>*>(other);
        if (op != nullptr)
        {
            return _startState == op->getStartState() && _targetState == op->getTargetState();
        }
        return false;
    }
};

}
