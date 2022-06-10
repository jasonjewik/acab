#ifndef DECK
#define DECK

#include <vector>

class Pet;

class Deck {
  public:
    Deck(const int size);
    Pet*& operator[] (int index) { return pets[index]; };
    int getSize() const { return pets.size(); };    
    void swap(int index_a, int index_b);
  private:
    std::vector<Pet*> pets;
};

#endif