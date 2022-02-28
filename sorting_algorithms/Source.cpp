

///////////////////// TODO LIST /////////////////////
/*
 * - избавиться от мерцания в консоли
 * - подключить ASCII анимацию
 * + подключить библиотеку сортировок для сравнения
 * - переделать обработку ошибок
 * - сделать разные темы
 * + перевести упорядочивание на функцию sort 
 * 
 * + выровнять по центру пункты меню
 * + строка статуса над меню
 * + Сделать журнал сортировки пунктом меню
 * + В журнале сортировки в «Время сортировки» добавить «Время сортировки, изменение формата времени [-][+]»
 * + Добавить в журнал сортировки "Нажмите любую клавишу для перехода в меню"
 * + F1 внести в меню, назвав «О программе»
 * - Отредактировать раздел F1
 */
 ///////////////////// TODO LIST /////////////////////


#include "All.h" //подключаем единый заголовочный файл
#include "Sort.h" // подключаем заголовочный файл с сортировками
#include "Drawing.h" // подключаем заголовочный файл с отрисовками

/*
 * заголовочный файл All подключен ко всем файлам .cpp
 * в заголовочном файле All прописаны:
 *  - пространство имен std
 *  - пространство имен FrontEnd
 *  - пространство имен chrono
 *  - библиотека <conio.h>
 *  - библиотека <iostream>
 *  - библиотека <string>
 *  - библиотека <vector>
 *  - библиотека <windows.h>
 *  - библиотека <ctime>
 *  - библиотека <string>
 *  - библиотека <chrono>
 *  - структура Data
 *  - структура CompareData
 *  - класс enum Form
 *  - класс enum Key
 *  - псевдоним типа vector <int> vec_i
 *  - псевдоним типа vector <Data> vec_d
 * можем ими свободно пользоваться в этом файле
 */

