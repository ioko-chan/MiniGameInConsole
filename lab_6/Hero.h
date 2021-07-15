#pragma once
#include <iostream>
#include <unordered_map>
#include <functional>

class Hero {
public:

	Hero(std::string name, int hp, int def, int dam)
		: name_(name), hp_(hp), def_(def), dam_(dam) {
	}

	virtual void ChangeHp(int damage);
	virtual void ChangeDef(int damage);
	virtual void ChangeDam(int damage);

	void AddAbility();

	virtual void AddAbilitySp()=0;
      
	void CoinsAdd();
	std::string Name();

	virtual void InfoHero();
	int CoinsInfor();

	virtual void Restart() = 0;
	void Win(Hero* enemy);
	bool IsDead();

	void SellectAttack(int var, Hero* enemy);

protected:
	std::string name_;
	int hp_, def_, dam_, coins_ = 0;
	std:: vector  <std::function<void(Hero* enemy)> > skills;
};