#include "log.h"
#include <gtest/gtest.h>

TEST(MARKS, LOAD_DATA) {
    // Load the archive data
    auto data = load_archive_data ();
    EXPECT_TRUE(data);

}

TEST(MARKS, PASSWORD){
    Set_Password("InewDeveloper");
    EXPECT_EQ(Get_Password(), "InewDeveloper");
}

TEST(MARKS, CheckPassword ){
    Set_Password("InewDeveloper");
    EXPECT_TRUE(Check_Password("InewDeveloper"));
    EXPECT_FALSE(Check_Password("InewDeveloper1"));

}