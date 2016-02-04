#pragma once

#include <object.h>

namespace AI_Search {

class Id : public Object
{
public:
    Id() {}
    virtual ~Id(){}

    virtual std::string toString() = 0;
    virtual bool equal(Object* other) = 0;
};

}
