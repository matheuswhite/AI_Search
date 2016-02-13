#pragma once

#include <operator.h>

namespace EightPuzzle {

class EightPuzzleOperator : public AI_Search::Operator<std::string>
{
    std::string _value;
public:
    EightPuzzleOperator(AI_Search::State<std::string>* startState, std::string value);
    virtual ~EightPuzzleOperator();

    std::string toString();
    bool equal(Object *other);

    std::string getValue() const;
};

}
