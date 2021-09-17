#include<stdlib.h>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include<QWidget>
#include<QTextStream>
#include<QObject>
#include<QCloseEvent>
#include<QEvent>
#include<QCoreApplication>
#include<QKeyEvent>
#include<QDebug>
#include<QProcessEnvironment>
#include<QDir>
#include"mainmenu.h"
#include"ui_mainmenu.h"
#include"settlement_class.h"
#include"player_class.h"

using namespace std;

Player player;
Settlement settlement;
unsigned int _index = 0;
int settlement_number = 0;
void moveCharacter();


mainmenu::mainmenu(QWidget *parent): QDialog(parent), ui(new Ui::mainmenu)
{
    setGeometry(500, 30, 0, 0);
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
}

mainmenu::~mainmenu()
{
    delete ui;
}

// tabs
void mainmenu::on_start_clicked()
{
    player.set_nickname("DragonSlayer");
    settlement.create_settlement(0, 3, "Far Home", 719, 438);
    setup_all();

    QString imagename = ":/assets/Assets/Mmap.png";
    QImage image(imagename);
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsView* view = new QGraphicsView(scene);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    view->move(920, 0);
    view->setGeometry(778, 30, 1142, 1020);
    scene->addItem(item);
    view->show();

    ui->tabWidget->removeTab(0);
    this->setGeometry(0, 30, 778, 1020);
    //mainmenu::setWindowFlags(Qt::WindowMaximizeButtonHint);
    //mainmenu::setWindowModality(Qt::WindowModal);
}

void mainmenu::on_about_clicked()
{
    if (!ui->rules->isEnabled())
    {
        ui->rules->setEnabled(true);
        ui->rules->setText("Автор: Вакуленко Артур М8О-111Б\n"
        "Суть: За каждое перемещение с игрока снимается плата в зависимости от расстояния между ним и городом."
        "\nПри перемещении в город можно посмотреть ситуацию в нем, купить товар."
        "\n");
    }
    else if (ui->rules->isEnabled())
    {
        ui->rules->setEnabled(false);
        ui->rules->setText("");
    }
}

void mainmenu::on_exit_clicked()
{
    mainmenu::close();
}

void mainmenu::on_charactertab_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setTabEnabled(1, true);
    ui->tabWidget->setEnabled(true);
    setup_all();
}

void mainmenu::on_gametab_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(0, true);
    ui->tabWidget->setEnabled(true);
}

void mainmenu::on_tradetab_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
    ui->tabWidget->setTabEnabled(2, true);
    ui->tabWidget->setEnabled(true);
}

void mainmenu::on_gametab2_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(0, true);
    ui->tabWidget->setEnabled(true);
}

void mainmenu::on_movetab_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
    ui->tabWidget->setTabEnabled(3, true);
    ui->tabWidget->setEnabled(true);
}

void mainmenu::on_gametab3_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(0, true);
    ui->tabWidget->setEnabled(true);
}

// info ui
void mainmenu::setup_all()
{
    ui->nickname->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ui->nickname->setText( "Name: " + player.get_nickname() );
    ui->money->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ui->money->setText( "Money: " + QString::number(player.get_money_amount()) ); //td::to_string(player.get_money_amount()
    ui->fame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ui->fame->setText( "Fame: " + QString::number(player.get_fame_amount()) );
    ui->weight->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ui->weight->setText( "Weight: " + QString::number(player.get_weight_amount()) );
    ui->coalLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ui->coalLabel->setText( "Coal: " + QString::number(player.get_item_amount(0)) );
    ui->stoneLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ui->stoneLabel->setText( "Stone: " + QString::number(player.get_item_amount(1)) );
    ui->woodLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ui->woodLabel->setText( "Wood: " + QString::number(player.get_item_amount(2)) );
    ui->wheatLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ui->wheatLabel->setText( "Wheat: " + QString::number(player.get_item_amount(3)) );
    ui->cityLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ui->cityLabel->setText( "Settlement: " + settlement.get_settlement_name() );
    ui->classLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ui->classLabel->setText( "Class: " + settlement.get_settlement_property_name(settlement.get_settlement_property()) );
    ui->statusLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ui->statusLabel->setText( "Status: " + settlement.get_settlement_situation_name(settlement.get_settlement_situation()) );
}


