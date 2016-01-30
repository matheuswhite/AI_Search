#include "eightpuzzlestate.h"

EightPuzzle::EightPuzzleState::EightPuzzleState(EightPuzzleId* id, EightPuzzleState* father, EightPuzzleOperator* fatherOperator, int depth, double cost) : State(id, father, fatherOperator, depth, cost)
{
}

EightPuzzle::EightPuzzleState::~EightPuzzleState()
{
}

bool EightPuzzle::EightPuzzleState::isFinal()
{
    return ((EightPuzzleId*)getId())->getIdValue().compare("12345678x") == 0;
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

    for (Operator* var : operatorAllowed) {
        std::cout << "|" << ((EightPuzzleOperator*)var)->getOperatorValue() << "|";
    }
    std::cout << std::endl;

    return operatorAllowed;
}

std::vector<State*> EightPuzzle::EightPuzzleState::genChilds(std::vector<Operator*> allowedOperators)
{
    std::vector<State*> childs;

    for (int var = 0; var < allowedOperators.size(); ++var) {

        Operator* side = allowedOperators[var];

        childs.push_back(new EightPuzzleState((EightPuzzleId*)applyOperator(side), this, (EightPuzzleOperator*)side, getDepth() + 1, getCost() + 1));
    }

    return childs;
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
