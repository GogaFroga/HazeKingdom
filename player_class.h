#pragma once
#include<string>
#include<string.h>
#include<QString>

#define items_amount 4

class Player
{
    public:
        void set_nickname(QString);		// SET nickname

        void set_money_amount(float);		// SET money

        void set_fame_amount(float);		// SET money

        void set_weight_amount(float);		// SET weight

        void set_posision(int, int);		// SET player coordinates

        QString get_nickname();			// GET nickname

        float get_money_amount();			// GET money

        float get_fame_amount();			// GET money

        float get_weight_amount();			// GET weight

        int get_posision();					// GET player coordinates

        int get_item_amount();

        int add_item(unsigned int, unsigned int);			// ADD item

        int delete_item(unsigned int, unsigned int);		// DELETE item

    private:
        QString _nickname = "defaultPlayer";
        float _money = 100;
        float _fame = 0;
        float _weight = 0;
        int _x = 0;
        int _y = 0;
        unsigned int inventory[items_amount][1] = { { 0 }, { 0 }, { 0 }, { 0 } }; // Coal // Stone // Wood // Wheat
};
