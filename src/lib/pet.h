#ifndef PET
#define PET

class Pet {
  public:
    // TODO @jasonjewik: Add params for status condition and unique ability
    Pet(int health, int attack, int exp, int level)
      : health(health), attack(attack), exp(exp), level(level) { };

    // Getters
    int getHealth() const { return health; };
    int getAttack() const { return attack; };
    int getExp() const { return exp; };
    int getLevel() const { return level; };

    // Setters
    void setHealth(int health_) { health = health_ };
    void setAttack(int attack_) { attack = attack_ };    
    void setExp(int exp_) { exp = exp_; };
    void setLevel(int level_) { level = level_; }
    
  private:
    int health;
    int attack;
    int exp;
    int level;
};

#endif