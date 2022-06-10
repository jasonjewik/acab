#include "pet.h"

void Pet::setExp(int exp_) {
  exp = exp_;
};

void Pet::setLevel(int level_) {
  level = level_;
};

bool Pet::merge(Pet* other) {
  // TODO: check if mergeable
  exp += other->getExp() + 1;
  return true;
};