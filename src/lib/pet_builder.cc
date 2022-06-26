#include "pet_builder.h"

PetBuilder& PetBuilder::setHealth(BoundedValue<short> health_) {
  health = health_;
  return *this;
};

PetBuilder& PetBuilder::setAttack(BoundedValue<short> attack_) {
  attack = attack_;
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
  return *this;
};

Pet* PetBuilder::build() {
  Pet* p = new Pet(health, attack, level, exp, expThresholds);
  return p;
};