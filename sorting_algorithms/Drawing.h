#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ИНСТРУМЕНТЫ ДЛЯ РАБОТЫ С КОНСОЛЬЮ     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//ФУНКЦИЯ:
//template <typename T> void Print(T buf, int x, int y, byte color)
//template <typename T> void Print(T buf, int x, int y)
//template <typename T> void Print(T buf, byte color)
//ЦЕЛЬ: передвижение курсора консоли в строку y и столбец x, вывод в консоль строки цветом, заданным color
//ПАРАМЕТРЫ:
//buf - строка для вывода
//x - столбец в консоли
//y - строка в консоли
//color - цвет текста и фона 
template <typename T> void Print(T, int, int, byte);
template <typename T> void Print(T, int, int);
template <typename T> void Print(T, byte);


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
void Color(byte);


//ФУНКЦИЯ: GotoXY(int x, int y)
//ЦЕЛЬ: передвижение курсора консоли в строку y и столбец x
//ПАРАМЕТРЫ:
//x - столбец в консоли
//y - строка в консоли
void GotoXY(int, int);


//ФУНКЦИЯ: string Tab(int k)
//ЦЕЛЬ: создание строки с заданным количеством табуляций
//ПАРАМЕТРЫ: k - количество табуляций
string Tab(int);


//ФУНКЦИЯ: string Enter(int k)
//ЦЕЛЬ: создание строки с заданным количеством переходов на следующую строку
//ПАРАМЕТРЫ: k - количество переходов на следующую строку
string Enter(int);


//ФУНКЦИЯ: Key GetKey()
//ЦЕЛЬ: получение значения нажатой клавиши
Key GetKey();


//ФУНКЦИЯ: void DirectingInMenu(Key key, Form menu, int& dir_forms, byte number_of_lines)
//ЦЕЛЬ: универсальная функция для перемещения в формах меню
//ПАРАМЕТРЫ:
//key - клавиша, нажатая для перемещения в меню
//menu - форма меню, в которой происходит перемещение
//& dir_forms - указатель на переменную перемещения по формам меню
//number_of_lines - количество пунктов в форме меню
void DirectingInMenu(Key, Form, int&, byte);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ОТРИСОВКА ФОРМ     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//ФУНКЦИЯ: void DrawingForms(Form menu, byte line)
//ЦЕЛЬ: переход между формами
//ПАРАМЕТРЫ: 
//menu - форма для отрисовки
//line - позиция курсора в форме
void DrawingForms(Form, byte);


//ФУНКЦИЯ: void DrawingTheInitialForm(byte line)
//ЦЕЛЬ: отрисовка главного меню
//ПАРАМЕТРЫ: line - позиция курсора в форме
void DrawingTheInitialForm(byte);


//ФУНКЦИЯ: void DrawingTheCreationForm(byte line)
//ЦЕЛЬ: отрисовка меню создания массива
//ПАРАМЕТРЫ: line - позиция курсора в форме
void DrawingTheCreationForm(byte);


//ФУНКЦИЯ: void DrawingTheOrderingForm(byte line)
//ЦЕЛЬ: отрисовка меню упорядочивания массива
//ПАРАМЕТРЫ: line - позиция курсора в форме
void DrawingTheOrderingForm(byte);


//ФУНКЦИЯ: void DrawingTheSortingForm(byte line)
//ЦЕЛЬ: отрисовка меню сортировки массива
//ПАРАМЕТРЫ: line - позиция курсора в форме
void DrawingTheSortingForm(byte);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ОТРИСОВКА ИНФОРМАЦИОННЫХ ОКОН     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//ФУНКЦИЯ: void DrawingManualInput(vector <int>& mas, vector <int>& back_up_mas)
//ЦЕЛЬ: отрисовка информации при ручном вводе
//ПАРАМЕТРЫ: 
//& mas - указатель на вектор
//& back_up_mas - указатель на вектор для back up
void DrawingManualInput(vec_i&, vec_i&);


//ФУНКЦИЯ: void DrawingAnArray(vector <int>& mas)
//ЦЕЛЬ: отрисовка массива
//ПАРАМЕТРЫ: & mas - указатель на вектор
void DrawingAnArray(vec_i&);


//ФУНКЦИЯ: void DrawingAnOrder(vector <int>& mas, vector <int>& back_up_mas, bool ordering)
//ЦЕЛЬ: отрисовка окна вывода упорядочивания
//ПАРАМЕТРЫ: 
//& mas - указатель на вектор
//& back_up_mas - указатель на вектор для back up
//ordering - в какую сторону необхлдимо упорядочивать
void DrawingAnOrder(vec_i&, vec_i&, bool);


//ФУНКЦИЯ: void DrawingTheSortingOperation(string name_sort, void sort(vector <int>& mas), vector <Data>& SortingLog, vector <int>& mas, vector <int>& back_up_mas)
//ЦЕЛЬ: отрисовка информации при сортировке
//ПАРАМЕТРЫ: 
//name_sort - имя сортировки
//sort(& mas) -  функция с параметром
//SortingLog - указатель на вектор истории сортировок
//& mas - указатель на вектор
//& back_up_mas - указатель на вектор для back up
void DrawingTheSortingOperation(string, void sort(vec_i& mas), vec_d&, vec_i&, vec_i&);


//ФУНКЦИЯ: void DrawingHint()
//ЦЕЛЬ: отрисовка окна по управлению и "О программе" в консоль при нажатии на клавишу F1
void DrawingHint();


//ФУНКЦИЯ: void DrawingTheSortingLog(vector <Data>& SortingLog)
//ЦЕЛЬ: отрисовка журнала сортировки
//ПАРАМЕТРЫ: 
//SortingLog - указатель на вектор истории сортировок
void DrawingTheSortingLog(vec_d&);


void DrawingTheStatusBar(string message = "0");


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ДРУГОЕ     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//ФУНКЦИЯ: void NewEntryInTheSortingLog(vector <Data>& SortingLog, string name_sort, size_t number_of_elements, nanoseconds working_time)
//ЦЕЛЬ: добавление записи в структуру истории сортировок
//ПАРАМЕТРЫ: 
//SortingLog - указатель на вектор истории сортировок
//name_sort - имя сортировки
//number_of_elements - количество элементов, участвовавших в сортировке
//working_time - время сортировки
void NewEntryInTheSortingLog(vec_d&, string, size_t, size_t);


//ФУНКЦИЯ: bool CheckingAndDrawingErrors(vector <int>& mas, vector <Data> SortingLog, bool key)
//ЦЕЛЬ: обработка и отрисовка ошибок
//ПАРАМЕТРЫ: 
//& mas - указатель на вектор
//SortingLog - указатель на вектор истории сортировок
//key - какую ошибку надо проверять
bool CheckingAndDrawingErrors(vec_i& mas, vec_d SortingLog, bool key);