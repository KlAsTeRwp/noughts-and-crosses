#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include<QWidget>
#include<QPushButton>
#include<QGridLayout>
#include<QLabel>
#include<QTextStream>
#include<gamebutton.h>
class GameField: public QWidget
{
Q_OBJECT
private:
    QTextStream debug{stdout};
    int Player{}; //игрок, которому предстоит ходить
    GameButton *button[9]; //массив из указателей на игровые кнопки
    QGridLayout *Grid; // указатель на объект класса QgridLayout
    QLabel *Label; // указатель на объект QLabel
    char Field[3][3]{{' '}}; // двумерный массив типа char. в нём хранятся состояния кнопок
    bool End{false}; // переменная типа bool, указывающая, есть ли ещё поля, доступные для изменения
public:
    explicit GameField(QWidget *parent = 0);
    ~GameField();
    bool scanLine(int, bool);//проверка линии (вертикальной или горизонтальной)
    bool scanDiag(int); //проверка диаогнали (основной или побочной)
    bool scanField(int,int); //проверка поля
    int getPlayer();
    QString getLabelText();
    char getFieldEl(int, int);
    bool getEnd();
    bool setEnd(bool);
    bool setPlayer(int);
    void setLabelText(QString);
    bool setFieldEl(char,int,int);
public slots:
    void changeField(int,int); //изменение массива в соответсвие с нажатой клавишей
    void isEnd(int, int, int); // проверка поля
signals:
    void turned(int,int,int); //сигнал, сообщающий о конце хода
    void check(int,int,int); //сигнал, для инициализации проверки
};

#endif // GAMEFIELD_H
