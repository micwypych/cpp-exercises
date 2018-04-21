//
// Created by mwypych on 21.04.17.
//

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <memory>
#include <MemLeakTest.h>
#include <Iterable.h>

using ::utility::Product;
using ::std::vector;
using ::std::string;
using ::std::pair;


class IterableProductTests : public ::testing::Test, MemLeakTest {
public:
};

TEST_F(IterableProductTests, ProductOfIntAndStringList) {
    const vector<int> vi {7, -3};
    const vector<string> vs {"4", "9991", "adfskld"};
    vector<pair<int,string>> expected {{7, "4"}, {7, "9991"}, {7, "adfskld"},{-3, "4"}, {-3, "9991"}, {-3, "adfskld"}};

    int i = 0;
    for (const auto &p : Product(vi, vs)) {
        EXPECT_EQ(expected[i], p);
        i++;
    }
    EXPECT_EQ(expected.size(), i);
}

TEST_F(IterableProductTests, ProductOfEmptyList) {
    const vector<int> vi {};
    const vector<string> vs {};
    const vector<pair<int,string>> expected {};

    int i = 0;
    for (const auto &p : Product(vi, vs)) {
        EXPECT_EQ(expected[i].first, p.first);
        EXPECT_EQ(expected[i].second, p.second);
        i++;
    }
}

