#pragma once
#include <iostream>

/**
 * @brief Класс Point (точка)
 */
class Point {
private:
    double x;
    double y;
    static const double EPS;
public:
    /**
     * @brief Конструктор для класса Point
     * @param x абсцисса точки Point
     * @param y ордината точки Point
     */
    Point(const double x = 0, const double y = 0);

    /**
     * @brief Функция ввода абсциссы точки
     * @return Считанное значение
     */
    double getX() const;

    /**
     * @brief Функция ввода ординаты точки
     * @return Считанное значение
     */
    double getY() const;

    /**
     * @brief Переопределение оператора вывода ("сдвиг влево")
     * @param os поток вывода
     * @param p объект класса Point
     * @return Переопределённый поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    /**
     * @brief Переопределение оператора ввода ("сдвиг вправо")
     * @param is входной поток
     * @param p объект класса Point
     * @return Переопределённый входной поток
     */
    friend std::istream& operator>>(std::istream& is, Point& p);

    /**
     * @brief Переопределение оператора сравнения (равенство)
     * @param p объект класса Point
     * @return Возвращает true, если равенство выполнено, иначе false
     */
    bool operator==(const Point& p) const;

    /**
     * @brief Переопределение оператора сравнения (неравенство)
     * @param p объект класса Point
     * @return Возвращает true, если равенство не выполнено, иначе false
     */
    bool operator!=(const Point& p) const;
};
