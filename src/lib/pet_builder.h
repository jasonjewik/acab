#ifndef PET_BUILDER
#define PET_BUILDER

#include <memory>
#include <vector>

#include "bounded_value.h"
#include "pet.h"

class PetBuilder {
  public:
    PetBuilder& setHealth(BoundedValue<short> health_);
    PetBuilder& setAttack(BoundedValue<short> attack_);
    PetBuilder& setExpLvl(short level_, short exp_, std::vector<BoundedValue<short>>& expThresholds_);

    Pet* build();

  private:
    BoundedValue<short> health;
    BoundedValue<short> attack;
    BoundedValue<short> level;
    BoundedValue<short> exp;
    std::vector<BoundedValue<short>> expThresholds;
};

#endif