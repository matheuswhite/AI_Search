#pragma once

#include <frontier.h>
#include <id.h>
#include <operator.h>

namespace AI_Search {

class State
{
    Id* _id;
    State* _father;
    std::vector<State*> _childs;
    Operator* _fatherOperator;
    int _depth;
    double _cost;
public:
    State(Id* id, State* father, Operator* fatherOperator, int depth, double cost);
    virtual ~State();

    Id* getId() const;
    State* getFather() const;
    Operator* getFatherOperator() const;
    std::vector<State*> getChilds() const;
    int getDepth() const;
    double getCost() const;

    std::pair<Id*, bool> search(Frontier* frontier, std::function<bool(State*, State*)> sortAlgorithm);
    void getListOfOperators(std::vector<Operator*>* list);

protected:
    virtual bool isFinal() = 0;
    virtual std::vector<Operator*> getAllowedOperators() = 0;
    virtual std::vector<State*> genChilds(std::vector<Operator*> allowedOperators) = 0;
    virtual Id* applyOperator(Operator* op) = 0;
};

}
