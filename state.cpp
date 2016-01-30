#include "state.h"

AI_Search::State::State(Id* id, State* father, Operator* fatherOperator, int depth, double cost)
{
    _id = id;
    _father = father;
    _fatherOperator = fatherOperator;
    _depth = depth;
    _cost = cost;
}
AI_Search::State::~State()
{
    delete _id;
    _id = nullptr;
    _father = nullptr;
    _fatherOperator = nullptr;
    _childs.clear();
}

AI_Search::Id* AI_Search::State::getId() const
{
    return _id;
}
AI_Search::State* AI_Search::State::getFather() const
{
    return _father;
}
AI_Search::Operator* AI_Search::State::getFatherOperator() const
{
    return _fatherOperator;
}
std::vector<AI_Search::State*> AI_Search::State::getChilds() const
{
    return _childs;
}
int AI_Search::State::getDepth() const
{
    return _depth;
}
double AI_Search::State::getCost() const
{
    return _cost;
}

std::pair<AI_Search::Id*, bool> AI_Search::State::search(Frontier* frontier, std::function<bool(State*, State*)> sortAlgorithm)
{
    if (isFinal())
    {
        return std::pair<Id*, bool>(_id, true);
    }
    _childs = genChilds(getAllowedOperators());
    frontier->addStates(_childs, sortAlgorithm);

    return std::pair<Id*, bool>(_id, false);
}

void AI_Search::State::getListOfOperators(std::vector<Operator*>* list)
{
    if (_father == nullptr)
    {
        return ;
    }
    list->push_back(_fatherOperator);
    _father->getListOfOperators(list);
}
