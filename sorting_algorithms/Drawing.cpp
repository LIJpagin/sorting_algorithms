#include "All.h" //подключаем единый заголовочный файл
#include "Sort.h" // подключаем заголовочный файл с сортировками
#include "Drawing.h" // подключаем заголовочный файл с отрисовками


#define clear system("cls") // директива препроцессора для замены часто используемой функции очистки консоли
#define pause system("pause") // директива препроцессора для замены часто используемой функции паузы


static HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE); // получение имени консоли

static string console_logo[]  = /* массив строк с лого программы                 */{
	"                       _",
	"  ___    ___    _ __  | |_     _ __    _ __    ___     __ _   _ __    __ _   _ __ ___",
	" / __|  / _ \\  | '__| | __|   | '_ \\  | '__|  / _ \\   / _` | | '__|  / _` | | '_ ` _ \\",
	" \\__ \\ | (_) | | |    | |_    | |_) | | |    | (_) | | (_| | | |    | (_| | | | | | | |",
	" |___/  \\___/  |_|     \\__|   | .__/  |_|     \\___/   \\__, | |_|     \\__,_| |_| |_| |_|",
	"                              |_|                     |___/"
};
static string console_line1[] = /* массов строк с пунктами главного меню         */{
	"Создать массив",
	"Вывести массив",
	"Упорядочить массив",
	"Отсортировать массив",
	"Журнал сортировок",
	"О программе",
	"Выход"
};
static string console_line2[] = /* массов строк с пунктами меню создания массива */{
	"Ручной ввод",
	"100",
	"1,000",
	"10,000",
	"100,000",
	"Назад"
};
static string console_line3[] = /* массов строк с пунктами меню упорядочивания   */{
	"По возрастанию",
	"По убыванию",
	"Назад"
};
static string console_line4[] = /* массов строк с пунктами меню сортировки       */{
	"Методом вставок",
	"Методом пузырька с флагом",
	"Шейкер-сортировкой",
	"Встроенным алгоритмом сортировки С++",
	"Назад"
};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ИНСТРУМЕНТЫ ДЛЯ РАБОТЫ С КОНСОЛЬЮ     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//ФУНКЦИЯ:
//template <typename T> void Print(T buf, int x, int y, byte color)
//template <typename T> void Print(T buf, byte color)
//ЦЕЛЬ: передвижение курсора консоли в строку y и столбец x, вывод в консоль строки цветом, заданным color
//ПАРАМЕТРЫ:
//buf - строка для вывода
//x - столбец в консоли
//y - строка в консоли
//color - цвет текста и фона 
template <typename T> void Print(T buf, int x, int y, byte color)
{ 
	SetConsoleTextAttribute(hndl, (WORD)((0 << 4) | color));
	COORD p = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hndl, p);
	cout << buf;
	SetConsoleTextAttribute(hndl, (WORD)((0 << 4) | 11));
}
template <typename T> void Print(T buf, int x, int y)
{
	SetConsoleTextAttribute(hndl, (WORD)((0 << 4) | 11));
	COORD p = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hndl, p);
	cout << buf;
}
template <typename T> void Print(T buf, byte color)
{
	SetConsoleTextAttribute(hndl, (WORD)((0 << 4) | color));
	cout << buf;
	SetConsoleTextAttribute(hndl, (WORD)((0 << 4) | 11));
}

/*ФУНКЦИЯ: void Color(byte color)
* ЦЕЛЬ: измение цвета выводимого в консоль текста
* ПАРАМЕТРЫ: color - цвет текста и фона
*
* ШРИФТ
* 0, 7, 8, 15 - от черного до белого
* 1, 3, 9, 11 - от синего до голубого
* 4, 12 - красный
* 2, 10 - зеленый
* 5, 13 - фиолетовый
* 6, 14 - желтый
*
* ФОН
* 0..15 - черный
* 112..127, 128..143 - серый
* 240..255 - белый
* 32..47, 160..175 - зеленый
* 16..31, 48..63, 144..159, 176..191 - синий
* 64..79, 192..207 - красный
* 80..95, 208..223 - фиолетовый
* 96..111, 224..239 - желтый
*/
void Color(byte color)
{
	SetConsoleTextAttribute(hndl, (WORD)((0 << 4) | color));
}

