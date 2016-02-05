#include "eightpuzzleoperator.h"

EightPuzzle::EightPuzzleOperator::EightPuzzleOperator(std::string value)
{
    _value = value;
}

EightPuzzle::EightPuzzleOperator::~EightPuzzleOperator()
{

}

std::string EightPuzzle::EightPuzzleOperator::toString()
{
    return _value;
}

bool EightPuzzle::EightPuzzleOperator::equal(Object *other)
{
    EightPuzzleOperator* op = dynamic_cast<EightPuzzleOperator*>(other);
    if (op != nullptr)
    {
        return _value.compare(op->getOperatorValue()) == 0;
    }
    return false;
}

std::string EightPuzzle::EightPuzzleOperator::getOperatorValue() const
{
    return _value;
}
