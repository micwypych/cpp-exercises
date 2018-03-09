//
// Created by mwypych on 25.05.17.
//

#include <vector>
#include <gtest/gtest.h>
#include <MemLeakTest.h>
#include <Tree.h>

using ::tree::Tree;

class DummyTreeDataType {
 public:
  bool operator<(const DummyTreeDataType &other) const {
    return true;
  }
};

class TreeTest : public ::testing::Test, MemLeakTest {
 public:
};

TEST_F(TreeTest, CanCreateTreeOfInts) {
  Tree<int> tree;
}

TEST_F(TreeTest, CanCreateTreeOfDoubles) {
  Tree<double> tree;
}

TEST_F(TreeTest, CanCreateTreeOfArbitraryType) {
  Tree<DummyTreeDataType> tree;
}

TEST_F(TreeTest, CanInsertSingleValueIntoTree) {
  Tree<int> tree {5};
  auto value = tree.Value();
  EXPECT_EQ(5, value);
  EXPECT_EQ(1, tree.Size());
  EXPECT_EQ(1, tree.Depth());
}

TEST_F(TreeTest, CanInsertMoreValuesIntoTree) {
  Tree<int> tree {5};
  auto value = tree.Value();
  EXPECT_EQ(5, value);
  EXPECT_EQ(1, tree.Size());
  EXPECT_EQ(1, tree.Depth());
  tree.Insert(0);
  value = tree.Value();
  EXPECT_EQ(5, value);
  EXPECT_EQ(2, tree.Size());
  EXPECT_EQ(2, tree.Depth());
  tree.Insert(102);
  value = tree.Value();
  EXPECT_EQ(5, value);
  EXPECT_EQ(3, tree.Size());
  EXPECT_EQ(2, tree.Depth());
  tree.Insert(890);
  value = tree.Value();
  EXPECT_EQ(5, value);
  EXPECT_EQ(4, tree.Size());
  EXPECT_EQ(3, tree.Depth());
  tree.Insert(81);
  value = tree.Value();
  EXPECT_EQ(5, value);
  EXPECT_EQ(5, tree.Size());
  EXPECT_EQ(3, tree.Depth());
  tree.Insert(-1);
  value = tree.Value();
  EXPECT_EQ(5, value);
  EXPECT_EQ(6, tree.Size());
  EXPECT_EQ(3, tree.Depth());
}