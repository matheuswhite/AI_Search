#include "eightpuzzlestate.h"

EightPuzzle::EightPuzzleState::EightPuzzleState(std::string id, EightPuzzleState* father, EightPuzzleOperator* fatherOperator, int depth, double cost)
    : State<std::string>(id, father, fatherOperator, depth, cost)
{
}

EightPuzzle::EightPuzzleState::~EightPuzzleState()
{
}

std::string EightPuzzle::EightPuzzleState::toString()
{
    std::string output = "Id:" + getId() + "|F:";
    if (getFather() != nullptr)
        output += getFather()->getId();
    else
        output += "null";
    return output + "|D:" + std::to_string(getDepth());
}

std::vector<Operator<std::string>*> EightPuzzle::EightPuzzleState::getAllowedOperators()
{
    std::pair<int, int> pos = getBlankPiecePos();
    std::vector<Operator<std::string>*> operatorAllowed;

    Operator<std::string>* up = new EightPuzzleOperator(this, "up");
    Operator<std::string>* down = new EightPuzzleOperator(this, "down");
    Operator<std::string>* left = new EightPuzzleOperator(this, "left");
    Operator<std::string>* right = new EightPuzzleOperator(this, "right");

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
        std::string currentPiece = getId().substr(var,1);
        std::pair<int, int> currentPos = getNumberPiecePos(currentPiece, getId());
        std::pair<int, int> goalPos = getNumberPiecePos(currentPiece, goalState);

        if (currentPos.first != goalPos.first || currentPos.second != goalPos.second)
            heuristicValue += 1;
    }

    _heuristic = heuristicValue;
}

std::vector<State<std::string>*> EightPuzzle::EightPuzzleState::genChilds(std::vector<Operator<std::string>*> allowedOperators)
{
    std::vector<State<std::string>*> childs;

    for (int var = 0; var < allowedOperators.size(); ++var)
    {
        EightPuzzleOperator* side = dynamic_cast<EightPuzzleOperator*>(allowedOperators[var]);

        State<std::string>* child = new EightPuzzleState(applyOperator(side), this, side, getDepth() + 1, getCost() + 1);
        side->setTargetState(child);

        childs.push_back(child);
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
    std::size_t pos = getId().find("x");
    int row = pos / 3;
    int col = pos % 3;

    return std::pair<int, int>(row, col);
}

std::string EightPuzzle::EightPuzzleState::applyOperator(EightPuzzleOperator* op)
{
    std::string newId = getId();
    std::pair<int, int> blankPos = getBlankPiecePos();
    std::pair<int, int> numberPos;

    if (op->getValue().compare("up") == 0)
    {
        numberPos = std::pair<int, int>(blankPos.first - 1, blankPos.second);
    }
    else if (op->getValue().compare("down") == 0)
    {
        numberPos = std::pair<int, int>(blankPos.first + 1, blankPos.second);
    }
    else if (op->getValue().compare("left") == 0)
    {
        numberPos = std::pair<int, int>(blankPos.first, blankPos.second - 1);
    }
    else if (op->getValue().compare("right") == 0)
    {
        numberPos = std::pair<int, int>(blankPos.first, blankPos.second + 1);
    }

    std::string letter1 = "";
    std::string letter2 = "";

    letter1 += getId().at(numberPos.first * 3 + numberPos.second);
    letter2 += getId().at(blankPos.first * 3 + blankPos.second);

    newId.replace(blankPos.first * 3 + blankPos.second, 1, letter1.c_str());
    newId.replace(numberPos.first * 3 + numberPos.second, 1, letter2.c_str());

    return newId;
}
