#include<iostream>
#include<string>
#include"player_class.h"


void Player::set_nickname(QString nickname)
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
}

QString Player::get_nickname() const
{
    return(_nickname);
}

float Player::get_money_amount() const
{
    return(_money);
}

float Player::get_fame_amount() const
{
    return(_fame);
}

float Player::get_weight_amount() const
{
    return(_weight);
}

int Player::get_x_posision() const
{
    return(_x);
}

int Player::get_y_posision() const
{
    return(_y);
}

unsigned int Player::get_item_amount(unsigned int index) const
{
    int amount = inventory[index][0];
    return(amount);
}

int Player::add_item(unsigned int index, unsigned int amount)
{
    //сделать лимит
    inventory[index][0] = inventory[index][0] + amount;
    return(0);
}

int Player::delete_item(unsigned int index, unsigned int amount)
{
    if (inventory[index][0] - amount >= 0)
    {
        inventory[index][0] = inventory[index][0] - amount;
        return(0);
    }
    else
        return(-1);
}
