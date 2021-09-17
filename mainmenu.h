#ifndef MAINMENU_H
#define MAINMENU_H

#include<QDialog>
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

QT_BEGIN_NAMESPACE
namespace Ui { class mainmenu; }
QT_END_NAMESPACE

class mainmenu : public QDialog
{
    Q_OBJECT

    public:
        mainmenu(QWidget *parent = nullptr);
        ~mainmenu();
        void setup_all();

        void set_data();

    private slots:

        void on_start_clicked();

        void on_about_clicked();

        void on_exit_clicked();

        void on_charactertab_clicked();

        void on_gametab_clicked();

        void on_gametab2_clicked();

        void on_gametab3_clicked();

        void on_tradetab_clicked();

        void on_movetab_clicked();

        void on_move_button_clicked();

        void on_buy_button_clicked();

        void on_sell_button_clicked();

        void on_coal_button_clicked();

        void on_stone_button_clicked();

        void on_wood_button_clicked();

        void on_wheat_button_clicked();

        void on_settlement_1_clicked();

        void on_settlement_2_clicked();

        void on_settlement_3_clicked();

        void on_settlement_4_clicked();

        void on_settlement_5_clicked();

        void on_settlement_6_clicked();

        void on_settlement_7_clicked();

        void on_settlement_8_clicked();

        void on_game_exit_clicked();

private:
        Ui::mainmenu *ui;
};

#endif // MAINMENU_H
