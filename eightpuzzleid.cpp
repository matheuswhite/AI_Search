#include "eightpuzzleid.h"

EightPuzzle::EightPuzzleId::EightPuzzleId(std::string value) : Id()
{
    _value = value;
}

EightPuzzle::EightPuzzleId::~EightPuzzleId()
{

}

std::string EightPuzzle::EightPuzzleId::getIdValue() const
{
    return _value;
}

bool EightPuzzle::EightPuzzleId::operator ==(const EightPuzzleId& other) const
{
    return _value.compare(other.getIdValue()) == 0;
}
