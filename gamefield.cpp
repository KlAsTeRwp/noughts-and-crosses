#include "gamefield.h"

GameField::GameField(QWidget *parent):
    QWidget(parent)
{
    Grid = new QGridLayout(parent);
    Label = new QLabel;
    setPlayer(0);
    Grid->addWidget(Label,3,1);
    for (int i{}; i<3; i++)
    {
        for (int j{}; j<3; j++)
        {
            button[i*3+j] = new GameButton(parent, i,j);
            Grid->addWidget(button[i*3+j], i,j);
            connect(button[i*3+j], SIGNAL(clicked(int,int)), this, SLOT(changeField(int,int)));
            connect(this, SIGNAL(turned(int,int,int)), button[i*3+j], SLOT(changeButton(int,int,int)));
            connect(this, SIGNAL(check(int, int, int)), this, SLOT(isEnd(int, int, int)));
        }
    }
}

void GameField::changeField(int X, int Y)
{
    emit turned(getPlayer(), X,Y);
    if(getPlayer() == 0)
    {
        setFieldEl('O', X, Y);
        setPlayer(1);
    }
    else
    {
        setFieldEl('X', X,Y);
        setPlayer(0);
    }
    isEnd(getPlayer(), X, Y);
}


bool GameField::scanField(int X, int Y)
{
    bool Win = false;
    if ((X+Y)%2 == 0)
    {
        if (X+Y == 2)
            Win = scanDiag(2);
        if (X == Y)
            Win = (Win || scanDiag(1));
    }
    Win = (Win || scanLine(Y, false) || scanLine(X, true));
    return Win;
}

bool GameField::scanLine(int X, bool Vertical)
{
    if (Vertical)
    {
        for(int i{}; i<3; i++)
        {
            if (i>0 && getFieldEl(X,i) != getFieldEl(X,i-1))
            {
                return false;
            }
        }
    }
    else
    {
        for(int i{}; i<3; i++)
        {
            if (i>0 && getFieldEl(i,X) != getFieldEl(i-1,X))
            {
                return false;
            }
        }
    }
    return true;
}

bool GameField::scanDiag(int X)
{
    if (X == 1)
        for(int i{}; i<3; i++)
            {
                if (i>0 && getFieldEl(i,i) != getFieldEl(i-1,i-1))
                    return false;
            }
    if (X == 2)
        for(int i{}; i<3; i++)
            {
                if (i>0 && getFieldEl(2-i, i) != getFieldEl(3-i, i-1))
                    return false;
            }
    return true;
}

void GameField::isEnd(int Player, int X, int Y)
{
    if (scanField(X,Y))
    {
        setLabelText("Победил игрок " + QString::number(getPlayer()+1) + "\n Конец игры");
        setEnd(true);
    }
}

int GameField::getPlayer()
{
    return this->Player;
}

QString GameField::getLabelText()
{
    return this->Label->text();
}

char GameField::getFieldEl(int X, int Y)
{
    return this->Field[X][Y];
}

bool GameField::setPlayer(int Player)
{
    Label->setText("Ход игрока " + QString::number(Player));
    return this->Player = Player;
}

void GameField::setLabelText(QString Text)
{
    return this->Label->setText(Text);
}

bool GameField::setFieldEl(char Value, int X ,int Y)
{
    return this->Field[X][Y] = Value;
}

bool GameField::getEnd()
{
    return this->End;
}

bool GameField::setEnd(bool End)
{
    for (int i{}; i<9; i++)
    {
        button[i]->setEnabled(false);
    }
    return this->End = End;
}

GameField::~GameField()
{
    delete [] button;
    delete Grid;
    delete Label;
}
