#pragma once
#include<string>
#include<string.h>

class Player
{
	public:
		void set_nickname(std::string);		// SET nickname

		void set_money_amount(float);		// SET money

		void set_fame_amount(float);		// SET money

		void set_weight_amount(float);		// SET weight

		void set_posision(int, int);		// SET player coordinates

		std::string get_nickname();				// GET nickname 

		float get_money_amount();				// GET money

		float get_fame_amount();				// GET money

		float get_weight_amount();				// GET weight

		int get_posision();						// GET player coordinates

		// add item

		// delete item

	private:
		std::string _nickname = "defaultPlayer";
		float _money = 100;
		float _fame = 0;
		float _weight = 0;
		int _x = 0;
		int _y = 0;
		// inventory
};
