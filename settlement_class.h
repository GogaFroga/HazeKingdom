#pragma once
#include<iostream>
#include<string.h>
#include<QPushButton>

#define situations_amount 4
#define settlement_property_amount 4
#define items_amount 4


class Settlement
{
    public:
        void set_settlement_name(QString);
        QString get_settlement_name();

        void set_settlement_property(unsigned short);
        unsigned short get_settlement_property();
        QString get_settlement_property_name(unsigned short index);

        void set_settlement_x(int);
        int get_settlement_x();
        void set_settlement_y(int);
        int get_settlement_y();

        void set_settlement_situation(unsigned short);
        unsigned short get_settlement_situation();
        QString get_settlement_situation_name(unsigned short index);
        QString get_settlement_situation_text(unsigned short index);

        void create_settlement(unsigned short, unsigned short, class Market, QString, int, int); // create (property, situation, name, x, y)

    private:
        Market *market;
        // Значения присваиваются в момент создания, через create_settlement
        QString _settlement_name = "defaultSettlement";
        unsigned short _settlement_property = 0;
        unsigned short _settlement_situation = 0;
        float _SELL_item_local_price[items_amount];
        float _BUY_item_local_price[items_amount];
        int _x = 200;
        int _y = 200;

        // Значения являются стандартными значениями
        QString _settlement_property_name[settlement_property_amount] = { "Village", "Town", "Mining Village", "Outpost" };
        float _SELL_property_multiplier[items_amount][settlement_property_amount] = {
                                                                                        { 0.90, 1.10, 0.50, 1.20 },		// Coal
                                                                                        { 0.50, 1.22, 0.50, 1.08 },		// Stone
                                                                                        { 1.10, 1.11, 1.22, 1.05 },		// Wood
                                                                                        { 0.50, 1.12, 1.18, 1.02 }		// Wheat
                                                                                     };
        float _BUY_property_multiplier[items_amount][settlement_property_amount] = {
                                                                                { 10.0, 1.30, 0.90, 1.60 },		// Coal
                                                                                { 10.0, 1.30, 0.95, 1.55 },		// Stone
                                                                                { 2.00, 1.30, 1.30, 1.50 },		// Wood
                                                                                { 0.70, 1.30, 2.00, 1.50 }		// Wheat
        };
        QString _situation_name[situations_amount] = { "Everything is quiet", "Lack of food", "Lack of building materials", "We need coal" };
        float _SELL_situation_multiplier[items_amount][situations_amount] = {
                                                                                { 1.00, 1.00, 1.00, 1.20 },	// Coal
                                                                                { 1.00, 1.00, 1.15, 1.00 },	// Stone
                                                                                { 1.00, 1.00, 1.13, 1.00 },	// Wood
                                                                                { 1.00, 1.12, 1.00, 1.00 }	// Wheat
                                                                             };
        float _BUY_situation_multiplier[items_amount][situations_amount] = {
                                                                                { 1.00, 1.00, 1.00, 10.0 }, // Coal
                                                                                { 1.00, 1.00, 4.00, 1.00 },	// Stone
                                                                                { 1.00, 1.00, 4.00, 1.00 },	// Wood
                                                                                { 1.00, 10.0, 1.00, 1.00 }	// Wheat
                                                                            };
        QString _situation_text[situations_amount] = { "The typical crowd noise is heard in the city...", "You see the haggard faces of people in the streets...", "You don't see any ongoing constructions in the city", "You see, that there is no smoke coming out from the forges!" };

};


class Market	// local settlement market
{
    public:
        void buy(unsigned short, unsigned short, class Player);			// BUY (item index, item amount)

        void sell(unsigned short, unsigned short, class Player);		// SELL (item index, item amount)

        std::string get_item_name(unsigned short);		// GET item name by index

        float get_item_deafolt_price(unsigned short);	// GET default price by index

        float get_item_weight(unsigned short);			// GET weight by index

    private:
        std::string _item_name[items_amount] = { "Coal", "Stone", "Wood", "Wheat" };
        float _item_deafolt_price[items_amount] = { 100, 40, 20, 2 };
        float _item_weight[items_amount] = { 10, 30, 15, 2 };
};

