#ifndef PET_BUILDER
#define PET_BUILDER

#include <array>
#include <memory>
#include <vector>

#include "bounded_value.h"
#include "pet.h"

class PetBuilder {
  public:
    PetBuilder();

    PetBuilder& setAbility(short ability_);
    PetBuilder& setHealth(BoundedValue<short> health_);
    PetBuilder& setAttack(BoundedValue<short> attack_);
    PetBuilder& setExpLvl(short level_, short exp_, std::vector<BoundedValue<short>>& expThresholds_);
    PetBuilder& setStatus(short status_);

    Pet* build();

  private:
    std::array<short, 5> buildFlags;
    short ability;
    BoundedValue<short> health;
    BoundedValue<short> attack;
    BoundedValue<short> level;
    BoundedValue<short> exp;
    std::vector<BoundedValue<short>> expThresholds;
    short status;
};

#endif