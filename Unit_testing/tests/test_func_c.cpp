#include <gtest/gtest.h>

int private_ok_value = 2;

int func_ok(int a, int b) {
  return a + b == private_ok_value;
}

// Тесты
TEST(FuncOkTest, TestValidSum) {
    // Проверяем, что сумма 1 + 1 == 2
    EXPECT_TRUE(func_ok(1, 1));
}

TEST(FuncOkTest, TestInvalidSum) {
    // Проверяем, что сумма 3 + 3 не равна 2
    EXPECT_FALSE(func_ok(3, 3));
}

TEST(FuncOkTest, TestEdgeCase) {
    // Проверяем, что 0 + 2 == 2
    EXPECT_TRUE(func_ok(0, 2));
}

TEST(FuncOkTest, TestNegativeNumbers) {
    // Проверяем, что -1 + 3 == 2
    EXPECT_TRUE(func_ok(-1, 3));
}

TEST(FuncOkTest, TestLargeNumbers) {
    // Проверяем, что 1000000 + (-999998) == 2
    EXPECT_TRUE(func_ok(1000000, -999998));
}

TEST(FuncOkTest, TestZeroValues) {
    // Проверяем, что 0 + 0 не равно 2
    EXPECT_FALSE(func_ok(0, 0));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
