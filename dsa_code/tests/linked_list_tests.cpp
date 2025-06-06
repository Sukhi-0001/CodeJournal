#include <climits>
#include <gtest/gtest.h>
#include <linked_list.h>

using namespace std;

TEST(InsertDataTests, Appending) {
  Linked_list list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  EXPECT_EQ(list.get_node(0), INT_MIN);
  EXPECT_EQ(list.get_node(3), 3);
  EXPECT_EQ(list.get_node(6), INT_MIN);
}

TEST(InsertDataTests, InsertAtGivenPostion) {
  Linked_list list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  // 1 -> 2 -> 3
  list.insert(100, 1);
  // 100 -> 1 -> 2 -> 3
  EXPECT_EQ(list.get_node(1), 100);
  EXPECT_EQ(list.get_node(2), 1);
  EXPECT_EQ(list.get_node(3), 2);
  EXPECT_EQ(list.get_node(4), 3);
  EXPECT_EQ(list.get_node(5), INT_MIN);

  list.insert(99, 4);
  // 100 -> 1 -> 2 -> 99 -> 3
  EXPECT_EQ(list.get_node(4), 99);
  list.insert(98, 6);
  // list.display_list();
  EXPECT_EQ(list.get_node(6), 98);

  // EXPECT_EQ(list.get_node(3),98);
}

TEST(FindSizeTests, Getsize) {
  Linked_list list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  EXPECT_EQ(list.get_legth(), 3);
}

TEST(KthNodeFromBack, KthNodeFromBack) {
  Linked_list list;
  list.insert(1);
  list.insert(2);
  list.insert(3);
  EXPECT_EQ(list.kth_node_from_end(1), 3);
  EXPECT_EQ(list.kth_node_from_end(3), 1);
  EXPECT_EQ(list.kth_node_from_end(4), INT_MIN);
  EXPECT_EQ(list.kth_node_from_end(0), INT_MIN);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  return 0;
}
