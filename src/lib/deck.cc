#include "deck.h"

Deck::Deck(const int size) {
  pets.resize(size);
};

(Pet*)& Deck::operator[] (int index) {
  if (index > 0 && index < size)
    return pets[index];
  return nullptr;
};