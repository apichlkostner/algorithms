#include "gtest/gtest.h"
#include "ArrayInversion.h"

class ArrayInversionTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};


TEST(count_split_inv_test, check) {
  int A0[] = {9,2,3,4,5,6,7,8};
  int n = sizeof(A0) / sizeof(A0[0]);
  auto z = ArrayInversion::sort_and_count(A0, n);

  EXPECT_EQ(7, z);
  EXPECT_EQ(2, A0[0]);
  EXPECT_EQ(3, A0[1]);
  EXPECT_EQ(4, A0[2]);
  EXPECT_EQ(5, A0[3]);
  EXPECT_EQ(6, A0[4]);
  EXPECT_EQ(7, A0[5]);
  EXPECT_EQ(8, A0[6]);
  EXPECT_EQ(9, A0[7]);


  int A1[] = {9,10,3,4,5,6,7,8};
  int n1 = sizeof(A1) / sizeof(A1[0]);
  z = ArrayInversion::sort_and_count(A1, n1);

  EXPECT_EQ(12, z);
  EXPECT_EQ(3, A1[0]);
  EXPECT_EQ(4, A1[1]);
  EXPECT_EQ(5, A1[2]);
  EXPECT_EQ(6, A1[3]);
  EXPECT_EQ(7, A1[4]);
  EXPECT_EQ(8, A1[5]);
  EXPECT_EQ(9, A1[6]);
  EXPECT_EQ(10, A1[7]);

  int A2[] = {10,9,3,4,5,6,7,8};
  int n2 = sizeof(A2) / sizeof(A2[0]);
  z = ArrayInversion::sort_and_count(A2, n2);

  EXPECT_EQ(13, z);
  EXPECT_EQ(3, A2[0]);
  EXPECT_EQ(4, A2[1]);
  EXPECT_EQ(5, A2[2]);
  EXPECT_EQ(6, A2[3]);
  EXPECT_EQ(7, A2[4]);
  EXPECT_EQ(8, A2[5]);
  EXPECT_EQ(9, A2[6]);
  EXPECT_EQ(10, A2[7]);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}