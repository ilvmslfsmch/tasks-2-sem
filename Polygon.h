#pragma once

/**
 * @brief Абстрактный класс Polygon (правильный многоугольник)
 */
class Polygon {
    public:

    /**
     * @brief Виртуальный (абстрактный) метод сериализации в строку toString
     * @return Сериализованная строка
     */
    virtual std::string toString() const = 0;

    /**
     * @brief Виртуальный метод рассчёта площади правильного многоугольника
     * @return Расчитанное значение
     */
    virtual double getArea() const = 0;

    /**
     * @brief Виртуальный метод рассчёта периметра правильного многоугольника
     * @return Рассчитанное значение
     */
    virtual double getPerimeter() const = 0;

    /**
     * @brief Виртуальный метод расчёта радиуса описанной вокруг правильного многоугольника окружности
     * @return Рассчитанное значение
     */
    virtual double getRadius() const = 0;

    /**
     * @brief Виртуальный деструктор объекта "правильный многоугольник"
     */
    virtual ~Polygon() = default;

    /**
     * @brief Виртуальная функция чтения из стандартного потока ввода
     * @param is входной поток
     */
    virtual void Read(std::istream& is) = 0;

    /**
     * @brief Перегрузка (переопределение) оператора вывода
     * @param os поток вывода
     * @param p объект класса Polygon
     * @return переопределённый поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Polygon& p) {
        os << p.toString();
        return os;
    }

    /**
     * @brief Перегрузка (переопределение) оператора ввода
     * @param is входной поток
     * @param p объект класса Polygon
     * @return переопределённый входной поток
     */
    friend std::istream& operator>>(std::istream& is, Polygon& p) {
        p.Read(is);
        return is;
    }
};