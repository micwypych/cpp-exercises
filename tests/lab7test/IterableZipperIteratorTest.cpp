//
// Created by mwypych on 21.04.18.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <memory>
#include <MemLeakTest.h>
#include <Iterable.h>

using ::utility::Zipper;
using ::utility::ZipperIterator;
using ::utility::IterableIterator;
using ::std::vector;
using ::std::string;
using ::std::make_unique;


class IterableTests : public ::testing::Test, MemLeakTest {
 public:
};

TEST_F(IterableTests, ImplementsZipperIterator) {
  vector<int> vi {4, 77, -91};
  vector<string> vs {"4", "9991", "adfskld"};
  auto it = ZipperIterator(vi.begin(),vs.begin(), vi.end(), vs.end());
  auto expected_pair = std::make_pair<int,std::string>(4,"4");
  EXPECT_EQ(expected_pair, it.Dereference());
  std::unique_ptr<IterableIterator> next_it = make_unique<ZipperIterator>(vi.begin()+1,vs.begin()+1, vi.end(), vs.end());
  EXPECT_TRUE( it.NotEquals(next_it));
  EXPECT_FALSE(it.Next().NotEquals(next_it));
}
