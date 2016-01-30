#pragma once

#include <operator.h>
#include <string>

namespace EightPuzzle {

class EightPuzzleOperator : public Operator
{
    std::string _value;
public:
    EightPuzzleOperator(std::string value);
    virtual ~EightPuzzleOperator();

    std::string getOperatorValue() const;
};

}
