#include "gtest/gtest.h"
#include "pet.h"

class PetTest : public ::testing::Test {
  public:
    Pet* p = new Pet(1, 2, 0, 1);
    Pet* q = new Pet(3, 1, 1, 2);
};

TEST_F(PetTest, MergePets) {
  int pexp = p->getExp();
  int qexp = q->getExp();
  EXPECT_EQ(p->merge(q), true);
  EXPECT_EQ(p->getExp(), pexp + qexp + 1);
}