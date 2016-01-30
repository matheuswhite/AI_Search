#include "eightpuzzlestate.h"

EightPuzzle::EightPuzzleState::EightPuzzleState(EightPuzzleId id, State* father, EightPuzzleOperator fatherOperator, int depth, double cost) : State(id, father, fatherOperator, depth, cost)
{
}

EightPuzzle::EightPuzzleState::~EightPuzzleState()
{
}

bool EightPuzzle::EightPuzzleState::isFinal()
{
    return getId().compare("12345678x") == 0;
}

std::vector<EightPuzzleOperator> EightPuzzle::EightPuzzleState::getAllowedOperators()
{
    std::pair<int, int> pos = getBlankPiecePos();
    std::vector<std::string> operatorAllowed;

    operatorAllowed.push_back("up");
    operatorAllowed.push_back("down");
    operatorAllowed.push_back("left");
    operatorAllowed.push_back("right");

    switch (pos.first) {
    case 0:
        operatorAllowed.erase(std::remove(operatorAllowed.begin(), operatorAllowed.end(), "up"), operatorAllowed.end());
        break;
    case 2:
        operatorAllowed.erase(std::remove(operatorAllowed.begin(), operatorAllowed.end(), "down"), operatorAllowed.end());
        break;
    default:
        break;
    }

    switch (pos.second) {
    case 0:
        operatorAllowed.erase(std::remove(operatorAllowed.begin(), operatorAllowed.end(), "left"), operatorAllowed.end());
        break;
    case 2:
        operatorAllowed.erase(std::remove(operatorAllowed.begin(), operatorAllowed.end(), "right"), operatorAllowed.end());
        break;
    default:
        break;
    }

    return operatorAllowed;
}

std::vector<State*> EightPuzzle::EightPuzzleState::genChilds(std::vector<EightPuzzleOperator> allowedOperators)
{
    std::vector<State<std::string, std::string>*> childs;

    for (int var = 0; var < allowedOperators.size(); ++var) {

        std::string side = allowedOperators[var];

        State<std::string, std::string>* child = new EightPuzzleState(applyOperator(side), this, side, getDepth() + 1, getCost() + 1);

        childs.push_back(child);
    }

    return childs;
}

std::pair<int, int> EightPuzzle::EightPuzzleState::getBlankPiecePos()
{
    std::size_t pos = getId().find("x");
    int row = pos / 3;
    int col = pos % 3;
    return std::pair<int, int>(row, col);
}

EightPuzzleId* EightPuzzle::EightPuzzleState::applyOperator(EightPuzzleOperator op)
{
    std::string newId = getId();
    std::pair<int, int> blankPos = getBlankPiecePos();
    std::pair<int, int> numberPos;

    if (op.compare("up") == 0)
    {
        numberPos = std::pair<int, int>(blankPos.first - 1, blankPos.second);
    }
    else if (op.compare("down") == 0)
    {
        numberPos = std::pair<int, int>(blankPos.first + 1, blankPos.second);
    }
    else if (op.compare("left") == 0)
    {
        numberPos = std::pair<int, int>(blankPos.first, blankPos.second - 1);
    }
    else if (op.compare("right") == 0)
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
