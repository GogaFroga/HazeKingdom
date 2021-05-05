#include<iostream>
#include<string>
#include<cmath>
#include"settlement_class.h"
#include"player_class.h"

#include<QtWidgets/QApplication>
#include<QtWidgets/QGraphicsView>
#include<QtWidgets/QMainWindow>
#include<QtWidgets/QApplication>
#include<QtWidgets/QMenu>
#include<QtWidgets/QMenuBar>
#include<QtWidgets/QLayout>
#include<QtWidgets/QPushButton>
#include<QtWidgets/QWidget>
#include<QtWidgets/QGraphicsPixmapItem>
#include<QtWidgets/QGraphicsScene>
#include<QtWidgets/QScrollBar>
#include<QObject>
#include<QLabel>

Market market;
Player player;

void set_data(QGraphicsScene*);

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 1920, 1080);
    //map
    QGraphicsPixmapItem *item_map = new QGraphicsPixmapItem( QPixmap("C:/Users/User/Documents/GitHub/HazeKingdom/Assets/Wmap") );
    scene->addItem(item_map);
    set_data(scene);


    //first settlement
    Settlement FirstSettlement;
    QPushButton* settlement1 = FirstSettlement.create_settlement(1, 0, market, "City1", 633, 310);
    scene->addWidget(settlement1);
    //second settlement
    Settlement SecondSettlement;
    QPushButton* settlement2 = SecondSettlement.create_settlement(1, 0, market, "City2", 1033, 320);
    scene->addWidget(settlement2);



    QGraphicsView view(scene);
    view.showMaximized();
    return app.exec();
}



void set_data(QGraphicsScene* scene)
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

//    QLabel *coal = new QLabel();
//    weight->setFrameStyle(QFrame::Panel | QFrame::Sunken);
//    weight->setText( "Weight: " + QString::number(player.get_item_amount()) );
//    weight->setAlignment(Qt::AlignLeft);
//    weight->move(300, 0);
//    scene->addWidget(weight);
}
