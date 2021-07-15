#pragma once
#include "Hero.h"
class Haos :public Hero {
public:
	Haos(std::string name = "Puff", int hp = 60, int def = 5, int dam = 10, int shine = 5)
		: Hero(name, hp, def, dam), shine_(shine) {
	};
	void InfoHero() override;
	void Restart()override;
	void AddAbilitySp() override;
	
protected:
	int shine_;
};