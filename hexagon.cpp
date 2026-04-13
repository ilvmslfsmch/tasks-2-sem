#include <cfloat>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "Hexagon.h"
#include "Point.h"
#include <limits>

using namespace std;

const double EPS = numeric_limits<double>::epsilon() * 1e7;

Hexagon::Hexagon(Point v1, Point v2, Point v3, Point v4, Point v5, Point v6)
    : p1(v1), p2(v2), p3(v3), p4(v4), p5(v5), p6(v6) {
    side = hypot(p2.getX() - p1.getX(), p2.getY() - p1.getY());

    if (abs(side) <= EPS) {
        throw invalid_argument("Side must be more than 0.");
    }

    if (abs(hypot(p3.getX() - p2.getX(), p3.getY() - p2.getY()) - side) > EPS ||
        abs(hypot(p4.getX() - p3.getX(), p4.getY() - p3.getY()) - side) > EPS ||
        abs(hypot(p5.getX() - p4.getX(), p5.getY() - p4.getY()) - side) > EPS ||
        abs(hypot(p6.getX() - p5.getX(), p6.getY() - p5.getY()) - side) > EPS ||
        abs(hypot(p1.getX() - p6.getX(), p1.getY() - p6.getY()) - side) > EPS) {
        throw invalid_argument("All sides must be equal.");
    }

    if (abs(hypot(p4.getX() - p1.getX(), p4.getY() - p1.getY()) - 2 * side) > EPS ||
        abs(hypot(p5.getX() - p2.getX(), p5.getY() - p2.getY()) - 2 * side) > EPS ||
        abs(hypot(p6.getX() - p3.getX(), p6.getY() - p3.getY()) - 2 * side) > EPS) {
        throw invalid_argument("Main diagonals must be equal to 2 * side.");
    }
}

Hexagon::Hexagon(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4,
    double x5, double y5, double x6, double y6)
    : Hexagon(Point(x1, y1), Point(x2, y2),
        Point(x3, y3), Point(x4, y4),
        Point(x5, y5), Point(x6, y6)) {}

double Hexagon::getArea() const {
    return 3.0 * sqrt(3.0) / 2.0 * pow(side, 2.0);
}

double Hexagon::getPerimeter() const {
    return 6.0 * side;
}

double Hexagon::getRadius() const {
    return side;
}

string Hexagon::toString() const {
    stringstream ss;
    ss << fixed << setprecision(2);
    ss << "Hexagon (side: " << side << "); Points: " <<
        p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << " " << p6;
    return ss.str();
}

void Hexagon::Read(istream& is) {
    Point v1, v2, v3, v4, v5, v6;
    if (is >> v1 >> v2 >> v3 >> v4 >> v5 >> v6) {
        *this = Hexagon(v1, v2, v3, v4, v5, v6);
    }
}