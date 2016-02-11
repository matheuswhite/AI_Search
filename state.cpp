#include "state.h"

AI_Search::State::State(Id* id, State* father, Operator* fatherOperator, int depth, double cost)
{
    _id = id;
    _father = father;
    _fatherOperator = fatherOperator;
    _depth = depth;
    _cost = cost;
    genHeuristic();
}
AI_Search::State::~State()
{
    delete _id;
    _id = nullptr;
    _father = nullptr;
    _fatherOperator = nullptr;
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
int AI_Search::State::getDepth() const
{
    return _depth;
}
double AI_Search::State::getCost() const
{
    return _cost;
}

double AI_Search::State::getHeuristic() const
{
    return _heuristic;
}

void AI_Search::State::genHeuristic()
{
    _heuristic = 0;
}

std::vector<AI_Search::Operator*> AI_Search::State::getListOfOperators()
{
    std::vector<Operator*> output;
    State* father = this;
    while(father != nullptr)
    {
        output.push_back(father->getFatherOperator());
        father = father->getFather();
    }
    std::reverse(output.begin(), output.end());

    return output;
}

bool AI_Search::State::equal(Object* other)
{
    State* s = dynamic_cast<State*>(other);
    if (s != nullptr)
    {
        return _id->equal(s->getId());
    }
    return false;
}
