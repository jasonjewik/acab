#ifndef DECK
#define DECK

#include <vector>

class Pet;

class Deck {
  public:
    Deck(const int size);
    int getSize() const { return size; };
    (Pet*)& operator[] (int index);
  private:
    int size;
    std::vector<Pet*> pets;
};

#endif