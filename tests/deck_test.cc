#include <memory>

#include "gtest/gtest.h"
#include "deck.h"
#include "pet.h"

class DeckTest : public ::testing::Test {
  public:
    int deckSize = 5;
    Deck deck(deckSize);
    std::shared_ptr<Pet> p(new Pet(1, 2, 0, 1));
};

TEST_F(DeckTest, GetDeckSize) {
  EXPECT_EQ(deckSize, deck.getSize());
}

TEST_F(DeckTest, GetEmptySlot) {
  for (int i = 0; i < deckSize; ++i) {
    EXPECT_EQ(nullptr, deck[i]);
  }
}

TEST_F(DeckTest, InsertPet) {  
  deck[0] = p;
  EXPECT_EQ(deck[0], p);
}