#include "main.h"
#include <gtest/gtest.h>

TEST(MARKS, LOAD_DATA)
{

    EXPECT_EQ(load_archive_data(), true);
}