#include <iostream>
#include "Chemist.h"

void Chemist::InfoHero() {
	Hero::InfoHero();
	std::cout << "Zel'a: " << zel_ << std::endl;
}

void Chemist::Restart(){
	hp_ = 30;
	def_ = 5;
	dam_ = 15;
	zel_ = 5;
}


void Chemist::AddAbilitySp() {
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
			if (zel_ > 0) {
				enemy->ChangeHp(dam_*2);
				zel_--;
			}
			});
		std::cout << "---------Double Attack---------- " << std::endl;
		break;
	}
	case 2: {
		skills.push_back([&](Hero* enemy) {
			if (zel_ > 0) {
				ChangeDam(-10*2);
			}
			});
		std::cout << "---------Simple Double Debuff---------- " << std::endl;
		break;
	}
	case 3: {
		skills.push_back([&](Hero* enemy) {
			if (zel_ > 0) {
				enemy->ChangeDef(dam_*2);
			}
			});
		std::cout << "-------Double Attack for defense------- " << std::endl;
		break;
	}
	default:
		break;
	}

}