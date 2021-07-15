//Лабораторная работа 2
//Решить лабораторную работу 1 с вынесением способности в отдельный класс.
//Разрешается пойти двумя путями(выберите один из двух) :
//
//    1)Реализовать способность  в виде  абстрактого класса или интерфейса.
//
//    2)Реализовать способность в виде std::function
//
//    Изменить линейку способностей(верхняя, средняя, нижняя) героя на список.Чтобы по номеру можно было выбрать соответствующую способность.
//    У класса героя есть набор способностей(общий для всех подклассов).У каждого подкласса есть набор уникальных для этого подкласса умений.
//
//    Во время боя персонаж может использовать не более 5 способностей из списка за раз.После выбора персонажа игрок  выбирает какие способности из общего списка(класса и  подкласса) он будет использовать в этом бою.
//
//    P.S.Эта и все следующие лабораторные принимаются только в формате проекта!Писать в одном файле больше нельзя!Разбиваем на.h и.cpp.ВСЕ следующие лабораторные!
//
//    P.S2.Лабораторная работа 1 в модификации 2 принята НЕ будет, это РАЗНЫЕ лабораторные работы принимаются отдельно!!!

#include <iostream>
#include "Hero.h"
#include "Chemist.h"
#include "KnightCrack.h"
#include "Haos.h"
#include <functional>

Hero* Variant(int var, int play) {
	switch (var) {
	case 1: {
		std::cout << "Player" << play << " chose Chemist" << std::endl;
		return new Chemist{};
	}
	case 2: {
		std::cout << "Player" << play << " chose KhightCriack" << std::endl;
		return new KnightCriack{};
	}
	case 3: {
		std::cout << "Player" << play << " chose Haos" << std::endl;
		return new Haos{};
	}
	}
}

void Move(Hero* player, Hero* enemy, int& varPlayer) {
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "Player <" << player->Name() << ">:" << std::endl;
	std::cin >> varPlayer;
	
		player->SellectAttack(varPlayer, enemy);
		player->Win(enemy);
	
}

void MortalBattle(Hero* Player1, Hero* Player2) {
	int var1 = 0, var2 = 0, varP = 0;
	while (1) {
		Move(Player1, Player2, var1);
		if (Player1->IsDead() || Player2->IsDead())
			break;
		Move(Player2, Player1, var2);
		if (Player1->IsDead() || Player2->IsDead())
			break;
	}
}

void Battle(Hero* Player1, Hero* Player2) {
	while (1) {
		if (Player1->CoinsInfor() == 3 || Player2->CoinsInfor() == 3)
			break;
		MortalBattle(Player1, Player2);
		system("cls");
		std::cout << "Score: <" << Player1->CoinsInfor() << ":" << Player2->CoinsInfor() << "> " << std::endl;
		std::cout << "Restart!" << std::endl;
		Player1->Restart();
		Player2->Restart();
	}
	system("cls");
	(Player1->CoinsInfor() == 3) ? (std::cout << "Player1 WIN!") : (std::cout << "Player2 WIN!" << std::endl);
	std::cout << "Score: <" << Player1->CoinsInfor() << ":" << Player2->CoinsInfor() << "> " << std::endl;
}

int main() {
	std::cout << "-----------------------<Player 1>?-----------------------" << std::endl << std::endl << "-------" << "<Chemist>" << "-------" << "<KnightCriack>" << "-------" << "<Haos>" << "-------" << std::endl << std::endl << std::endl;
	int variant1;
	std::cin >> variant1;
	std::cout << std::endl << std::endl;  
	Hero* Player1 = Variant(variant1, 1);
	Player1->InfoHero();
	Player1->AddAbility();
	Player1->AddAbilitySp();
	std::cout << std::endl << std::endl;
	std::cout << "-----------------------<Player 2>?-----------------------" << std::endl << std::endl << "-------" << "<Chemist>" << "-------" << "<KnightCriack>" << "-------" << "<Haos>" << "-------" << std::endl << std::endl << std::endl;;
	int variant2;
	std::cin >> variant2;
	std::cout << std::endl << std::endl;
	Hero* Player2 = Variant(variant2, 2);
	Player2->InfoHero();
	Player2->AddAbility();
	Player2->AddAbilitySp();
	Battle(Player1, Player2);
	return 0;
}
