#include <iostream>
#include "KnightCrack.h"
#include "Hero.h"

void KnightCriack::ChangeHp(int damage)  {
	//damage = abs(damage - shield_);
	if ((damage - shield_) > 0) {
		Hero::ChangeHp(damage);
	}
}

void KnightCriack::Restart() {
	hp_ = 50;
	def_ = 10;
	dam_ = 15;
	shield_ = 40;
}

void KnightCriack::InfoHero() {
	Hero::InfoHero();
	std::cout << "Shield: " << shield_ << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}


void KnightCriack::AddAbilitySp() {
	int choice;
	std::cout << "-------Choose a Super attack---------" << std::endl;
	std::cout << "1 - Double Attack" << std::endl;
	std::cout << "2 - Simple Double Debuff" << std::endl;
	std::cout << "3 - Double Attack for defense" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1: {
		skills.push_back([&](Hero* enemy) {
			
				enemy->ChangeHp(dam_ * 2);
				shield_++;
			});
		std::cout << "---------Double Attack---------- " << std::endl;
		break;
	}
	case 2: {
		skills.push_back([&](Hero* enemy) {
			if (shield_ > 0) {
				ChangeDam(-10 * 2);
				shield_--;
			}
			});
		std::cout << "---------Simple Double Debuff---------- " << std::endl;
		break;
	}
	case 3: {
		skills.push_back([&](Hero* enemy) {
			if (shield_ > 0) {
				enemy->ChangeDef(dam_ * 2);
			}
			});
		std::cout << "-------Double Attack for defense------- " << std::endl;
		break;
	}
	default:
		break;
	}

}