#include <gtest/gtest.h>
#include "Hexagon.h"
#include "Point.h"
#include <string>
#include <sstream>

Hexagon CreateValidHex() {
    return Hexagon(2.0, 0.0,
                   1.0, 1.7320508075688772,
                   -1.0, 1.7320508075688772,
                   -2.0, 0.0,
                   -1.0, -1.7320508075688772,
                   1.0, -1.7320508075688772);
}

TEST(HexagonTest, GeometryMethods) {
    Hexagon h = CreateValidHex();
    EXPECT_NEAR(h.getPerimeter(), 12.0, 0.0001);
    EXPECT_NEAR(h.getArea(), 10.3923, 0.001);
    EXPECT_NEAR(h.getRadius(), 2.0, 0.0001);
}

TEST(HexagonTest, ReadMethod) {
    Hexagon h;

    std::string input = "10.0 0.0  "
                        "5.0 8.660254037844386  "
                        "-5.0 8.660254037844386  "
                        "-10.0 0.0  "
                        "-5.0 -8.660254037844386  "
                        "5.0 -8.660254037844386";
    std::stringstream ss(input);

    ASSERT_NO_THROW(h.Read(ss));

    EXPECT_NEAR(h.getPerimeter(), 60.0, 0.001);
    EXPECT_NEAR(h.getRadius(), 10.0, 0.001);
}

TEST(HexagonTest, OutputMethods) {
    Hexagon h = CreateValidHex();
    std::string out = h.toString();

    EXPECT_FALSE(out.empty());
    EXPECT_TRUE(out.find("Hexagon") != std::string::npos || out.find("Шестиугольник") != std::string::npos);

    std::stringstream ss;
    ss << h;
    EXPECT_EQ(ss.str(), h.toString());
}

TEST(HexagonTest, ValidationExceptions) {
    EXPECT_THROW({
        Hexagon h(0,0, 0,0, 0,0, 0,0, 0,0, 0,0);
    }, std::invalid_argument);

    EXPECT_THROW({
        Hexagon h(10,0, 1,1, 2,2, 3,3, 4,4, 5,5);
    }, std::invalid_argument);
}

TEST(PointTest, StreamOperators) {
    Point p;
    std::stringstream ss("10.5 20.0");
    ss >> p;
    EXPECT_DOUBLE_EQ(p.getX(), 10.5);
    EXPECT_DOUBLE_EQ(p.getY(), 20.0);

    std::stringstream os;
    os << p;
    EXPECT_TRUE(os.str().find("10.5") != std::string::npos);
}