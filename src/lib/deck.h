#ifndef DECK
#define DECK

#include <vector>

class Pet;

class Deck {
  public:
    Deck(const int size);
    int getSize() const { return pets.size(); };
    Pet*& operator[] (int index) { return pets[index]; };
  private:
    std::vector<Pet*> pets;
};

#endif