void mainmenu::on_coal_button_clicked()
{
    _index = 0;
}

void mainmenu::on_stone_button_clicked()
{
    _index = 1;
}

void mainmenu::on_wood_button_clicked()
{
    _index = 2;
}

void mainmenu::on_wheat_button_clicked()
{
    _index = 3;
}

void mainmenu::on_buy_button_clicked()
{
    QString amountstr = ui->spinBox_amount->text();
    unsigned short amount = amountstr.toInt();
    int check = settlement.buy(_index, amount, &player);
    if (check == 0)
    {
        ui->tabWidget->setCurrentIndex(1);
        ui->tabWidget->setTabEnabled(1, true);
        ui->tabWidget->setEnabled(true);
        mainmenu::setup_all();
    }
}

void mainmenu::on_sell_button_clicked()
{
    QString amountstr = ui->spinBox_amount->text();
    unsigned short amount = amountstr.toInt();
    settlement.sell(_index, amount, &player);

    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setTabEnabled(1, true);
    ui->tabWidget->setEnabled(true);
    mainmenu::setup_all();
}

// depart
void mainmenu::on_move_button_clicked()
{
    // read file until settlement_number's string
    short local_i = 0;
    QString line = "0 0 1345 0345 Fist";
    QString FILENAME = ":/assets/Assets/settlement.txt";
    QFile f(FILENAME);
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&f);
    while (local_i <= settlement_number) // !stream.atEnd() till the end
    {
         line = stream.readLine();
         local_i++;
    }
    string _string = line.toStdString();
    f.close();

    //parse the string and make variables
    string substring = _string.substr(0, 1);
    QString qsubstring = QString::fromStdString(substring);
    unsigned int property = qsubstring.toUInt();

    substring = _string.substr(2, 1);
    qsubstring = QString::fromStdString(substring);
    unsigned int situation = qsubstring.toUInt();

    substring = _string.substr(4, 4);
    qsubstring = QString::fromStdString(substring);
    unsigned int x = qsubstring.toUInt();

    substring = _string.substr(9, 4);
    qsubstring = QString::fromStdString(substring);
    unsigned int y = qsubstring.toUInt();

    substring = _string.substr(14);
    QString name = QString::fromStdString(substring);

    settlement.create_settlement(property, situation, name, x, y); //property, situation, market, name, x, y

    // pay gold for move
    int p_x = player.get_x_posision();
    int p_y = player.get_x_posision();
    int move_price = sqrt( (x-p_x)*(x-p_x) + (y-p_y)*(y-p_y) ) / 50;
    player.set_money_amount(player.get_money_amount() - move_price);
    player.set_posision(x, y);

    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setTabEnabled(1, true);
    ui->tabWidget->setEnabled(true);
    mainmenu::setup_all();
}

void mainmenu::on_settlement_1_clicked()
{
    settlement_number = 0;
}

void mainmenu::on_settlement_2_clicked()
{
    settlement_number = 1;
}

void mainmenu::on_settlement_3_clicked()
{
    settlement_number = 2;
}

void mainmenu::on_settlement_4_clicked()
{
    settlement_number = 3;
}

void mainmenu::on_settlement_5_clicked()
{
    settlement_number = 4;
}

void mainmenu::on_settlement_6_clicked()
{
    settlement_number = 5;
}

void mainmenu::on_settlement_7_clicked()
{
    settlement_number = 6;
}

void mainmenu::on_settlement_8_clicked()
{
    settlement_number = 7;
}

void mainmenu::on_game_exit_clicked()
{
    mainmenu::close();
}

//end
