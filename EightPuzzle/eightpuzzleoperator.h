#pragma once

#include <operator.h>
#include <string>
#include <iostream>

namespace EightPuzzle {

class EightPuzzleOperator : public AI_Search::Operator
{
    std::string _value;
public:
    EightPuzzleOperator(std::string value);
    virtual ~EightPuzzleOperator();

    std::string toString();
    bool equal(Object *other);

    std::string getOperatorValue() const;
};

}
