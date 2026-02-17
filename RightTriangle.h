#pragma once
/**
* @brief Класс "прямоугольный треугольник"
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
     * @brief Расчёт длины описанной окружности
     * @return Рассчитанное значение
     */
    double getLenghtOfRound() const;

    /**
     * @brief Расчёт площади описанного круга
     * @return Рассчитанное значение
     */
    double getSquareOfRound() const;
};
