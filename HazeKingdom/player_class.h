#pragma once
#include<string>
#include<string.h>

class Player
{
public:
	void set_nickname(std::string);			// set nickname string

	void set_money_amount(float);			// set money

	void set_fame_amount(float);			// set money

	void set_cargo_amount(float);			// set cargo

private:
	std::string _nickname = "DefoltPlayer";
	float _money = 0;
	float _fame = 0;
	float _cargo = 0;
};
