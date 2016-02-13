#include "eightpuzzleoperator.h"

EightPuzzle::EightPuzzleOperator::EightPuzzleOperator(State<std::string>* startState, std::string value)
    : Operator<std::string>(startState), _value(value)
{
}

EightPuzzle::EightPuzzleOperator::~EightPuzzleOperator()
{
}

std::string EightPuzzle::EightPuzzleOperator::toString()
{
    return Operator<std::string>::toString() + "\nValue\t" +  _value;
}

bool EightPuzzle::EightPuzzleOperator::equal(Object *other)
{
    EightPuzzleOperator* op = dynamic_cast<EightPuzzleOperator*>(other);
    if (op != nullptr)
    {
        return _value.compare(op->getValue()) == 0;
    }
    return false;
}

std::string EightPuzzle::EightPuzzleOperator::getValue() const
{
    return _value;
}
