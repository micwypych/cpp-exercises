//
// Created by mwypych on 21.03.17.
//


#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <memory>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <StringUtility.h>
#include <Name.h>

using ::model::Name;
using ::std::make_unique;
using ::utility::FromString;
using ::std::tuple;
using ::std::pair;
using ::std::vector;
using ::std::map;
using ::std::string;

using TestArgument = string;
using TestExpected = map<string, string>;
using TestParam = pair<TestArgument, TestExpected>;

class NameTests : public ::testing::TestWithParam<TestParam>, MemLeakTest {
};

TEST_P(NameTests, ProperSquares) {
  auto param = GetParam();
  auto name = param.first;
  auto expected = param.second;

  Name name_under_test {name};
  EXPECT_EQ(expected["1st name"], name_under_test.FirstName());
  if (expected.find("2nd name") != expected.end()) {
    EXPECT_EQ(expected["2nd name"], name_under_test.SecondName().value());
  } else {
    EXPECT_FALSE(name_under_test.SecondName());
  }
  if (expected.find("3rd name") != expected.end()) {
    EXPECT_EQ(expected["3rd name"], name_under_test.ThirdName().value());
  } else {
    EXPECT_FALSE(name_under_test.ThirdName());
  }
  EXPECT_EQ(expected["last name"], name_under_test.Surname());
  EXPECT_EQ(expected["full name initials"], name_under_test.ToFullInitials());
  EXPECT_EQ(expected["first names initials"], name_under_test.ToFirstNamesInitials());
  EXPECT_EQ(expected["surname names"], name_under_test.ToSurnameNames());
  EXPECT_EQ(expected["names surname"], name_under_test.ToNamesSurname());
}

TEST(NameTests, test_IsBeforeBySurname) {
  Name aaa {"A B C AAA"};
  Name zzz {"X Y Z ZZZ"};

  EXPECT_TRUE(aaa.IsBeforeBySurname(zzz));
  EXPECT_FALSE(zzz.IsBeforeBySurname(aaa));
}

TEST(NameTests, test_IsBeforeByName) {
  Name aaa {"A B C AAA"};
  Name zzz {"X Y Z ZZZ"};

  EXPECT_TRUE(aaa.IsBeforeByFirstName(zzz));
  EXPECT_FALSE(zzz.IsBeforeByFirstName(aaa));
}

std::vector<TestParam> nameTestData{
    {"John Ronald Reuel Tolkien",
        {{"1st name","John"},
         {"2nd name","Ronald"},
         {"3rd name", "Reuel"},
         {"last name", "Tolkien"},
         {"full name initials", "J. R. R. T."},
         {"first names initials", "J. R. R. Tolkien"},
         {"surname names", "Tolkien John Ronald Reuel"},
         {"names surname", "John Ronald Reuel Tolkien"}}},
    {"Thomas\tJorge   Djelly\t\n\r \tCucumber",
     {{"1st name","Thomas"},
      {"2nd name","Jorge"},
      {"3rd name", "Djelly"},
      {"last name", "Cucumber"},
      {"full name initials", "T. J. D. C."},
      {"first names initials", "T. J. D. Cucumber"},
      {"surname names", "Cucumber Thomas Jorge Djelly"},
      {"names surname", "Thomas Jorge Djelly Cucumber"}}},
    {"Just\t\t\n\r \tSurname",
     {{"1st name","Just"},
      {"last name", "Surname"},
      {"full name initials", "J. S."},
      {"first names initials", "J. Surname"},
      {"surname names", "Surname Just"},
      {"names surname", "Just Surname"}}},
    {"First\t\tAndSecond\n\r \tSurname",
     {{"1st name","First"},
      {"2nd name","AndSecond"},
      {"last name", "Surname"},
      {"full name initials", "F. A. S."},
      {"first names initials", "F. A. Surname"},
      {"surname names", "Surname First AndSecond"},
      {"names surname", "First AndSecond Surname"}}},
    {"First\t\tAndSecond\n\r \tSurname-With-Dash",
     {{"1st name","First"},
      {"2nd name","AndSecond"},
      {"last name", "Surname-With-Dash"},
      {"full name initials", "F. A. S."},
      {"first names initials", "F. A. Surname-With-Dash"},
      {"surname names", "Surname-With-Dash First AndSecond"},
      {"names surname", "First AndSecond Surname-With-Dash"}}},
};

INSTANTIATE_TEST_CASE_P(NameTestsFixture,
                        NameTests,
                        ::testing::ValuesIn(nameTestData));