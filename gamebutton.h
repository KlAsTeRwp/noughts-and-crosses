#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include<QPushButton>

class GameButton : public QPushButton
{
Q_OBJECT
public:
    explicit GameButton(QWidget *parent = 0, int x = 0, int y = 0);
    ~GameButton();
    int GetX();
    int GetY();
    bool SetX(int);
    bool SetY(int);
private:
    int x{}, y{};
public slots:
    void changeButton(int,int,int);
    void turn();
signals:
    void clicked(int, int);
};

#endif // GAMEBUTTON_H
