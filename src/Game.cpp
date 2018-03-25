#include "stdafx.h"
#include <iostream>
#include <ctime>
#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}


void Game::drawMap()
{
	for (int i = 0; i < Constants::HEIGHT; i++) {
		for (int j = 0; j < Constants::WIDTH; j++) {
			if (i == 0 || i == Constants::HEIGHT - 1 || j == 0 || j == Constants::WIDTH - 1) {
				field_[i][j] = '#';
			}
			else {
				field_[i][j] = ' ';
			}
		}
	}
	for (int i = 0; i <battleCity_.getWalls().size(); i++) {
		for (int j = 0; j < battleCity_.getWalls()[i].getLength(); j++) {
			Wall wall = battleCity_.getWalls()[i];
				field_[wall[j].getPosY()][wall[j].getPosX()] = '#';
		}
	}
	for (int i = 0; i <battleCity_.getFortress().size(); i++) {
			field_[battleCity_.getFortress()[i].getPosY()][battleCity_.getFortress()[i].getPosX()] = '@';
	}
	if (!(isVictory() || isGameOver())) {
		for (int i = 0; i < battleCity_.getPlayerBullets().size(); i++) {
			field_[battleCity_.getPlayerBullets()[i].getPosY()][battleCity_.getPlayerBullets()[i].getPosX()] = '*';
		}
		for (int i = 0; i < battleCity_.getEnemiesBullets().size(); i++) {
			field_[battleCity_.getEnemiesBullets()[i].getPosY()][battleCity_.getEnemiesBullets()[i].getPosX()] = '*';
		}
	}
	for (int i = 0; i < battleCity_.getEnemies().size(); i++) {
		field_[battleCity_.getEnemies()[i].getPosY()][battleCity_.getEnemies()[i].getPosX()] = 'E';
	}
	if (battleCity_.getGoldState()) {
		field_[Constants::posGoldY][Constants::posGoldX] = 'G';
	}
	if (battleCity_.getTank().getLife() > 0) {
		field_[battleCity_.getTank().getPosY()][battleCity_.getTank().getPosX()] = 'T';
	}
	for (int i = 0; i <Constants::HEIGHT; i++) {
		for (int j = 0; j < Constants::WIDTH; j++) {
			std::cout << field_[i][j];
		}
		std::cout << std::endl;
	}
	if (!(isVictory() || isGameOver())) {
		std::cout << "Life: " << battleCity_.getTank().getLife() << ", Score: " << battleCity_.getTank().getScore() << ", Time: " << gameTime;
	}
	else {
		std::cout << "Life: " << battleCity_.getTank().getLife() << ", Score: " << battleCity_.getTank().getScore() << ", Time: " << gameTime;
		if (battleCity_.getEnemies().size() == 0) {
			std::cout << " YOU WIN" << std::endl;
		}
		else if (battleCity_.getTank().getLife()<=0) {
			std::cout << " YOU LOSE, You are destroyed" << std::endl;
		}
		else if(!battleCity_.getGoldState()){
			std::cout << " YOU LOSE, Gold is destroyed" << std::endl;
		}
	}
}

bool Game::isGameOver()
{
	if (!battleCity_.getGoldState()
		|| battleCity_.getTank().getLife() <= 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Game::isVictory()
{
	if (battleCity_.getEnemies().size() == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Game::run()
{
	system("cls");
	drawMap();
	battleCity_.playerAction();
	battleCity_.enemyAction();
	battleCity_.bulletAction();
	gameTime = (float)(clock()) / CLOCKS_PER_SEC;
}
