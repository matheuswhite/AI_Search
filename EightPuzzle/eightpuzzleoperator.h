#pragma once

#include <operator.h>

using namespace AI_Search;

namespace EightPuzzle {

class EightPuzzleState;

class EightPuzzleOperator : public Operator<std::string>
{
    std::string _value;
public:
    EightPuzzleOperator(State<std::string> *startState, std::string value);
    virtual ~EightPuzzleOperator();

    std::string toString();
    bool equal(Object *other);

    std::string getValue() const;
};

}
