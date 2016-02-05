#include "eightpuzzleid.h"

EightPuzzle::EightPuzzleId::EightPuzzleId(std::string value) : Id()
{
    _value = value;
}

EightPuzzle::EightPuzzleId::~EightPuzzleId()
{

}

std::string EightPuzzle::EightPuzzleId::toString()
{
    return _value;
}

bool EightPuzzle::EightPuzzleId::equal(Object *other)
{
    EightPuzzleId* id = dynamic_cast<EightPuzzleId*>(other);
    if (id != nullptr)
    {
        return _value.compare(id->getIdValue()) == 0;
    }
    return false;
}

std::string EightPuzzle::EightPuzzleId::getIdValue() const
{
    return _value;
}
