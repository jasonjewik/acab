#include "pet.h"

HealthStatus Pet::setHealth(short health_) {
  short difference = health.value(health_);
  if (difference < 0)
    return fainted;
  return alive;
};

void Pet::setAttack(short attack_) {
  attack.value(attack_);
};

bool Pet::incrementExp() {
  if (level.isMax()) {
    exp.value(0);
    return false;
  }

  exp.value(exp.value() + 1);
  if (!exp.isMax())
    return true;

  level.value(level.value() + 1);
  if (!level.isMax())
    exp = expThresholds[level.value()];
  exp.value(0);
  return true;
};

bool Pet::setStatus(short status_) {
  status = status_;
  return true;
};