//ФУНКЦИЯ: GotoXY(int x, int y)
//ЦЕЛЬ: передвижение курсора консоли в строку y и столбец x
//ПАРАМЕТРЫ:
//x - столбец в консоли
//y - строка в консоли
void GotoXY(int x, int y)
{
	COORD p = { (short)x,(short)y };
	SetConsoleCursorPosition(hndl, p);
}

//ФУНКЦИЯ: string Tab(int k)
//ЦЕЛЬ: создание строки с заданным количеством табуляций
//ПАРАМЕТРЫ: k - количество табуляций
string Tab(int k)
{
	string input;
	for (int i = 0; i < k; i++)
		input += "\t";
	return input;
}

//ФУНКЦИЯ: string Enter(int k)
//ЦЕЛЬ: создание строки с заданным количеством переходов на следующую строку
//ПАРАМЕТРЫ: k - количество переходов на следующую строку
string Enter(int k)
{
	string input;
	for (int i = 0; i < k; i++)
		input += "\n";
	return input;
}

//ФУНКЦИЯ: Key GetKey()
//ЦЕЛЬ: получение значения нажатой клавиши
Key GetKey()
{
	unsigned char key[2]{};
	key[0] = _getch();
	if (key[0] == 0 || key[0] == 224)
		key[1] = _getch();

	if (key[0] == 0 && key[1] == 59) return Key::F1;
	else if (key[0] == 87 || key[0] == 119 || key[0] == 150 || key[0] == 230) return Key::W;
	else if (key[0] == 65 || key[0] == 97 || key[0] == 148 || key[0] == 228) return Key::A;
	else if (key[0] == 83 || key[0] == 115 || key[0] == 155 || key[0] == 235) return Key::S;
	else if (key[0] == 68 || key[0] == 100 || key[0] == 130 || key[0] == 162) return Key::D;
	else if (key[0] == 224 && key[1] == 72) return Key::UP;
	else if (key[0] == 224 && key[1] == 75) return Key::LEFT;
	else if (key[0] == 224 && key[1] == 80) return Key::DOWN;
	else if (key[0] == 224 && key[1] == 77) return Key::RIGHT;
	else if (key[0] == 49) return Key::KEY_1;
	else if (key[0] == 50) return Key::KEY_2;
	else if (key[0] == 51) return Key::KEY_3;
	else if (key[0] == 52) return Key::KEY_4;
	else if (key[0] == 13) return Key::ENTER;
	else if (key[0] == 27) return Key::ESC;
	else if (key[0] == 19) return Key::CTRL_S;
	else if (key[0] == 8) return Key::CTRL_H;
	else if (key[0] == 45) return Key::MINUS;
	else if (key[0] == 61) return Key::PLUS;
	return Key::OTHER;
}

