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
