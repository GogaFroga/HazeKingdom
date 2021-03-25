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

void Player::set_weight_amount(float weight)
{
	Player::_weight = weight;
}

void Player::set_posision(int x, int y)
{
	Player::_x = x;
	Player::_y = y;
	// Player::_z = z;
}

std::string Player::get_nickname()
{
	return(_nickname);
}

float Player::get_money_amount()
{
	return(_money);
}

float Player::get_fame_amount()
{
	return(_fame);
}

float Player::get_weight_amount()
{
	return(_weight);
}

int Player::get_posision()
{
	return(_x, _y);
}
