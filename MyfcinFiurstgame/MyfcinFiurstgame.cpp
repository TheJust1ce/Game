// MyfcinFiurstgame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool Check(char massiv[9], char xoro);
void Field(char massiv[9]);
void StepX(char(&massiv)[9]);
void StepO(char(&massiv)[9]);
bool Check4win(char massiv[9]);

int main()
{
	setlocale(LC_ALL, "RUS");

	char position[9];
	for (int i = 0; i < 9; i++)
		position[i] = ' ';
	Field(position);

	for (int i = 0; i < 9; i++)
		if (i % 2 == 0)
		{
			StepX(position);
			Field(position);
			if (Check4win(position) == true)
				break;
		}
		else
		{
			StepO(position);
			Field(position);
			if (Check4win(position) == true)
				break;
		}

	cout << "Спасибо за игру" << endl;
	system("pause");
	return 0;
}

void Field(char massiv[9])
{
	system("cls");
	cout << "\n " << massiv[0] << " | " << massiv[1] << " | " << massiv[2] << endl;
	cout << " " << "-" << " + " << "-" << " + " << "-" << endl;
	cout << " " << massiv[3] << " | " << massiv[4] << " | " << massiv[5] << endl;
	cout << " " << "-" << " + " << "-" << " + " << "-" << endl;
	cout << " " << massiv[6] << " | " << massiv[7] << " | " << massiv[8] << endl;
	cout << endl;
}

void StepX(char(&massiv)[9])
{
	int x, y;
	cout << "Ход игрока 1" << "\nВведите коордиинаты ячейки, в которую хотите поставить 'x': " << endl;
	cin >> x >> y;

	if (((x > 3) || (x < 1)) || ((y > 3) || (y < 1)))
	{
		cout << "Неверно введены координаты ячйки" << endl;
		StepX(massiv);
	}

	int coor = (x - 1) * 3 + y - 1;

	if (massiv[coor] == ' ')
		massiv[coor] = 'x';
	else
	{
		cout << "Недопустимый ход" << endl;
		StepX(massiv);
	}
}

void StepO(char(&massiv)[9])
{
	int x, y;
	cout << "Ход игрока 2" << "\nВведите коордиинаты ячейки, в которую хотите поставить 'o': " << endl;
	cin >> x >> y;

	if (((x > 3) || (x < 1)) || ((y > 3) || (y < 1)))
	{
		cout << "Неверно введены координаты ячйки" << endl;
		StepO(massiv);
	}

	int coor = (x - 1) * 3 + y - 1;

	if (massiv[coor] == ' ')
		massiv[coor] = 'o';
	else
	{
		cout << "Недопустимый ход" << endl;
		StepO(massiv);
	}
}

bool Check4win(char massiv[9])
{
	bool wonx = false, wono = false, empty = false;
	if (Check(massiv, 'x') == true)
	{
		cout << "Выиграл игрок 1" << endl;
		wonx = true;
	}
	if (Check(massiv, 'o') == true)
	{
		cout << "Выиграл игрок 2" << endl;
		wono = true;
	}

	for (int i = 0; i < 9; i++)
		if (massiv[i] == ' ')
		{
			empty = true;
			break;
		}
	if ((!empty) && (wonx == false) && (wono == false))
	{
		cout << "Ничья" << endl;
		return true;
	}

	if ((wonx == true) || (wono == true))
		return true;
}

bool Check(char massiv[9], char xoro)
{
	for (int i = 0; i < 9; i = i + 3)
		if (((massiv[i] == xoro) && (massiv[i + 1] == xoro) && (massiv[i + 2] == xoro)) || ((massiv[i / 3] == xoro) && (massiv[i / 3 + 3] == xoro) && (massiv[i / 3 + 6] == xoro)))
			return  true;
	if (((massiv[0] == xoro) && (massiv[4] == xoro) && (massiv[8] == xoro)) || ((massiv[2] == xoro) && (massiv[4] == xoro) && (massiv[6] == xoro)))
		return true;
}

