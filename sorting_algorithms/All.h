#pragma once

#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <ctime>
#include <chrono>
#include <algorithm>

// пространство имен для удобной настройки отрисовок меню
namespace FrontEnd
{
	const byte INDENT_BY_X_LOGO = 15;
	const byte INDENT_BY_Y_LOGO = 0;

	const byte INDENT_BY_X_MENU_1_LINES = 60;
	const byte INDENT_BY_Y_MENU_1_LINES = 11;
	const byte NUMBER_OF_LINES_IN_MENU_1 = 7;

	const byte INDENT_BY_X_MENU_2_LINES = 60;
	const byte INDENT_BY_Y_MENU_2_LINES = 12;
	const byte NUMBER_OF_LINES_IN_MENU_2 = 6;

	const byte INDENT_BY_X_MENU_3_LINES = 60;
	const byte INDENT_BY_Y_MENU_3_LINES = 12;
	const byte NUMBER_OF_LINES_IN_MENU_3 = 3;

	const byte INDENT_BY_X_MENU_4_LINES = 60;
	const byte INDENT_BY_Y_MENU_4_LINES = 12;
	const byte NUMBER_OF_LINES_IN_MENU_4 = 5;

	const bool ENDLESS_MOVEMENT_IN_THE_MENU = false;

	const byte NUMBER_OF_COLUMNS = 16;
}

// подключаем пространства
using namespace std;
using namespace chrono;
using namespace FrontEnd;

// структура записи журнала сортировок
struct Data
{
	int number = 0; // порядковый номер сортировки
	string sort; // название сортировки
	int number_of_elements = 0; // количество элементов, участвовавших в сортировке
	size_t working_time = 0; // время, за которое происходила сортировка
};
// компаратор для функции sort библиотеки algorithm
struct CompareData
{
	int what;
	bool Compare(const struct Data& f, const struct Data& s)
	{
		switch (abs(what))
		{
		case 1: return f.number < s.number;
		case 2: return f.sort < s.sort;
		case 3: return f.number_of_elements < s.number_of_elements;
		case 4: return f.working_time < s.working_time;
		default: return false;
		}
	}
public:
	CompareData(int what) : what(what) {}
	bool operator()(const struct Data& f, const struct Data& s) {
		bool ret = Compare(f, s);
		return what >= 0 ? ret : !ret;
	}
};
// класс перечисления для форм
enum class Form
{
	INITIAL, // главная
	CREATION, // создания массива
	ORDERING, // упорядочивания массива
	SORTING // сортировки массива
};
// класс перечисления для клавиш
enum class Key
{
	W,
	A,
	S,
	D,
	UP,
	LEFT,
	DOWN,
	RIGHT,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	ENTER,
	ESC,
	CTRL_S,
	CTRL_H,
	F1,
	PLUS,
	MINUS,
	OTHER
};

// псевдонимы типов для сокращения названия вектора
typedef vector <int> vec_i;
typedef vector <Data> vec_d;