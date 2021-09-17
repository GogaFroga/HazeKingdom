#include<iostream>
#include<string.h>
#include<QtWidgets/QPushButton>
#include"settlement_class.h"
#include"player_class.h"


void Settlement::set_settlement_name(QString settlement_name)
{
        Settlement::_settlement_name = settlement_name;
}

QString Settlement::get_settlement_name()
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

QString Settlement::get_settlement_property_name(unsigned short index)
{
        return (Settlement::_settlement_property_name[index]);
}

void Settlement::set_settlement_situation(unsigned short index)
{
        Settlement::_settlement_situation = index;
}

unsigned short Settlement::get_settlement_situation()
{
        return(Settlement::_settlement_situation);
}

QString Settlement::get_settlement_situation_name(unsigned short index)
{
        return (Settlement::_situation_name[index]);
}

QString Settlement::get_settlement_situation_text(unsigned short index)
{
        return (Settlement::_situation_text[index]);
}

void Settlement::set_settlement_x(int x)
{
    Settlement::_x = x;
}

int Settlement::get_settlement_x()
{
    return(Settlement::_x);
}

void Settlement::set_settlement_y(int y)
{
    Settlement::_y = y;
}

int Settlement::get_settlement_y()
{
    return(Settlement::_y);
}

void Settlement::create_settlement(unsigned short property_index, unsigned short situation_index, QString name, int x , int y)
{
        set_settlement_name(name);
        set_settlement_property(property_index);
        set_settlement_situation(situation_index);
        set_settlement_x(x);
        set_settlement_y(y);
        unsigned short index;
        for (index = 0; index < items_amount; index++)
        {
                float item_price = Settlement.get_item_default_price(index);
                _SELL_item_local_price[index] = item_price * _SELL_property_multiplier[index][_settlement_property] *
                                                                                _SELL_situation_multiplier[index][_settlement_situation];

                _BUY_item_local_price[index] = item_price * _BUY_property_multiplier[index][_settlement_property] *
                        _BUY_situation_multiplier[index][_settlement_situation];
        }
}


int Settlement::buy(unsigned int index, unsigned short amount, class Player *player)
{
        float money = player->get_money_amount();
        float weight = player->get_weight_amount();
        float item_price = Settlement::_BUY_item_local_price[index];
        if (money >= amount * item_price)
        {
                money -= amount * item_price;
                //weight += amount * weight;
                player->set_money_amount(money);
                player->set_weight_amount(weight);
                player->add_item(index, amount);
        }
        else
                return(1);
}

void Settlement::sell(unsigned short index, unsigned short amount, class Player *player)
{
        float money = player->get_money_amount();
        float weight = player->get_weight_amount();
        unsigned int item_amount = player->get_item_amount(index);
        float item_price = Settlement::_SELL_item_local_price[index];
        if (item_amount >= amount)
        {
                money += amount * item_price;
                weight -= amount * weight;
                player->set_money_amount(money);
                player->set_weight_amount(weight);
                player->delete_item(index, amount);
        }
        else
                (std::cout << "У вас нет этого товара!");
}

std::string Settlement::get_item_name(unsigned short)
{
        return std::string();
}

float Settlement::get_item_default_price(unsigned short index)
{
        return (_item_deafolt_price[index]);
}

float Settlement::get_item_weight(unsigned short index)
{
        return (_item_weight[index]);
}
