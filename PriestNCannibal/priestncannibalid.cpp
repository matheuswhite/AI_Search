#include "priestncannibalid.h"

PriestNCannibalId::PriestNCannibalId(int startMarginAmount, int goalMarginAmount)
    : _startMarginAmount(startMarginAmount), _goalMarginAmount(goalMarginAmount)
{
}

PriestNCannibalId::~PriestNCannibalId()
{
}

std::string PriestNCannibalId::toString()
{
    return "StartMargin: " + std::to_string(_startMarginAmount/10) + " Priests and " + std::to_string(_startMarginAmount%10) + "Cannibals\nGoalMargin: "
            + std::to_string(_goalMarginAmount/10) + " Priests and " + std::to_string(_goalMarginAmount%10) + "Cannibals";
}

int PriestNCannibalId::getStartMarginAmount() const
{
    return _startMarginAmount;
}

int PriestNCannibalId::getGoalMarginAmount() const
{
    return _goalMarginAmount;
}

bool PriestNCannibalId::equal(Object* other)
{
    PriestNCannibalId* id = dynamic_cast<PriestNCannibalId*>(other);
    if (id != nullptr)
    {
        return _startMarginAmount == id->getStartMarginAmount() && _goalMarginAmount == id->getGoalMarginAmount();
    }
    return false;
}
