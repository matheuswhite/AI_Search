#pragma once

#include <operator.h>
#include <PriestNCannibal/priestncannibalid.h>

using namespace AI_Search;

class PriestNCannibalState;

class PriestNCannibalOperator : public Operator<PriestNCannibalId*>
{
public:
    PriestNCannibalOperator(State<PriestNCannibalId*>* startState);
    virtual ~PriestNCannibalOperator();
};
