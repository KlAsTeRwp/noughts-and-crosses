#include<QApplication>
#include<QMainWindow>
#include<QTextStream>
#include<gamefield.h>

int main(int argc, char *argv[])
{
    QApplication Application(argc, argv);
    QWidget Main;
    GameField *Field = new GameField(&Main);
   // Main.resize(Field.size());
    Main.show();
    return Application.exec();
}
