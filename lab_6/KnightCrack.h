#pragma once
#include "Hero.h"

class KnightCriack : public Hero {
public:

	KnightCriack(std::string name = "Jakson", int hp = 50, int def = 10, int dam = 15, int shield = 40)
		:Hero(name, hp, def, dam), shield_(shield) {
	}
	void ChangeHp(int damage) override;
	void Restart()override;
	void InfoHero() override;

	void AddAbilitySp() override;

protected:
	int shield_;
};