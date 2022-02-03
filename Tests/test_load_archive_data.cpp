#include "log.h"
#include <gtest/gtest.h>

TEST(MARKS, LOAD_DATA)
{
    // Load the archive data
    auto data = load_archive_data();
    EXPECT_TRUE(data);
    EXPECT_EQ(1,1);
}
