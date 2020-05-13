#include "tst_test1.h"
#include "fibonachi_test.h"
#include "tst_stdout.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
