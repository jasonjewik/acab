#include "pet_builder.h"

PetBuilder::PetBuilder() {
  for (unsigned short i = 0; i < 4; ++i)
    buildFlags[i] = 0;
};

PetBuilder& PetBuilder::setAbility(short ability_) {
  ability = ability_;
  buildFlags[0] = 1;
  return *this;
};

PetBuilder& PetBuilder::setHealth(BoundedValue<short> health_) {
  health = health_;
  buildFlags[1] = 1;
  return *this;
};

PetBuilder& PetBuilder::setAttack(BoundedValue<short> attack_) {
  attack = attack_;
  buildFlags[2] = 1;
  return *this;
};

PetBuilder& PetBuilder::setExpLvl(short level_, short exp_, std::vector<BoundedValue<short>>& expThresholds_) {
  expThresholds = expThresholds_;

  level = BoundedValue<short>(0, level_, expThresholds_.size());
  exp = BoundedValue<short>(
    expThresholds_[level.value()].min(), 
    exp_,
    expThresholds_[level.value()].max()
  );

  buildFlags[3] = 1;
  return *this;
};

PetBuilder& PetBuilder::setStatus(short status_) {
  status = status_;
  buildFlags[4] = 1;
  return *this;
};

Pet* PetBuilder::build() {
  bool allFlagsSet = true;
  for (unsigned short i = 0; i < 4; ++i)
    allFlagsSet &= (buildFlags[i] == 1);

  Pet* p = nullptr;
  if (allFlagsSet)
    p = new Pet(ability, health, attack, level, exp, expThresholds, status);

  return p;
};