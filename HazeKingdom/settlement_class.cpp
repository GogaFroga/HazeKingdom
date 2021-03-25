#include<iostream>
#include<string.h>
#include"settlement_class.h"
#include"player_class.h"


void Settlement::set_settlement_name(std::string)
{
	std::string settlement_name;
	std::cin >> settlement_name;
	Settlement::_settlement_name = settlement_name;
}

std::string Settlement::get_settlement_name()
{
	return (Settlement::_settlement_name);
}

void Settlement::set_settlement_property(unsigned short index)
{
	Settlement::_settlement_property = index;
}

unsigned short Settlement::get_settlement_property()
{
	return (Settlement::_settlement_property);
}

void Settlement::set_settlement_situation(unsigned short index)
{
	Settlement::_settlement_situation = index;
}

unsigned short Settlement::get_settlement_situation()
{
	return(Settlement::_settlement_situation);
}

void Settlement::create_settlement(unsigned short property_index, unsigned short situation_index, class Market market)
{
	set_settlement_property(property_index);
	set_settlement_situation(situation_index);

	unsigned short index;
	for (index = 0; index < items_amount; index++)
	{
		float item_price = market.get_item_deafolt_price(index);
		_SELL_item_local_price[index] = item_price * _SELL_property_multiplier[index][_settlement_property] *
										_SELL_situation_multiplier[index][_settlement_situation];

		_BUY_item_local_price[index] = item_price * _BUY_property_multiplier[index][_settlement_property] *
			_BUY_situation_multiplier[index][_settlement_situation];
	}
}

void Market::buy(unsigned short index, unsigned short amount, class Player player)
{
	float money = player.get_money_amount();
	float weight = player.get_weight_amount();
	float item_price = Market::get_item_deafolt_price(index);
	if (money >= amount * item_price)
	{
		money -= amount * item_price;
		weight += amount * weight;
		player.set_money_amount(money);
		player.set_weight_amount(weight);
		//add item
	}
	else
		(std::cout << "Нехватает денег!");
}

void Market::sell(unsigned short index, unsigned short amount, class Player player)
{
	float money = player.get_money_amount();
	float weight = player.get_weight_amount();
	//float items_amount = player.get_items_amount();
	float item_price = Market::get_item_deafolt_price(index);
	if (items_amount > amount)
	{
		money += amount * item_price;
		weight -= amount * weight;
		player.set_money_amount(money);
		player.set_weight_amount(weight);
		//delete item
	}
	else
		(std::cout << "У вас нет этого товара!");
}

std::string Market::get_item_name(unsigned short)
{
	return std::string();
}

float Market::get_item_deafolt_price(unsigned short index)
{
	return (_item_deafolt_price[index]);
}

float Market::get_item_weight(unsigned short index)
{
	return (_item_weight[index]);
}
