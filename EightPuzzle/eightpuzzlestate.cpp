#include "eightpuzzlestate.h"

EightPuzzle::EightPuzzleState::EightPuzzleState(EightPuzzleId* id, EightPuzzleState* father, EightPuzzleOperator* fatherOperator, int depth, double cost) : State(id, father, fatherOperator, depth, cost)
{
}

EightPuzzle::EightPuzzleState::~EightPuzzleState()
{
}

std::string EightPuzzle::EightPuzzleState::toString()
{
    std::string output = "Id:";
    if (getId() != nullptr)
        output += getId()->toString();
    else
        output += "null";
    output += "|F:";
    if (getFather() != nullptr)
        output += getFather()->getId()->toString();
    else
        output += "null";
    return output + "|D:" + std::to_string(getDepth());
}

std::vector<Operator*> EightPuzzle::EightPuzzleState::getAllowedOperators()
{
    std::pair<int, int> pos = getBlankPiecePos();
    std::vector<Operator*> operatorAllowed;

    Operator* up = new EightPuzzleOperator("up");
    Operator* down = new EightPuzzleOperator("down");
    Operator* left = new EightPuzzleOperator("left");
    Operator* right = new EightPuzzleOperator("right");

    operatorAllowed.push_back(up);
    operatorAllowed.push_back(down);
    operatorAllowed.push_back(left);
    operatorAllowed.push_back(right);

    switch (pos.first) {
    case 0:
        operatorAllowed.erase(std::remove(operatorAllowed.begin(), operatorAllowed.end(), up), operatorAllowed.end());
        break;
    case 2:
        operatorAllowed.erase(std::remove(operatorAllowed.begin(), operatorAllowed.end(), down), operatorAllowed.end());
        break;
    default:
        break;
    }

    switch (pos.second) {
    case 0:
        operatorAllowed.erase(std::remove(operatorAllowed.begin(), operatorAllowed.end(), left), operatorAllowed.end());
        break;
    case 2:
        operatorAllowed.erase(std::remove(operatorAllowed.begin(), operatorAllowed.end(), right), operatorAllowed.end());
        break;
    default:
        break;
    }

    return operatorAllowed;
}

void EightPuzzle::EightPuzzleState::genHeuristic()
{
    std::string goalState = "12345678x";
    int heuristicValue = 0;

    for (int var = 0; var < 9; ++var)
    {
        std::string currentPiece = ((EightPuzzleId*)getId())->getIdValue().substr(var,1);
        std::pair<int, int> currentPos = getNumberPiecePos(currentPiece, ((EightPuzzleId*)getId())->getIdValue());
        std::pair<int, int> goalPos = getNumberPiecePos(currentPiece, goalState);

        if (currentPos.first != goalPos.first || currentPos.second != goalPos.second)
            heuristicValue += 1;
    }

    _heuristic = heuristicValue;
}

std::vector<State*> EightPuzzle::EightPuzzleState::genChilds(std::vector<Operator*> allowedOperators, Frontier *frontier)
{
    std::vector<State*> childs;

    for (int var = 0; var < allowedOperators.size(); ++var) {

        Operator* side = allowedOperators[var];

        State* child = new EightPuzzleState((EightPuzzleId*)applyOperator(side), this, (EightPuzzleOperator*)side, getDepth() + 1, getCost() + 1);

        bool existInFrontier = false;

        for (State* s : frontier->getVisitedStates())
        {
            if (child->equal(s))
            {
                existInFrontier = true;
                break;
            }
        }

        if (!existInFrontier)
        {
            childs.push_back(child);
        }
    }

    return childs;
}

std::pair<int, int> EightPuzzle::EightPuzzleState::getNumberPiecePos(std::string piece, std::string state)
{
    std::size_t pos = state.find(piece);
    int row = pos / 3;
    int col = pos % 3;

    return std::pair<int, int>(row, col);
}

std::pair<int, int> EightPuzzle::EightPuzzleState::getBlankPiecePos()
{
    std::size_t pos = ((EightPuzzleId*)getId())->getIdValue().find("x");
    int row = pos / 3;
    int col = pos % 3;

    return std::pair<int, int>(row, col);
}

Id* EightPuzzle::EightPuzzleState::applyOperator(Operator* op)
{
    std::string newId = ((EightPuzzleId*)getId())->getIdValue();
    std::pair<int, int> blankPos = getBlankPiecePos();
    std::pair<int, int> numberPos;

    if (((EightPuzzleOperator*)op)->getOperatorValue().compare("up") == 0)
    {
        numberPos = std::pair<int, int>(blankPos.first - 1, blankPos.second);
    }
    else if (((EightPuzzleOperator*)op)->getOperatorValue().compare("down") == 0)
    {
        numberPos = std::pair<int, int>(blankPos.first + 1, blankPos.second);
    }
    else if (((EightPuzzleOperator*)op)->getOperatorValue().compare("left") == 0)
    {
        numberPos = std::pair<int, int>(blankPos.first, blankPos.second - 1);
    }
    else if (((EightPuzzleOperator*)op)->getOperatorValue().compare("right") == 0)
    {
        numberPos = std::pair<int, int>(blankPos.first, blankPos.second + 1);
    }

    std::string letter1 = "";
    std::string letter2 = "";

    letter1 += ((EightPuzzleId*)getId())->getIdValue().at(numberPos.first * 3 + numberPos.second);
    letter2 += ((EightPuzzleId*)getId())->getIdValue().at(blankPos.first * 3 + blankPos.second);

    newId.replace(blankPos.first * 3 + blankPos.second, 1, letter1.c_str());
    newId.replace(numberPos.first * 3 + numberPos.second, 1, letter2.c_str());

    return new EightPuzzleId(newId);
}
