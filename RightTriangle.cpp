#include <iostream>
#include <cmath>
#include "RightTriangle.h"

RightTriangle::RightTriangle(const double side1, const double side2) {
    if (side1 <= 0 || side2 <= 0) {
        std::cout<<"Error. Sides must be positive."<<std::endl;
        exit(1);
    }
    this->side1 = side1;
    this->side2 = side2;
}

double RightTriangle::getRadius() const {
    return sqrt(pow(side1, 2) + pow(side2, 2))/2;
}

double RightTriangle::getLenghtOfRound() const {
    double r = getRadius();
    return 2 * M_PI * r;
}

double RightTriangle::getSquareOfRound() const {
    double r = getRadius();
    return M_PI * pow(r, 2);
}