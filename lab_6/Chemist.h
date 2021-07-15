#pragma once
#include "Hero.h"


class Chemist : public Hero {
public:
	Chemist(std::string name = "William", int hp = 30, int def = 5, int dam = 15, int zel = 5)
		:Hero(name, hp, def, dam), zel_(zel) {
	}
	void InfoHero() override;
	void Restart()override;

	void AddAbilitySp() override;

protected:
	int zel_;
};
