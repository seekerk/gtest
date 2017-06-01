#ifndef FIBONACHI_H
#define FIBONACHI_H

#include <gtest/gtest.h>

extern "C" {
#include "myfunc.h"
}

TEST(fibonachiTest, num0) {
    ASSERT_EQ(fibonachi(0), 0);
    ASSERT_EQ(fibonachi(1), 1);
    ASSERT_EQ(fibonachi(2), 2);
}

TEST(fibonachiTest, greather2) {
    ASSERT_EQ(fibonachi(5), 1 + 1 + 2 + 3 + 5);
    ASSERT_EQ(fibonachi(10), 1 + 1 + 2 + 3 + 5 + 8 + 13 + 21 + 34 + 55);
}

TEST(fibonachiTest, negative) {
    ASSERT_EQ(fibonachi(-1), 0);
}

#endif // FIBONACHI_H
