#include <iostream>
#include "Hexagon.h"
#include "Point.h"

using namespace std;

/**
 * @brief BY_POINTS - ввод координат через точки, BY_COORDINATES - через координаты (x1 y1 x2 y2 ...)
 */
enum {BY_POINTS = 1, BY_COORDINATES};

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1.
 */
int main () {
    int choice;
    cout << "Select input method: by points - " << BY_POINTS << ", by coordinates - " << BY_COORDINATES << "." << endl;
    cin >> choice;

    Hexagon hex;

    switch (choice) {
        case BY_POINTS: {
            Point p1, p2, p3, p4, p5, p6;
            cout << "Enter 6 points (x y x y ...):" << endl;
            cin >> p1 >> p2 >> p3 >> p4 >> p5 >> p6;
            hex = Hexagon(p1, p2, p3, p4, p5, p6);
            break;
        }
            case BY_COORDINATES: {
            double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
            cout << "Enter 12 coordinates (x1 y1 x2 y2 ...):" << endl;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
            hex = Hexagon(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6);
            break;
        }
            default:
            cout << "Error. Invalid choice." << endl;
            return 1;
    }
    cout << hex << endl;
    cout << "Area: " << hex.getArea() << endl;
    cout << "Perimeter: " << hex.getPerimeter() << endl;
    cout << "Radius:" << hex.getRadius() << endl;

    }
    return 0;
}
