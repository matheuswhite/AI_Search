#pragma once

#include <object.h>
#include <vector>

template <typename T>
class MiniMaxState : public Object
{
    T _id;
    int _depth;
    int _utility;
public:
    MiniMaxState(T id, int depth) : _id(id), _depth(depth)
    {
        genUtility();
    }
    virtual ~MiniMaxState()
    {
    }

    void setUtility(int value)
    {
        _utility = value;
    }

    int getUtility() const
    {
        return _utility;
    }

    T getId() const
    {
        return _id;
    }

    int getDepth() const
    {
        return _depth;
    }

    virtual std::string toString() = 0;
    virtual bool isFinal() = 0;
    virtual std::vector<MiniMaxState<T>*> genSuccessors() = 0;

    virtual int genUtility()
    {
        _utility = 0;
    }

    virtual bool equal(Object *other)
    {
        MiniMaxState<T>* s = dynamic_cast<MiniMaxState<T>*>(other);
        if (s != nullptr)
        {
            return _id == s->getId();
        }
        return false;
    }
};
