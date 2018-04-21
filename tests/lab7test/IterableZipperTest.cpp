//
// Created by mwypych on 20.04.17.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <memory>
#include <MemLeakTest.h>
#include <Iterable.h>

using ::utility::Zipper;
using ::std::vector;
using ::std::string;


class IterableZipperTests : public ::testing::Test, MemLeakTest {
 public:
};

TEST_F(IterableZipperTests, ZipperHasCBeginCEndMethods) {
  const vector<int> vi {8, 12, 103};
  const vector<string> vs {"kolo", "zadanie", "egzamin"};

  int i = 0;
  const auto zipped = Zipper(vi,vs);
  for (auto p = zipped.cbegin(); p!=zipped.cend(); ++p) {
    EXPECT_EQ(vi[i], (*p).first);
    EXPECT_EQ(vs[i], (*p).second);
    i++;
  }
}

TEST_F(IterableZipperTests, ZipperHasBeginEndMethods) {
  const vector<int> vi {1, 3, 10, -911, -901, 551117272};
  const vector<string> vs {"strumien", "siadmosci", "typowy", "dla", "duzego", "zmeczenia"};

  int i = 0;
  const auto zipped = Zipper(vi,vs);
  for (auto p = zipped.begin(); p!=zipped.end(); ++p) {
    EXPECT_EQ(vi[i], (*p).first);
    EXPECT_EQ(vs[i], (*p).second);
    i++;
  }
}

TEST_F(IterableZipperTests, ZipEqualLenghtLists) {
  const vector<int> vi {4, 77, -91};
  const vector<string> vs {"4", "9991", "adfskld"};

  int i = 0;
  for (const auto &p : Zipper(vi, vs)) {
    EXPECT_EQ(vi[i], p.first);
    EXPECT_EQ(vs[i], p.second);
    i++;
  }
}

TEST_F(IterableZipperTests, ZipWithLeftListLonger) {
  const vector<int> vi {4, 77, -91, 100, 2000};
  const vector<string> vs {"4", "9991", "adfskld"};
  const vector<string> vs_expected {"4", "9991", "adfskld", "adfskld", "adfskld"};

  int i = 0;
  for (const auto &p : Zipper(vi, vs)) {
    EXPECT_EQ(vi[i], p.first);
    EXPECT_EQ(vs_expected[i], p.second);
    i++;
  }
}

TEST_F(IterableZipperTests, ZipWithRightListLonger) {
  const vector<int> vi {4};
  const vector<string> vs {"4", "9991", "adfskld"};
  const vector<int> vi_expected {4, 4, 4};

  int i = 0;
  for (const auto &p : Zipper(vi, vs)) {
    EXPECT_EQ(vi_expected[i], p.first);
    EXPECT_EQ(vs[i], p.second);
    i++;
  }
}

TEST_F(IterableZipperTests, ZipEmptyLists) {
  const vector<int> vi {};
  const vector<string> vs {};

  int i = 0;
  for (const auto &p : Zipper(vi, vs)) {
    EXPECT_EQ(vi[i], p.first);
    EXPECT_EQ(vs[i], p.second);
    i++;
  }
}

