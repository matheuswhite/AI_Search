#pragma once

#include <id.h>
#include <string>

namespace EightPuzzle {

class EightPuzzleId : public Id
{
    std::string _value;
public:
    EightPuzzleId(std::string value);
    virtual ~EightPuzzleId();

    std::string getIdValue() const;

    bool operator ==(const EightPuzzleId& other) const;
};

}
