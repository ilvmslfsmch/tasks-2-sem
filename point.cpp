#include <iostream>
#include <cmath>
#include "Point.h"
#include <limits>

using namespace std;

const double Point::EPS = numeric_limits<double>::epsilon() * 1e7;

Point::Point(const double x, const double y): x(x), y(y) {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

bool Point::operator==(const Point& p) const {
    return abs(x - p.x) <= EPS &&
           abs(y - p.y) <= EPS;
}

bool Point::operator!=(const Point& p) const {
    return !(*this == p);
}
