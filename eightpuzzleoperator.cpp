#include "eightpuzzleoperator.h"

EightPuzzle::EightPuzzleOperator::EightPuzzleOperator(std::string value)
{
    _value = value;
}

EightPuzzle::EightPuzzleOperator::~EightPuzzleOperator()
{

}

std::string EightPuzzle::EightPuzzleOperator::getOperatorValue() const
{
    return _value;
}

bool EightPuzzle::EightPuzzleOperator::operator ==(const EightPuzzleOperator& other) const
{
    return _value.compare(other.getOperatorValue()) == 0;
}
