#pragma once


//ФУНКЦИЯ: void CreateAnArray(vector <int>& mas, vector<int>& back_up_mas, size_t size)
//ЦЕЛЬ: заполнение элементов вектора случайными числами
//ПАРАМЕТРЫ:
//& mas - указатель на вектор
//& back_up_mas - указатель на вектор для back up
//size - размер создаваемого массива
void CreateAnArray(vec_i&, vec_i&, size_t);


//ФУНКЦИЯ: nanoseconds TimeMeasurement(void sort(vector <int>& mas), vector <int>& mas, vector <int>& back_up_mas)
//ЦЕЛЬ: измерение времени сортировки
//ПАРАМЕТРЫ:
//sort(& mas) - функция с параметром
//& mas - указатель на вектор
//& back_up_mas - указатель на вектор для back up
size_t TimeMeasurement(void sort(vec_i& mas), vec_i&, vec_i&);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     СОРТИРОВКИ     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//ФУНКЦИЯ: void BubbleSortWithFlag(vector <int>& mas)
//ЦЕЛЬ: сортировка пузырьком с флагом
//ПАРАМЕТРЫ: & mas - указатель на вектор
void BubbleSortWithFlag(vec_i&);


//ФУНКЦИЯ: void СocktailSort(vector <int>& mas)
//ЦЕЛЬ: шейкер-сортировка
//ПАРАМЕТРЫ: & mas - указатель на вектор
void CocktailSort(vec_i&);


//ФУНКЦИЯ: void InsertionSort(vector <int>& mas)
//ЦЕЛЬ: сортировка вставками
//ПАРАМЕТРЫ: & mas - указатель на вектор
void InsertionSort(vec_i&);