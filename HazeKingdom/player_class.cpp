#include<iostream>
#include<string>
#include"player_class.h"


void Player::set_nickname(std::string nickname)
{
	Player::_nickname = nickname;
}

void Player::set_money_amount(float money)
{
	Player::_money = money;
}

void Player::set_fame_amount(float fame)
{
	Player::_fame = fame;
}

void Player::set_cargo_amount(float cargo)
{
	Player::_cargo = cargo;
}