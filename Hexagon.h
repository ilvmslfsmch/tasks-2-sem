#pragma once
#include "Polygon.h"
#include "Point.h"

/**
 * @brief Класс Hexagon (правильный многоугольник)
 */
class Hexagon:public Polygon {
private:
    Point p1, p2, p3, p4, p5, p6;
    double side;
    static const double EPS;
    public:

    /**
     * @brief конструктор по умолчанию
     */
    Hexagon();

    /**
     * @brief Конструктор для построения правильного шестиугольника через точки Point
     * @param v1 первая точка
     * @param v2 вторая точка
     * @param v3 третья точка
     * @param v4 четвёртая точка
     * @param v5 пятая точка
     * @param v6 шестая точка
     */
    Hexagon(const Point v1, const Point v2, const Point v3, const Point v4, const Point v5, const Point v6);

    /**
     * @brief Конструктор для построения правильного шестиугольника через координаты
     * @param x1 абсцисса первой точки
     * @param y1 ордината первой точки
     * @param x2 абсцисса второй точки
     * @param y2 ордината второй точки
     * @param x3 абсцисса третьей точки
     * @param y3 ордината третьей точки
     * @param x4 абсцисса четвёртой точки
     * @param y4 ордината четвёртой точки
     * @param x5 абсцисса пятой точки
     * @param y5 ордината пятой точке
     * @param x6 абсцисса шестой точки
     * @param y6 ордината шестой точки
     */
    Hexagon(const double x1, const double y1, const double x2, const double y2,
            const double x3, const double y3, const double x4, const double y4,
            const double x5, const double y5, const double x6, constdouble y6);

    /**
     * @brief Функция рассчёта площади правильного шестиугольника
     * @return Рассчитанное значение
     */
    double getArea() const override;

    /**
     * @brief Функция рассчёта периметра правильного шестиугольника
     * @return Рассчитанное значение
     */
    double getPerimeter() const override;

    /**
     * @brief Функция расчёта радиуса описанной вокруг правильного шестиугольника окружности
     * @return Рассчитанное значение
     */
    double getRadius() const override;

    /**
     * @brief Метод сериализации в строку toString
     * @return Сериализованная строка
     */
    std::string toString() const override;

    /**
     * @brief Метод чтения из стандартного потока ввода
     * @param is входной поток
     */
    void Read(std::istream& is) override;
};