//ФУНКЦИЯ: void DirectingInMenu(Key key, Form menu, int& dir_forms, byte number_of_lines)
//ЦЕЛЬ: универсальная функция для перемещения в формах меню
//ПАРАМЕТРЫ:
//key - клавиша, нажатая для перемещения в меню
//menu - форма меню, в которой происходит перемещение
//& dir_forms - указатель на переменную перемещения по формам меню
//number_of_lines - количество пунктов в форме меню
void DirectingInMenu(Key key, Form menu, int& dir_forms, byte number_of_lines) {
	if (key == Key::W || key == Key::UP)
	{
		if (dir_forms > 0)
			DrawingForms(menu, --dir_forms);
		else if (ENDLESS_MOVEMENT_IN_THE_MENU)
			DrawingForms(menu, dir_forms = number_of_lines - 1);
	}
	else if (key == Key::S || key == Key::DOWN)
	{
		if (dir_forms < number_of_lines - 1)
			DrawingForms(menu, ++dir_forms);
		else if (ENDLESS_MOVEMENT_IN_THE_MENU)
			DrawingForms(menu, dir_forms = 0);
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ОТРИСОВКА ФОРМ     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//ФУНКЦИЯ: void DrawingForms(Form menu, byte line)
//ЦЕЛЬ: переход между формами
//ПАРАМЕТРЫ: 
//menu - форма для отрисовки
//line - позиция курсора в форме
void DrawingForms(Form menu, byte line)
{
	switch (menu)
	{
	case Form::INITIAL:
		DrawingTheInitialForm(line);
		break;
	case Form::CREATION:
		DrawingTheCreationForm(line);
		break;
	case Form::ORDERING:
		DrawingTheOrderingForm(line);
		break;
	case Form::SORTING:
		DrawingTheSortingForm(line);
		break;
	}
}

//ФУНКЦИЯ: void DrawingTheInitialForm(byte line)
//ЦЕЛЬ: отрисовка главного меню
//ПАРАМЕТРЫ: line - позиция курсора в форме
void DrawingTheInitialForm(byte line)
{
	clear;
	DrawingTheStatusBar("0");

	//вывод лого программы строчки 
	auto y = INDENT_BY_Y_LOGO;
	for (y; y < INDENT_BY_Y_LOGO + 6; y++)
		Print(console_logo[y], INDENT_BY_X_LOGO, y, 13);

	y = INDENT_BY_Y_MENU_1_LINES - 3;
	Print("-=    \30    =-", INDENT_BY_X_MENU_1_LINES - 6, y, 9);

	//вывод пуктов меню
	y = INDENT_BY_Y_MENU_1_LINES;
	for (auto i = 0; i < NUMBER_OF_LINES_IN_MENU_1; i++)
	{
		if (i == line)
			Print(" => " + console_line1[i] + "  ", INDENT_BY_X_MENU_1_LINES - console_line1[i].size() / 2 - 4, ++y, 95);
		else
			Print(console_line1[i], INDENT_BY_X_MENU_1_LINES - console_line1[i].size()/2, y);
		if (i == NUMBER_OF_LINES_IN_MENU_1 - 2) ++y;
		if (i == line) y++;
		y++;
	}

	y += 2;
	Print("-=    \31    =-", INDENT_BY_X_MENU_1_LINES - 6, y, 9);
}

//ФУНКЦИЯ: void DrawingTheCreationForm(byte line)
//ЦЕЛЬ: отрисовка меню создания массива
//ПАРАМЕТРЫ: line - позиция курсора в форме
void DrawingTheCreationForm(byte line)
{
	clear;
	DrawingTheStatusBar("0");
	auto y = INDENT_BY_Y_MENU_2_LINES - 2;
	Print("Выберите из какого количества элементов должен состоять массив", 28, y, 13);

	//вывод пуктов меню
	y = INDENT_BY_Y_MENU_2_LINES;
	for (auto i = 0; i < NUMBER_OF_LINES_IN_MENU_2; i++)
	{
		if (i == line)
			Print(" \4 " + console_line2[i] + "  ", INDENT_BY_X_MENU_2_LINES - console_line2[i].size() / 2 - 3, y, 95);
		else
			Print(console_line2[i], INDENT_BY_X_MENU_2_LINES - console_line2[i].size() / 2, y);
		if (i == NUMBER_OF_LINES_IN_MENU_2 - 2) ++y;
		y++;
	}
}

//ФУНКЦИЯ: void DrawingTheOrderingForm(byte line)
//ЦЕЛЬ: отрисовка меню упорядочивания массива
//ПАРАМЕТРЫ: line - позиция курсора в форме
void DrawingTheOrderingForm(byte line)
{
	clear;
	DrawingTheStatusBar("0");
	auto y = INDENT_BY_Y_MENU_3_LINES - 2;
	Print("Выберете, каким образом должен быть упорядочен массив", 33, y, 13);

	y = INDENT_BY_Y_MENU_3_LINES;
	for (auto i = 0; i < NUMBER_OF_LINES_IN_MENU_3; i++)
	{
		if (i == line)
			Print(" \4 " + console_line3[i] + "  ", INDENT_BY_X_MENU_3_LINES - console_line3[i].size() / 2 - 3, y, 95);
		else
			Print(console_line3[i], INDENT_BY_X_MENU_3_LINES - console_line3[i].size() / 2, y, 11);
		if (i == NUMBER_OF_LINES_IN_MENU_3 - 2) ++y;
		y++;
	}
}

//ФУНКЦИЯ: void DrawingTheSortingForm(byte line)
//ЦЕЛЬ: отрисовка меню сортировки массива
//ПАРАМЕТРЫ: line - позиция курсора в форме
void DrawingTheSortingForm(byte line)
{
	clear;
	DrawingTheStatusBar("0");
	auto y = INDENT_BY_Y_MENU_4_LINES - 2;
	Print("Выберете, каким образом должен быть отсортирован массив", 33, y, 13);

	y = INDENT_BY_Y_MENU_4_LINES;
	for (auto i = 0; i < NUMBER_OF_LINES_IN_MENU_4; i++)
	{
		if (i == line)
			Print(" \4 " + console_line4[i] + "  ", INDENT_BY_X_MENU_4_LINES - console_line4[i].size() / 2 - 3, y, 95);
		else
			Print(console_line4[i], INDENT_BY_X_MENU_4_LINES - console_line4[i].size() / 2, y);
		if (i == NUMBER_OF_LINES_IN_MENU_4 - 2) ++y;
		y++;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ОТРИСОВКА ИНФОРМАЦИОННЫХ ОКОН     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//ФУНКЦИЯ: void DrawingManualInput(vector <int>& mas, vector <int>& back_up_mas)
//ЦЕЛЬ: отрисовка информации при ручном вводе
//ПАРАМЕТРЫ: 
//& mas - указатель на вектор
//& back_up_mas - указатель на вектор для back up
void DrawingManualInput(vec_i& mas, vec_i& back_up_mas)
{
	long long quantity = 0;
	auto increase = 100;
	Key key = Key::W; // переменая для получения символа клавиатуры
	auto x = INDENT_BY_X_MENU_2_LINES + console_line2[0].size() / 2 + 5;
	Print("W or S", x, 11, 13);
	Print("Размер", x, 13, 13);
	Print("массива", x, 14, 13);

	x = INDENT_BY_X_MENU_2_LINES - console_line2[0].size() / 2;
	Print("A or D", x - 10, 11, 13);
	Print(" ", x - 2, 12, 95);
	Print("Дельта", x - 10, 13, 13);
	while (key != Key::ENTER && key != Key::ESC)
	{
		if (key == Key::W || key == Key::UP)
			quantity += increase;
		if (key == Key::S || key == Key::DOWN)
			if (quantity - increase > 0)
				quantity -= increase;
		if (key == Key::A || key == Key::LEFT)
			if (increase < 10000)
				increase += 100;
		if (key == Key::D || key == Key::RIGHT)
			if (increase > 100)
				increase -= 100;
		Print(" [ " + to_string(increase) + " ]", INDENT_BY_X_MENU_2_LINES - console_line2[0].size() / 2 - 12, 12, 95);
		Color(95);  cout << " ";
		Print(" [ " + to_string(quantity) + " ] ", INDENT_BY_X_MENU_2_LINES + console_line2[0].size() / 2 + 3, 12, 95);
		cout << "    ";
		key = GetKey();
	}
	if (key == Key::ENTER)
		CreateAnArray(mas, back_up_mas, quantity);
}

//ФУНКЦИЯ: void DrawingAnArray(vector <int>& mas)
//ЦЕЛЬ: отрисовка массива
//ПАРАМЕТРЫ: & mas - указатель на вектор
void DrawingAnArray(vec_i& mas)
{
	clear;
	bool flag = false;
	for (auto i = 0; i < mas.size(); i++)
	{
		if (i % NUMBER_OF_COLUMNS == 0) cout << endl;
		Color(i % 2 == 1 ? 13 : 11);
		printf("%7d", mas[i]);
		if (_kbhit()) {
			if (GetKey() == Key::ESC) {
				flag = true;
				DrawingTheInitialForm(2);
				break;
			}
		}
	}
	if (flag == false)
	{
		Color(11);
		cout << Enter(7) + Tab(5);
		pause;
	}
}

//ФУНКЦИЯ: void DrawingAnOrder(vector <int>& mas, vector <int>& back_up_mas, bool ordering)
//ЦЕЛЬ: отрисовка окна вывода упорядочивания
//ПАРАМЕТРЫ: 
//& mas - указатель на вектор
//& back_up_mas - указатель на вектор для back up
//ordering - в какую сторону необхлдимо упорядочивать
void DrawingAnOrder(vec_i& mas, vec_i& back_up_mas, bool ordering)
{
	clear;
	if (ordering)
	{
		Print("Подождите, идет упорядочивание массива по возрастанию . . .", 30, 13, 11);
		sort(mas.begin(), mas.end());
		DrawingTheStatusBar("Массив упорядочен по возрастанию");
	}
	else
	{
		Print("Подождите, идет упорядочивание массива по убыванию . . .", 30, 13, 11);
		sort(mas.rbegin(), mas.rend());
		DrawingTheStatusBar("Массив упорядочен по убыванию");
	}
	back_up_mas = mas;
	Print("Упорядочивание по возрастанию завершено!", 30, 14, 9);
	GotoXY(30, 16);
	pause;
}

//ФУНКЦИЯ: void DrawingTheSortingOperation(string name_sort, void sort(vector <int>& mas), vector <Data>& SortingLog, vector <int>& mas, vector <int>& back_up_mas)
//ЦЕЛЬ: отрисовка информации при сортировке
//ПАРАМЕТРЫ: 
//name_sort - имя сортировки
//sort(& mas) -  функция с параметром
//SortingLog - указатель на вектор истории сортировок
//& mas - указатель на вектор
//& back_up_mas - указатель на вектор для back up
void DrawingTheSortingOperation(string name_sort, void sort(vec_i& mas), vec_d& SortingLog, vec_i& mas, vec_i& back_up_mas)
{
	clear;
	Print("Подождите, идет сортировка " + name_sort + ". . .", 30, 13, 11);
	DrawingTheStatusBar("Идет сортировка значений элементов массива");

	auto duration = TimeMeasurement(sort, mas, back_up_mas);

	Print("Сортировка завершена за время ", 30, 14, 9);
	NewEntryInTheSortingLog(SortingLog, name_sort, mas.size(), duration);
	Color(9);

	string number = to_string(duration / 1000);
	string result;
	for (auto i = 0; i < number.size(); i++)
	{
		for (auto j = 0; j < 3; j++)
		{
			if (i < number.size()) result += number[i];
			i++;
			if ((number.size() - i) % 3 == 0) result += ' ';
		}
		i--;
	}
	cout << result << "мкс";
	DrawingTheStatusBar("Массив в " + to_string(mas.size()) + " элементов отсортирован " + name_sort + " за " + result + "мкс");
	Color(11);
	GotoXY(30, 16);
	pause;
}

//ФУНКЦИЯ: void DrawingHint()
//ЦЕЛЬ: отрисовка окна по управлению и "О программе" в консоль при нажатии на клавишу F1
void DrawingHint()
{
	clear;
	cout << "Это курсовая работа за 2 семестр по курсу Информатика\n";
	cout << "Курсовую работу выполнил студент группы 1043 Шпагин Даниил Дмитриевич\n";
	cout << "Перемещение по пунктам меню осуществляется клавишами W и S или стрелками вверх и вниз\n";
	cout << "Сделать выбор пункта меню можно нажатием клавиши Enter\n";
	cout << "Журнал истории сортировок можно вызвать нажатием сочетания клавиш Ctr+H\n";
	cout << "В журнале историй, нажав клавиши + или -, можно изменить формат времени\n";
	cout << "При отрисовке массива по клавише Esc можно закончить вывод массива\n\n";
	pause;
}

//ФУНКЦИЯ: void DrawingTheSortingLog(vector <Data>& SortingLog)
//ЦЕЛЬ: отрисовка журнала сортировки
//ПАРАМЕТРЫ: 
//SortingLog - указатель на вектор истории сортировок
void DrawingTheSortingLog(vec_d& SortingLog)
{
	Key key = Key::MINUS; // переменая для получения символа клавиатуры
	bool save_mode = false; // переменная для хранения формата вывода времени
	auto save_sort = 1; // переменная для хранения поля структуры для сортировки журнала
	while (key != Key::ESC)
	{
		if (key==Key::KEY_1||key == Key::KEY_2||key == Key::KEY_3||key == Key::KEY_4||key == Key::MINUS||key == Key::PLUS)
		{
			switch (key)
			{
			case Key::PLUS: save_mode = true; break;
			case Key::MINUS: save_mode = false; break;
			case Key::KEY_1: abs(save_sort) == 1 ? save_sort *= (-1) : save_sort = 1; break;
			case Key::KEY_2: abs(save_sort) == 2 ? save_sort *= (-1) : save_sort = 2; break;
			case Key::KEY_3: abs(save_sort) == 3 ? save_sort *= (-1) : save_sort = 3; break;
			case Key::KEY_4: abs(save_sort) == 4 ? save_sort *= (-1) : save_sort = 4; break;
			}
			clear;
			sort(SortingLog.begin(), SortingLog.end(), CompareData(save_sort));
		}

		Print("№", 5, 1, 13);
		Print("Метод сортировки", 10, 1, 13);
		Print("Кол-во элементов, шт", 50, 1, 13);
		Print("Время сортировки", 90, 1, 13);

		for (auto i = 0; i < SortingLog.size(); i++)
		{
			string s(89, '.');
			Print(s, 10, i + 3, (i % 2 == 1 ? 3 : 11)); // вывод точек для удобочитаемости
			Print(to_string(SortingLog[i].number), 5, i + 3, (i % 2 == 1 ? 3 : 11)); // вывод порядкового номера сортировки
			Print(SortingLog[i].sort, 10, i + 3, (i % 2 == 1 ? 3 : 11)); // вывод названия сортировки
			Print(to_string(SortingLog[i].number_of_elements), 58, i + 3, (i % 2 == 1 ? 3 : 11)); // вывод количества элементов
			GotoXY(98, i + 3); Color(i % 2 == 1 ? 3 : 11);

			if (save_mode)
			{
				long double number = (long double)SortingLog[i].working_time;
				if (number < 1000)
					printf("%3.2f нс ", number);
				else if (number < 1000000)
					printf("%3.2f мкс", number / 1000);
				else if (number < 1000000000)
					printf("%3.2f мс ", number / 1000000);
				else if (number < 60000000000)
					printf("%3.2f сек", number / 1000000000);
				else
					printf("%3.2f мин", number / 60000000000);
			}
			else
			{
				string number = to_string(SortingLog[i].working_time / 1000);
				for (auto i = 0; i < number.size(); i++)
				{
					for (auto j = 0; j < 3; j++)
					{
						if (i < number.size()) cout << number[i];
						i++;
						if ((number.size() - i) % 3 == 0) cout << ' ';
					}
					i--;
				}
				cout << "мкс";
				Color(11);
			}
			if (i == SortingLog.size() - 1)
			{
				Print("Измененить формат времени сортировки можно клавишами [+] и [-]", 28, i + 5);
				Print("Для выхода из журнала сортировок нажмите клавишу [Esc]", 32, i + 6);
			}
		}
		key = GetKey();
	}
}


void DrawingTheStatusBar(string message)
{
	static string status = "Готов сортировать!";
	if (message != "0")
		status = message;
	Print("| " + status, 2, 26, 8);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ДРУГОЕ     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//ФУНКЦИЯ: void NewEntryInTheSortingLog(vector <Data>& SortingLog, string name_sort, size_t number_of_elements, size_t working_time)
//ЦЕЛЬ: добавление записи в структуру истории сортировок
//ПАРАМЕТРЫ: 
//SortingLog - указатель на вектор истории сортировок
//name_sort - имя сортировки
//number_of_elements - количество элементов, участвовавших в сортировке
//working_time - время сортировки
void NewEntryInTheSortingLog(vec_d& SortingLog, string name_sort, size_t number_of_elements, size_t working_time)
{
	static int g_recording; // счетчик записей в журнале сортировок
	g_recording++;
	SortingLog.resize(g_recording);
	SortingLog[(size_t)g_recording - 1].number = g_recording;
	SortingLog[(size_t)g_recording - 1].sort = name_sort;
	SortingLog[(size_t)g_recording - 1].number_of_elements = (int)number_of_elements;
	SortingLog[(size_t)g_recording - 1].working_time = working_time;
}

//ФУНКЦИЯ: bool CheckingAndDrawingErrors(vector <int>& mas, vector <Data> SortingLog, bool key)
//ЦЕЛЬ: обработка и отрисовка ошибок
//ПАРАМЕТРЫ: 
//& mas - указатель на вектор
//SortingLog - указатель на вектор истории сортировок
//key - какую ошибку надо проверять
bool CheckingAndDrawingErrors(vec_i& mas, vec_d SortingLog, bool key)
{
	if (mas.empty() && key == true)
	{
		clear;
		Print("Error: вероятно, вы забыли создать массив . . .", 36, 13, 13);
		DrawingTheStatusBar("Для начала стоит создать массив. В главном меню выберите пункт \"Создать массив\"");
		GotoXY(36, 15);
		cout << "\a";
		pause;
		return 1;
	}
	else if (SortingLog.empty() && key == false) {
		clear;
		Print("Журнал пуст", 50, 13, 13);
		DrawingTheStatusBar("Новые записи в журнале сортировок будут появляться после применения сортировки к массиву");
		GotoXY(36, 15);
		cout << "\a";
		pause;
		return 1;
	}

	return 0;
}