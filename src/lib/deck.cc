#include <algorithm>

#include "deck.h"
#include "pet.h"

Deck::Deck(const int size) {
  pets.resize(size);
};

void Deck::swap(int index_a, int index_b) {
  std::iter_swap(pets.begin() + index_a, pets.begin() + index_b);
};