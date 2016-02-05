#pragma once

#include <frontier.h>
#include <id.h>
#include <operator.h>
#include <object.h>

namespace AI_Search {

class State : public Object
{
    Id* _id;
    State* _father;
    Operator* _fatherOperator;
    int _depth;
    double _cost;
public:
    State(Id* id, State* father, Operator* fatherOperator, int depth, double cost);
    virtual ~State();

    Id* getId() const;
    State* getFather() const;
    Operator* getFatherOperator() const;
    int getDepth() const;
    double getCost() const;

    std::pair<Id*, bool> search(Frontier* frontier);
    void getListOfOperators(std::vector<Operator*>* list);

    bool equal(Object* other);
    virtual std::string toString() = 0;
protected:
    virtual bool isFinal() = 0;
    virtual std::vector<Operator*> getAllowedOperators() = 0;
    virtual std::vector<State*> genChilds(std::vector<Operator*> allowedOperators, Frontier* frontier) = 0;
    virtual Id* applyOperator(Operator* op) = 0;
};

}
