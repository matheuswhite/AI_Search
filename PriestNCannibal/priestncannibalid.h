#pragma once

#include <object.h>

class PriestNCannibalId : public Object
{
    int _startMarginAmount;
    int _goalMarginAmount;
public:
    PriestNCannibalId(int startMarginAmount, int goalMarginAmount);
    virtual ~PriestNCannibalId();

    int getStartMarginAmount() const;
    int getGoalMarginAmount() const;

    std::string toString();
    bool equal(Object* other);

    bool operator ==(PriestNCannibalId* other)
    {
        return equal(other);
    }
};
