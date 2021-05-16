#ifndef TRADESCENE_H
#define TRADESCENE_H

#include <QDialog>

namespace Ui {
class tradescene;
}

class tradescene : public QDialog
{
    Q_OBJECT

public:
    explicit tradescene(QWidget *parent = nullptr);
    ~tradescene();

private slots:
    void on_checkBox_1_pressed();

    void on_checkBox_2_pressed();

    void on_checkBox_3_pressed();

    void on_checkBox_4_pressed();

private:
    Ui::tradescene *ui;
};

#endif // TRADESCENE_H
