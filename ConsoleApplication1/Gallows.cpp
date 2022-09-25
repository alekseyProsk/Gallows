#include <iostream>
#include <windows.h>
#include <cstring>
#include "Gallows.h"

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void Gallows::Printword() //����� �������� ����� � ������ �� �����
{
	
	cout << "���������� �����\n ";
	for (int i = 0; i < size; i++)
	{
		secretword[i] = 95;// ���������� �������� �������� -
		cout << secretword[i] << " ";
	}
	cout << endl;
	cout << "\n������ ";
	for (int i = 0; i < size; i++)
	{
		mistake[i] = 95;
		cout << mistake[i] << " ";
	}
	cout << endl;
}

void Gallows::Enterword() // ���������� ����������� �����
{
	int setup;

	cout << "1-��������� �����\n2-������ ����� ������\n";//����� ������ ���� ��/ ��
	cin >> setup;

	switch (setup)
	{
	case 1:
	{
	Generateword(); // ���� ����� �����������
	}break;
	case 2:
	{
		cout << "������� ���� � ����� �����?\n"; // ���� ����� ������ ����
		cin >> size;
		cout << "������� �����\n";
		cin >> word;

		system("cls");
	}break;
	}
	
	
}

void Gallows::Checkrule() // ���� ����� � �������� �� ������
{
	
	int who;
	static int l = 0;
	char symbol;
	cout << "��� ����� ����������? ��(1)/��(2)\n";
	cin >> who;
	
	if (who == 1)
	{
		cout << "������� �����\n ";// ��������� ��
		cin >> symbol;
	}
	else 
	{
		char* alph = new char[]{"��������������������������������"};
		cout << "��������� ������\n ";//�������� ��
		symbol = alph[rand() % 34];
	}
	
		
	
	
		bool isadded = false;// ����, ��� ��� ������� �������
		for (int i = 0; i < size; i++)
		{	
			for (int j = 0; j < size; j++)
			{
				if (symbol == word[j]) //���� ��������� ������ ����� ������� �� ����������� �����, �������� �����
				{
					secretword[j] = symbol;
					isadded = true;
				}
			}
			if (isadded == true) // ���� ������ ������, ���� �������� ���������������
				break;
			else
			{
				mistake[l] = symbol;// ���� �������� �� ������, ��������� ������ ������������� ������� ������
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
				
						cout << "�� ���������";
				
					exit(0);
				}
				break;
		};
	}
}


bool Gallows::checkwin()//�������� �� ������
{
	for (int i = 0; i < size; i++)
	{
		if (word[i] != secretword[i])
			return false;
	}
	return true;
}

void Gallows::Generateword() // ���� �� ����� ������� ����, �� ���������� ����� ������ �� ������ ����
{
	char easy[4][4] = { "���","���","���","���" }; // ������� �������� � �������� ���������
	char normal[4][7] = { "������","������","������","������" };
	char hard[4][10] = { "���������","���������","���������","���������" };

	int setup;
	cout << "�������� ������� ���������\n";
	cout << "1 - ������ (����� �� 3� ����)\n";
	cout << "2 - �������(����� �� 6�� ����)\n";
	cout << "3 - �������(����� �� 9�� ����)\n";
	cin >> setup;
	switch (setup)
	{
		case 1:
		{
			size = 3;
			strcpy(word, easy[rand() % 4]);//����� ���������� ����� ������ �� ������ ��������� 
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

void Gallows::checkword()// ����� �������� ��������� ���� �� �����
{
	cout << "�����\n";
	for (int i = 0; i < size; i++)
	{
		cout << secretword[i] << " ";
	}
	cout << "\n������ ";
	for (int i = 0; i < size; i++)
	{
		cout << mistake[i] << " ";
	}
	cout << endl;
}

void Gallows::runGallows() //���� ������������������ ����
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
	
	cout << "�� ��������";
	exit(0);

}
	



