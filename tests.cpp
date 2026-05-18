#include <gtest/gtest.h>
#include "Array.h"

TEST(VectorTest, DefaultConstructor) {
    vector v;
    EXPECT_EQ(v.getSize(), 0);
    EXPECT_TRUE(v.isEmpty());
    EXPECT_EQ(v.toString(), "Empty");
}

TEST(VectorTest, InitializerListConstructor) {
    vector v = {1, 2, 3};
    EXPECT_EQ(v.getSize(), 3);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
}

TEST(VectorTest, CopyConstructor) {
    vector v1 = {1, 2, 3};
    vector v2 = v1;
    EXPECT_EQ(v2.toString(), v1.toString());
    v2[0] = 99;
    EXPECT_NE(v2[0], v1[0]);
}

TEST(VectorTest, CopyAssignment) {
    vector v1 = {1, 2, 3};
    vector v2;
    v2 = v1;
    EXPECT_EQ(v2.toString(), v1.toString());
    v2[0] = 99;
    EXPECT_NE(v2[0], v1[0]);
}

TEST(VectorTest, SelfAssignment) {
    vector v = {1, 2, 3};
    v = v;
    EXPECT_EQ(v.toString(), "1 2 3");
}

TEST(VectorTest, EqualityOperators) {
    vector v1 = {1, 2, 3};
    vector v2 = {1, 2, 3};
    vector v3 = {1, 2, 4};
    EXPECT_TRUE(v1 == v2);
    EXPECT_TRUE(v1 != v3);
}

TEST(VectorTest, OperatorIndex) {
    vector v = {10, 20, 30};
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v[2], 30);
}

TEST(VectorTest, OperatorIndexWrite) {
    vector v = {1, 2, 3};
    v[1] = 99;
    EXPECT_EQ(v[1], 99);
}

TEST(VectorTest, PushAtBegin) {
    vector v = {1, 2, 3};
    v.push(0, 99);
    EXPECT_EQ(v.toString(), "99 1 2 3");
}

TEST(VectorTest, PushAtEnd) {
    vector v = {1, 2, 3};
    v.push(v.getSize(), 99);
    EXPECT_EQ(v.toString(), "1 2 3 99");
}

TEST(VectorTest, PopAtMiddle) {
    vector v = {1, 2, 3};
    v.pop(1);
    EXPECT_EQ(v.toString(), "1 3");
}

TEST(VectorTest, PopUntilEmpty) {
    vector v = {1};
    v.pop(0);
    EXPECT_TRUE(v.isEmpty());
    EXPECT_EQ(v.toString(), "Empty");
}

TEST(VectorTest, ReplaceElement) {
    vector v = {1, 2, 3};
    v.replace(1, 42);
    EXPECT_EQ(v[1], 42);
    EXPECT_EQ(v.getSize(), 3);
}
