#include <iostream>
#include <windows.h>
#include <cstring>
#include "Gallows.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void Gallows::Printword() //Вывод скрытого слова и ошибок на экран
{
	
	cout << "Загаданное слово\n ";
	for (int i = 0; i < size; i++)
	{
		secretword[i] = 95;// Заполнение массивов символом -
		cout << secretword[i] << " ";
	}
	cout << endl;
	cout << "\nОшибки ";
	for (int i = 0; i < size; i++)
	{
		mistake[i] = 95;
		cout << mistake[i] << " ";
	}
	cout << endl;
}

void Gallows::Enterword() // заполнение загаданного слова
{
	int setup;

	cout << "1-Рандомное слово\n2-Ввести слово самому\n";//выбор режима игры ВЫ/ ИИ
	cin >> setup;

	switch (setup)
	{
	case 1:
	{
	Generateword(); // Если хотим зарандомить
	}break;
	case 2:
	{
		cout << "Сколько букв в вашем слове?\n"; // Если хотим ввести сами
		cin >> size;
		cout << "Введите слово\n";
		cin >> word;

		system("cls");
	}break;
	}
	
	
}

void Gallows::Checkrule() // Ввод буквы и проверка на ошибки
{
	
	int who;
	static int l = 0;
	char symbol;
	cout << "Кто будет отгадывать? ВЫ(1)/ИИ(2)\n";
	cin >> who;
	
	if (who == 1)
	{
		cout << "Введите букву\n ";// Выбираете вы
		cin >> symbol;
	}
	else 
	{
		char* alph = new char[]{"абвгдеёжзийклмнопрстуфхцчшщъыьэюя"};
		cout << "Компьютер вводит\n ";//Рандомит ИИ
		symbol = alph[rand() % 34];
	}
	
		
	
	
		bool isadded = false;// флаг, что все символы найдены
		for (int i = 0; i < size; i++)
		{	
			for (int j = 0; j < size; j++)
			{
				if (symbol == word[j]) //Если введенный символ равен символу из загаданного слова, проверка верна
				{
					secretword[j] = symbol;
					isadded = true;
				}
			}
			if (isadded == true) // Если символ найден, цикл проверки останавливается
				break;
			else
			{
				mistake[l] = symbol;// Если проверка не прошла, введенный символ присваивается массиву ошибок
				l++;
				if (l == 1)
				{
					cout << "\n";
					cout << "\n";
					cout << "\n";
					cout << "\n";
					cout << "\n";
					cout << "\n";
					cout << "\n";
					cout << "\n";
					cout << "\n";
					cout << "\n";
					cout << "\n";
					cout << "\n";
					cout << " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
					
				}
				if (l == 2)
				{
					cout << "        @@@@@@@@@@@@@@@@\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
						cout << " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
					
				}
				if (l == 3)
				{
					cout << "        @@@@@@@@@@@@@@@@\n";
					cout << "        |             @\n";
					cout << "        |             @\n";
					cout << "        |             @\n";
					cout << "        |             @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
					
				}
				if (l == 4)
				{
					cout << "        @@@@@@@@@@@@@@@@\n";
					cout << "        |             @\n";
					cout << "        |             @\n";
					cout << "        |             @\n";
					cout << "        |             @\n";
					cout << "        0             @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
				}
				if (l == 5)
				{
					cout << "        @@@@@@@@@@@@@@@@\n";
					cout << "        |             @\n";
					cout << "        |             @\n";
					cout << "        |             @\n";
					cout << "        |             @\n";
					cout << "        0             @\n";
					cout << "       / \\            @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
				}
				if (l == 6)
				{
					cout << "        @@@@@@@@@@@@@@@@\n";
					cout << "        |             @\n";
					cout << "        |             @\n";
					cout << "        |             @\n";
					cout << "        |             @\n";
					cout << "        0             @\n";
					cout << "       / \\            @\n";
					cout << "        |             @\n";
					cout << "       / \\            @\n";
					cout << "                      @\n";
					cout << "                      @\n";
					cout << " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
				
						cout << "ВЫ ПРОИГРАЛИ";
				
					exit(0);
				}
				break;
		};
	}
}


bool Gallows::checkwin()//Проверка на победу
{
	for (int i = 0; i < size; i++)
	{
		if (word[i] != secretword[i])
			return false;
	}
	return true;
}

void Gallows::Generateword() // Если не хотим вводить сами, то загадываем слово исходя из режима игры
{
	char easy[4][4] = { "лол","мир","душ","мяч" }; // Массивы словарей с уровнями сложности
	char normal[4][7] = { "алтарь","ателье","аншлаг","аммиак" };
	char hard[4][10] = { "бижутерия","диагональ","кинотеатр","живописец" };

	int setup;
	cout << "Выберите уровень сложности\n";
	cout << "1 - Легкий (Слова из 3х букв)\n";
	cout << "2 - Средний(Слова из 6ти букв)\n";
	cout << "3 - Тяжелый(Слова из 9ти букв)\n";
	cin >> setup;
	switch (setup)
	{
		case 1:
		{
			size = 3;
			strcpy(word, easy[rand() % 4]);//выбор ранжомного слова исходя из уровня сложности 
		}break;
		case 2:
		{
			size = 6;
			strcpy(word, normal[rand() % 4]);
		}break;
		case 3:
		{
			size = 9;
			strcpy(word, hard[rand() % 4]);
		}

	}
	
}

void Gallows::checkword()// Вывод текущего прогресса игры на экран
{
	cout << "Слово\n";
	for (int i = 0; i < size; i++)
	{
		cout << secretword[i] << " ";
	}
	cout << "\nОшибки ";
	for (int i = 0; i < size; i++)
	{
		cout << mistake[i] << " ";
	}
	cout << endl;
}

void Gallows::runGallows() //Сама последовательность игры
{
	
	Enterword();
	Printword();
	while (checkwin() != true)
	{
		Checkrule();
		Printword();
		checkwin();
		checkword();
		
	}
	
	cout << "ВЫ ВЫИГРАЛИ";
	exit(0);

}
	



