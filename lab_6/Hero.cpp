#include <iostream>
#include "Hero.h"

void Hero::ChangeHp(int damage) {
	damage -= def_;
	hp_ -= damage;
	if (hp_ < 0)
		std::cout << "Dead" << std::endl;
}

std::string Hero::Name() {
	return name_;
}

void Hero::ChangeDef(int damage) {
	if (def_ <= 0)
		ChangeHp(damage * 2);
	else
		def_ -= damage;
}

void Hero::ChangeDam(int damage) {
	if (dam_ <= 0)
		ChangeHp(damage * 2);
	else
		dam_ -= damage;
}

void Hero::InfoHero() {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "Health: " << hp_ << std::endl;
	std::cout << "Defence: " << def_ << std::endl;
	std::cout << "Damage: " << dam_ << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void Hero::AddAbility() {
	int choice;
	std::cout << "-------Choose a simple attack---------" << std::endl;
	std::cout << "1 - Simple Attack" << std::endl;
	std::cout << "2 - Simple Debuff" << std::endl;
	std::cout << "3 - Simple Attack for defense" << std::endl;

	
		skills.push_back( [&](Hero* enemy) {
			enemy->ChangeHp(dam_);
			});
		std::cout << "---------Simple Attack---------- "<< std::endl;
	
	
	
		skills.push_back([&](Hero* enemy) {
			ChangeDam(-10);
			});
		std::cout << "---------Simple Debuff---------- " << std::endl;
		


		skills.push_back([&](Hero* enemy) {
			enemy->ChangeDef(dam_);
			});
		std::cout << "-------Simple Attack for defense------- " << std::endl;
	
	
}

void Hero::SellectAttack(int var, Hero* enemy) {
	skills[var](enemy);
}

//void Hero::Block(int my, int enemys, Hero* enemy) {
//	{
//		if (my == enemys) {
//			std::cout << Name() << ", you guessed!!!" << std::endl;
//			SpecialAttack(enemy);
//		}
//		else {
//			std::cout << Name() << ", you don't guessed!!!" << std::endl;
//		}
//	}
//}

void Hero::CoinsAdd() {
	coins_++;
}

int Hero::CoinsInfor() {
	return coins_;
}

void Hero::Win(Hero* enemy) {
	if (enemy->IsDead()) {
		CoinsAdd();
		std::cout << Name() << ", YOU WIN!!!!" << std::endl;
	}
	enemy->InfoHero();
}

bool Hero::IsDead() {
	if (hp_ <= 0) {
		return true;
	}
	return false;
}