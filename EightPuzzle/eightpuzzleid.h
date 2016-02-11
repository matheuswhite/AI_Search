#pragma once

#include <id.h>
#include <string>

namespace EightPuzzle {

class EightPuzzleId : public AI_Search::Id
{
    std::string _value;
public:
    EightPuzzleId(std::string value);
    virtual ~EightPuzzleId();

    std::string toString();
    bool equal(Object *other);

    std::string getIdValue() const;
};

}
