#include <iostream>
#include <cmath>

/**
 * @brief Класс треугольник
 */
class RightTriangle {
private:
    /**
     * @brief Первый катет треугольника
     */
    double side1;

    /**
     * @brief Второй катет треугольника
     */
    double side2;

public:
    /**
     * @brief Конструктор
     * @param side1 первый катет треугольника
     * @param side2 второй катет треугольника
     */
    RightTriangle(const double side1, const double side2);

    /**
     * @brief Расчёт радиуса описанной окружности
     * @return Рассчитанное значение
     * @note Вокруг любого прямоугольного треугольника можно описать окружность. Диаметр этой окружности -
     * гипотенуза треугольника, следовательно, радиус - гипотенуза пополам. Гипотенуза ищется по теореме Пифагора.
     */
    double getRadius() const;

    /**
     * @brief Расчёт периметра описанной окружности
     * @return Рассчитанное значение
     */
    double getPerimeterOfRound() const;

    /**
     * @brief Расчёт площади описанного круга
     * @return Рассчитанное значение
     */
    double getSquareOfRound() const;
};

/**
 * @brief Считывает катет треугольника с клавиатуры
 * @param reports - строка информации
 * @return 1 при ошибке ввода; при корректном вводе - считанное значение
 * @note Так как дано, что треугольник прямоугольный, проверять правило треугольника не требуется, остаётся проверить
 * только полученные значения на положительность и на то, что введены числа, а не буквы/иное
 */
double getSide(std::string reports = "");

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main() {
    double side1 = getSide("Enter first side of right triangle:");
    double side2 = getSide("Enter last side of right triangle:");
    RightTriangle newTriangle(side1, side2);
    std::cout<<"Perimeter of circumscribed round is "<<newTriangle.getPerimeterOfRound()<<std::endl;
    std::cout<<"Square of circumscribed round is "<<newTriangle.getSquareOfRound()<<std::endl;
    return 0;
}

double getSide(std::string report) {
    std::cout << report << std::endl;
    double side = 0;
    std::cin >> side;
    if (std::cin.fail()) {
        std::cout<<"Error. You must insert only numbers."<<std::endl;
        exit(1);
    }
    return side;
}

RightTriangle::RightTriangle(const double side1, const double side2) {
    if (side1 <= 0 || side2 <= 0) {
        std::cout<<"Error. Sides must be positive\n"<<std::endl;
        exit(1);
    }
    this->side1 = side1;
    this->side2 = side2;
}

double RightTriangle::getRadius() const {
    return sqrt(pow(side1, 2) + pow(side2, 2))/2;
}

double RightTriangle::getPerimeterOfRound() const {
    double r = getRadius();
    return 2 * M_PI * r;
}

double RightTriangle::getSquareOfRound() const {
    double r = getRadius();
    return M_PI * pow(r, 2);
}
