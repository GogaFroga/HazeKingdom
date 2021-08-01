#include<QWidget>
#include<QObject>
#include<QCloseEvent>
#include<QEvent>
#include<QCoreApplication>
#include<QKeyEvent>
#include"mainmenu.h"
#include"ui_mainmenu.h"
#include"settlement_class.h"
#include"player_class.h"

Market market;
Player player;

mainmenu::mainmenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainmenu)
{
    ui->setupUi(this);
    setGeometry(0,0,800,600);
    ui->mainmenu_tab->hide();
    ui->game_tab->hide();
    ui->player_tab->hide();
}

mainmenu::~mainmenu()
{
    delete ui;
}
/*
void mainmenu::setup_all()
{
    ui->start->setGeometry(0, 0, 0, 0);
    ui->about->setGeometry(0, 0, 0, 0);
    ui->rules->setGeometry(0, 0, 0, 0);
    ui->exit->setGeometry(0, 0, 0, 0);
    ui->setupUi(this);
}*/


void mainmenu::on_start_clicked()
{

    QString imagename = "Wmap.jpg";
    QImage image(imagename);
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsView* view = new QGraphicsView(scene);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    view->show();
    //setup_all();
}


void mainmenu::on_about_clicked()
{
    if (!ui->rules->isEnabled())
    {
        ui->rules->setEnabled(true);
        ui->rules->setText("Автор: Вакуленко Артур М8О-111Б\nСуть: Вы перемещаетесь между городами и торгуете.\nБла-бла-бла.");
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


/*/first settlement
Settlement FirstSettlement;
QPushButton* settlement1 = FirstSettlement.create_settlement(1, 0, market, "City1", 633, 310);
scene->addWidget(settlement1);
//second settlement
Settlement SecondSettlement;
QPushButton* settlement2 = SecondSettlement.create_settlement(1, 0, market, "City2", 1033, 320);
scene->addWidget(settlement2);*/


/*/setting character stats
void mainmenu::set_data(QGraphicsScene* scene)
{
    QLabel *nickname = new QLabel();
    nickname->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    nickname->setText( "Name: " + player.get_nickname() );
    nickname->setAlignment(Qt::AlignLeft);
    nickname->move(50, 0);
    scene->addWidget(nickname);

    QLabel *money = new QLabel();
    money->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    money->setText( "Money: " + QString::number(player.get_money_amount()) ); //td::to_string(player.get_money_amount()
    money->setAlignment(Qt::AlignLeft);
    money->move(200, 0);
    scene->addWidget(money);

    QLabel *fame = new QLabel();
    fame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    fame->setText( "Fame: " + QString::number(player.get_fame_amount()) );
    fame->setAlignment(Qt::AlignLeft);
    fame->move(300, 0);
    scene->addWidget(fame);

    QLabel *weight = new QLabel();
    weight->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    weight->setText( "Weight: " + QString::number(player.get_weight_amount()) );
    weight->setAlignment(Qt::AlignLeft);
    weight->move(400, 0);
    scene->addWidget(weight);

    QLabel *coal = new QLabel();
    coal->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    coal->setText( "Coal: " + QString::number(player.get_item_amount(0)) );
    coal->setAlignment(Qt::AlignLeft);
    coal->move(470, 0);
    scene->addWidget(coal);

    QLabel *stone = new QLabel();
    stone->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    stone->setText( "Stone: " + QString::number(player.get_item_amount(1)) );
    stone->setAlignment(Qt::AlignLeft);
    stone->move(530, 0);
    scene->addWidget(stone);

    QLabel *wood = new QLabel();
    wood->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    wood->setText( "Wood: " + QString::number(player.get_item_amount(2)) );
    wood->setAlignment(Qt::AlignLeft);
    wood->move(590, 0);
    scene->addWidget(wood);

    QLabel *wheat = new QLabel();
    wheat->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    wheat->setText( "Wheat: " + QString::number(player.get_item_amount(3)) );
    wheat->setAlignment(Qt::AlignLeft);
    wheat->move(650, 0);
    scene->addWidget(wheat);
}
*/
