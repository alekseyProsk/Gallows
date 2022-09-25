#pragma once






class Gallows
{
	int size = 5;

	char* word = new char[size]; //Загаданное слово	
	char* secretword = new char[size]; //Отгадываемое слово	
	char* mistake = new char[size];// Ошибки (можно сделать просто счетчик, но так красивее =) )

	void Enterword();// заполнение загаданного слова
	void Checkrule();// Ввод буквы и проверка на ошибки
	void Printword();//Вывод скрытого слова и ошибок на экран
	void checkword();// Вывод текущего прогресса игры на экран
	bool checkwin();//Проверка на победу
	void Generateword();// Если не хотим вводить сами, то загадываем слово исходя из режима игры
	

public:

	
	void runGallows(); //Сама последовательность игры

};

