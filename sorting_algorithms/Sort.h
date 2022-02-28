#pragma once


//�������: void CreateAnArray(vector <int>& mas, vector<int>& back_up_mas, size_t size)
//����: ���������� ��������� ������� ���������� �������
//���������:
//& mas - ��������� �� ������
//& back_up_mas - ��������� �� ������ ��� back up
//size - ������ ������������ �������
void CreateAnArray(vec_i&, vec_i&, size_t);


//�������: nanoseconds TimeMeasurement(void sort(vector <int>& mas), vector <int>& mas, vector <int>& back_up_mas)
//����: ��������� ������� ����������
//���������:
//sort(& mas) - ������� � ����������
//& mas - ��������� �� ������
//& back_up_mas - ��������� �� ������ ��� back up
size_t TimeMeasurement(void sort(vec_i& mas), vec_i&, vec_i&);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ����������     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//�������: void BubbleSortWithFlag(vector <int>& mas)
//����: ���������� ��������� � ������
//���������: & mas - ��������� �� ������
void BubbleSortWithFlag(vec_i&);


//�������: void �ocktailSort(vector <int>& mas)
//����: ������-����������
//���������: & mas - ��������� �� ������
void CocktailSort(vec_i&);


//�������: void InsertionSort(vector <int>& mas)
//����: ���������� ���������
//���������: & mas - ��������� �� ������
void InsertionSort(vec_i&);