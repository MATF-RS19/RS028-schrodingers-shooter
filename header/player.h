#ifndef PLAYER_DEF
#define PLAYER_DEF

#include "weapon.h"
#include "../header/util.h"
#include <Box2D/Box2D.h>
#include <AL/alut.h>

typedef struct _Input{
    float horizontal, vertical, angle;
    bool shoot;
} Input;

class Brain;

class Player : public Colider{
public:
    Player(float x, float y, float r);
    Player();
    void Draw();
    void DrawShadow();
	void SwapWeapon(Weapon* newWeapon);
	void takeDmg(int dmg);
	void takeDmg(int dmg, b2Vec2 dir);
	void IncreaseHealth(int amount);
	void Revive();
	void SetMaxHealth(int mh);
	void moveSoundSource();

    virtual ClassID getClassID();
    void SetBrain(Brain* brain);
    Brain* m_brain;
    bool team;
		bool alive;
		bool deathFlag;
    Input input;
    Weapon* equiped_weapon;
    b2Body* body;
    float r;
    bool see_player;
    void die();

private:
    float speed;
    int health;
		int maxHealth;

protected:
  ALuint soundSource[2];
};

class Brain{
protected:
    Brain(Player& player);
    Player* m_player;
    

public:
    virtual void Update() = 0;
    virtual ~Brain(){}
};


class playerBrain: public Brain{
public:
    playerBrain(Player& player);

public:
    void Update();
};

class botBrain: public Brain{
public:
    botBrain(Player& player);

public:
    void Update();
};

void BotMoves();
void BotAim();
void Move(int ip, int jp,std::vector<std::vector<int>>& pathMap);

#endif
