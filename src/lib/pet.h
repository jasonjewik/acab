#ifndef PET
#define PET

#include <vector>

#include "bounded_value.h"

enum HealthStatus { fainted, alive };

class Pet {
  public:
    Pet() { };

    Pet(short ability_,
        BoundedValue<short> health_,
        BoundedValue<short> attack_,
        BoundedValue<short> level_,
        BoundedValue<short> exp_,
        std::vector<BoundedValue<short>>& expThresholds_,
        short status_)
      : ability(ability_), health(health_), attack(attack_), level(level_), 
        exp(exp_), expThresholds(expThresholds_), status(status_) { };

    // Getters
    short getAbility() const { return ability; };
    short getHealth() const { return health.value(); };
    short getAttack() const { return attack.value(); };    
    short getLevel() const { return level.value(); };
    short getExp() const { return exp.value(); };
    short getStatus() const { return status; };

    // Setters
    HealthStatus setHealth(short health_);
    void setAttack(short attack_);
    bool incrementExp();
    bool setStatus(short status_);
    
  private:
    short ability;
    BoundedValue<short> health;
    BoundedValue<short> attack;
    BoundedValue<short> level;
    BoundedValue<short> exp;
    std::vector<BoundedValue<short>> expThresholds;
    short status;
};

#endif