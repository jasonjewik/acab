#include "gtest/gtest.h"
#include "deck.h"
#include "pet.h"

class DeckTest : public ::testing::Test {
  public:
    int deckSize = 5;
    Deck deck = Deck(deckSize);
    Pet* p = new Pet(1, 2, 0, 1);
    Pet* q = new Pet(3, 1, 1, 2);
};

TEST_F(DeckTest, GetDeckSize) {
  EXPECT_EQ(deckSize, deck.getSize());
}

TEST_F(DeckTest, GetEmptySlot) {
  for (int i = 0; i < deckSize; ++i)
    EXPECT_EQ(nullptr, deck[i]);
}

TEST_F(DeckTest, InsertPet) {  
  deck[0] = p;
  EXPECT_EQ(p, deck[0]);
  for (int i = 1; i < deckSize; ++i)
    EXPECT_EQ(nullptr, deck[i]);
}

TEST_F(DeckTest, SwapPetWithEmpty) {
  deck[0] = p;
  deck.swap(0, 4);
  EXPECT_EQ(nullptr, deck[0]);
  EXPECT_EQ(p, deck[4]);
}

TEST_F(DeckTest, SwapTwoPets) {
  deck[0] = p;
  deck[2] = q;
  deck.swap(0, 2);
  EXPECT_EQ(q, deck[0]);
  EXPECT_EQ(p, deck[2]);  
}