int main(void)
{
	srand((unsigned int)time(NULL)); // выполняем инициализацию генератора случайных чисел
	setlocale(LC_ALL, "ru"); // руссифицируем вывод в консоль
	system("color 03"); // изменяем цвета фона и текста консоли
	system("mode con cols=120 lines=28"); // задаем размер консоли

	// отключаем видимость курсора консоли
	CONSOLE_CURSOR_INFO curs = { 0 };
	curs.dwSize = sizeof(curs);
	curs.bVisible = FALSE;
	::SetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &curs);

	vec_i mas; // вектор, участвующий в сортировках 
	vec_i back_up_mas; // вектор, для отката к начальному содержимому вектора mas
	vec_d SortingLog; // вектор, для хранения истории сортировок
	bool flag_completion = false; // флаг для выхода из программы
	auto dir_initial_form = 0; // переменная перемещения по главному меню
	auto dir_forms = 0; // переменная перемещения по остальным меню форм
	Form what_form = Form::INITIAL; // переменная для хранения текущей формы

	DrawingTheInitialForm(dir_initial_form); // делаем начальную отрисовку 

	while (!flag_completion)
	{
		Key key = GetKey();// переменная для получения значения нажатой клавиши

		// обработка нажатия Esc происходит во всех формах
		if (key == Key::ESC)
		{
			if (what_form == Form::INITIAL)
			{
				system("cls");
				flag_completion = true;
				cout << "\a";
			}
			else
			{
				what_form = Form::INITIAL;
				DrawingTheInitialForm(dir_initial_form);
			}
		}

		// обработка нажатия F1 происходит во всех формах
		else if (key == Key::F1)
		{
			DrawingHint();
			DrawingForms(what_form, what_form == Form::INITIAL ? dir_initial_form : dir_forms);
		}

		//обработка нажатия Ctrl+H происходит во всех формах
		else if (key == Key::CTRL_H)
		{
			if (!CheckingAndDrawingErrors(mas, SortingLog, false))
				DrawingTheSortingLog(SortingLog);
			DrawingForms(what_form, what_form == Form::INITIAL ? dir_initial_form : dir_forms);
		}

		// главное меню
		else if (what_form == Form::INITIAL)
		{
			DirectingInMenu(key, what_form, dir_initial_form, NUMBER_OF_LINES_IN_MENU_1);
			if (key == Key::ENTER)
			{
				dir_forms = 0;
				switch (dir_initial_form)
				{
				case 0: // создание массива
					what_form = Form::CREATION;
					DrawingTheCreationForm(dir_forms);
					break;
				case 1: // вывод массива
					if (!CheckingAndDrawingErrors(mas, SortingLog, true))
						if (mas.size() < 30000)
							DrawingAnArray(mas);
						else
						{
							system("cls");
							Print("Вы точно уверены, что необходимо вывести такой большой массив?\a", 25, 13, 13);
							Print("Для подтверждения нажмите любую клавишу, для отмены - Esc", 28, 15, 11);
							if (GetKey() != Key::ESC)
								DrawingAnArray(mas);
						}
					DrawingTheInitialForm(dir_initial_form);
					break;
				case 2: // упорядочивание массива
					what_form = Form::ORDERING;
					DrawingTheOrderingForm(dir_forms);
					break;
				case 3: // сортировки массива
					what_form = Form::SORTING;
					DrawingTheSortingForm(dir_forms);
					break;
				case 4: // журнал сортировок
					if (!CheckingAndDrawingErrors(mas, SortingLog, false))
						DrawingTheSortingLog(SortingLog);
					DrawingTheInitialForm(dir_initial_form);
					break;
				case 5: // о программе
					DrawingHint();
					DrawingTheInitialForm(dir_initial_form);
					break;
				case 6: // выход из программы
					system("cls");
					flag_completion = true;
					cout << "\a";
					break;
				}
			}
		}

		// меню создания массива
		else if (what_form == Form::CREATION)
		{
			DirectingInMenu(key, what_form, dir_forms, NUMBER_OF_LINES_IN_MENU_2);
			if (key == Key::ENTER)
			{
				switch (dir_forms)
				{
				case 0: // ручной ввод
					DrawingManualInput(mas, back_up_mas);
					break;
				case 1: // 100
					CreateAnArray(mas, back_up_mas, 100);
					break;
				case 2: // 1.000
					CreateAnArray(mas, back_up_mas, 1000);
					break;
				case 3: // 10.000
					CreateAnArray(mas, back_up_mas, 10000);
					break;
				case 4: // 100.000
					CreateAnArray(mas, back_up_mas, 100000);
					break;
				}
				what_form = Form::INITIAL;
				DrawingTheInitialForm(dir_initial_form);
			}
		}
		
		// меню упорядочивания массива
		else if (what_form == Form::ORDERING)
		{
			DirectingInMenu(key, what_form, dir_forms, NUMBER_OF_LINES_IN_MENU_3);
			if (key == Key::ENTER)
			{
				switch (dir_forms)
				{
				case 0: // упорядочить по возрастанию
					if (!CheckingAndDrawingErrors(mas, SortingLog, true))
						DrawingAnOrder(mas, back_up_mas, true);
					else
						dir_initial_form = 0;
					break;
				case 1: // упорядочить по убыванию
					if (!CheckingAndDrawingErrors(mas, SortingLog, true))
						DrawingAnOrder(mas, back_up_mas, false);
					else
						dir_initial_form = 0;
					break;
				case 2: // выход из меню упорядочивания
					break;
				}
				what_form = Form::INITIAL;
				DrawingTheInitialForm(dir_initial_form);
			}
		}
		
		// меню сортировки массива
		else if (what_form == Form::SORTING)
		{
			DirectingInMenu(key, what_form, dir_forms, NUMBER_OF_LINES_IN_MENU_4);
			if (key == Key::ENTER)
			{
				switch (dir_forms)
				{
				case 0: // отсортировать вставками
					if (!CheckingAndDrawingErrors(mas, SortingLog, true))
						DrawingTheSortingOperation("вставками", InsertionSort, SortingLog, mas, back_up_mas);
					else
					{
						what_form = Form::INITIAL;
						dir_initial_form = 0;
					}
					break;
				case 1: // отсортировать пузырьком с флагом
					if (!CheckingAndDrawingErrors(mas, SortingLog, true))
						DrawingTheSortingOperation("пузырьком с флагом", BubbleSortWithFlag, SortingLog, mas, back_up_mas);
					else
					{
						what_form = Form::INITIAL;
						dir_initial_form = 0;
					}
					break;
				case 2: // отсортировать шейкер-сортировкой
					if (!CheckingAndDrawingErrors(mas, SortingLog, true))
						DrawingTheSortingOperation("шейкер-сортировкой", CocktailSort, SortingLog, mas, back_up_mas);
					else
					{
						what_form = Form::INITIAL;
						dir_initial_form = 0;
					}
					break;
				case 3: // отсортировать встроенным алгоритмом сортировки С++
					if (!CheckingAndDrawingErrors(mas, SortingLog, true))
						DrawingTheSortingOperation("встроенным алгоритмом", [](vec_i& mas) { sort(mas.begin(), mas.end()); }, SortingLog, mas, back_up_mas);
					else
					{
						what_form = Form::INITIAL;
						dir_initial_form = 0;
					}
					break;
				case 4: // выход из меню сортировки массива
					what_form = Form::INITIAL;
					break;
				}
				DrawingForms(what_form, what_form == Form::INITIAL ? dir_initial_form : dir_forms);
			}
		}
	}
}