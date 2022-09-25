#include <iostream>
#include <cmath>
#include <windows.h.>
#include "Gallows.h"


using namespace std;





int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251); //Чтение русских букв
    SetConsoleOutputCP(1251); // Вывод русских букв
    Gallows game; // Игра
    game.runGallows();
   
    return 0;
}