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

std::string EightPuzzle::EightPuzzleOperator::getOperatorValue() const
{
    return _value;
}
