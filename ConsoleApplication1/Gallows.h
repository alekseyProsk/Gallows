#pragma once






class Gallows
{
	int size = 5;

	char* word = new char[size]; //���������� �����	
	char* secretword = new char[size]; //������������ �����	
	char* mistake = new char[size];// ������ (����� ������� ������ �������, �� ��� �������� =) )

	void Enterword();// ���������� ����������� �����
	void Checkrule();// ���� ����� � �������� �� ������
	void Printword();//����� �������� ����� � ������ �� �����
	void checkword();// ����� �������� ��������� ���� �� �����
	bool checkwin();//�������� �� ������
	void Generateword();// ���� �� ����� ������� ����, �� ���������� ����� ������ �� ������ ����
	

public:

	
	void runGallows(); //���� ������������������ ����

};

