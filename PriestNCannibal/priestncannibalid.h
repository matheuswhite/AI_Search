#pragma once

#include <object.h>

class PriestNCannibalId : public Object
{
    int _startPriestAmount;
    int _startCannibalAmount;
    int _goalPriestAmount;
    int _goalCannibalAmount;
public:
    PriestNCannibalId(int startPriestAmount, int startCannibalAmount, int goalPriestAmount, int goalCannibalAmount);
    virtual ~PriestNCannibalId();

    int getStartPriestAmount() const;
    int getGoalPriestAmount() const;
    int getStartCannibalAmount() const;
    int getGoalCannibalAmount() const;

    std::string toString();
    bool equal(Object* other);

    bool operator ==(PriestNCannibalId* other)
    {
        return equal(other);
    }
};
