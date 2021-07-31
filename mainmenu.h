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

        //void set_data(QGraphicsScene*);
        void set_data();

    private slots:

        void on_pushButton_clicked();

        void on_About_clicked();

        void on_exit_clicked();

    private:
        Ui::mainmenu *ui;
};

#endif // MAINMENU_H
