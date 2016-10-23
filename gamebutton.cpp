#include "gamebutton.h"

GameButton::GameButton(QWidget *parent, int x, int y):
    QPushButton(parent)
{
    SetX(x);
    SetY(y);
    connect(this, SIGNAL(clicked()), this, SLOT(turn()));
}

int GameButton::GetX()
{
    return this->x;
}

int GameButton::GetY()
{
    return this->y;
}

bool GameButton::SetX(int X)
{
    return this->x = X;
}

bool GameButton::SetY(int Y)
{
    return this->y = Y;
}

void GameButton::changeButton(int Player, int X, int Y) //в качестве параметра передается число, указывающее походившего игрока и числа являющиеся координатами кнопки
{
    if (GetX() == X && GetY() == Y)
    {
        if (Player == 0 && isEnabled())
            setText("X");
        else if(isEnabled())
            setText("O");
        setEnabled(false);
    }
}

void GameButton::turn() //при вызове данного слота высылается сигнал, в котором передаются координаты нажатой кнопки
{
    emit clicked(GetX(), GetY());
}

GameButton::~GameButton()
{}

