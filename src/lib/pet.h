#ifndef PET
#define PET

#include <vector>

#include "bounded_value.h"

enum HealthStatus { fainted, alive };

class Pet {
  public:
    Pet() { };

    // TODO @jasonjewik: Add params for status condition and unique ability
    Pet(BoundedValue<short> health_, 
        BoundedValue<short> attack_,
        BoundedValue<short> level_,
        BoundedValue<short> exp_, 
        std::vector<BoundedValue<short>>& expThresholds_)
      : health(health_), attack(attack_), level(level_), 
        exp(exp_), expThresholds(expThresholds_) { };

    // Getters
    short getHealth() const { return health.value(); };
    short getAttack() const { return attack.value(); };    
    short getLevel() const { return level.value(); };
    short getExp() const { return exp.value(); };

    // Setters
    HealthStatus setHealth(short health_);
    void setAttack(short attack_);
    bool incrementExp();    
    
  private:
    BoundedValue<short> health;
    BoundedValue<short> attack;
    BoundedValue<short> level;
    BoundedValue<short> exp;
    std::vector<BoundedValue<short>> expThresholds;
};

#endif