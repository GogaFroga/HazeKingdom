#include "tradescene.h"
#include "ui_tradescene.h"

tradescene::tradescene(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tradescene)
{
    ui->setupUi(this);
}

tradescene::~tradescene()
{
    delete ui;
}

void tradescene::on_checkBox_1_pressed()
{

}

void tradescene::on_checkBox_2_pressed()
{

}

void tradescene::on_checkBox_3_pressed()
{

}

void tradescene::on_checkBox_4_pressed()
{

}
