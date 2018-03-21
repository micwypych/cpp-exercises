//
// Created by mwypych on 10.03.18.
//

#include <gtest/gtest.h>
#include <ExampleLibrary.h>

TEST(examplelibrary_test, addition_of_4_and_5_is_10) {
  EXPECT_EQ(10, ExampleAddition(4, 5));
}

TEST(examplelibrary_test, addition_of_negative901_and_900_is_0) {
  EXPECT_EQ(0, ExampleAddition(-901, 900));
}

TEST(examplelibrary_test, addition_of_9132_and_871_is_) {
  EXPECT_EQ(9950, ExampleAddition(9132, 817));
}

TEST(examplelibrary_test, concatenation_of_empty_strings_gives_just_space) {
  EXPECT_EQ(" ", ExampleConcatenation("", ""));
}

TEST(examplelibrary_test, concatenation_of_different_strings_returns_those_strings_separted_with_space) {
  EXPECT_EQ("abc efgh", ExampleConcatenation("abc", "efgh"));
}