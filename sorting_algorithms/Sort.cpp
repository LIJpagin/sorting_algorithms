#include "All.h" //���������� ������ ������������ ����
#include "Drawing.h"

#define A -10000
#define B 10000
//�������: void CreateAnArray(vector <int>& mas, vector<int>& back_up_mas, size_t size)
//����: ���������� ��������� ������� ���������� �������
//���������:
//& mas - ��������� �� ������
//& back_up_mas - ��������� �� ������ ��� back up
//size - ������ ������������ �������
void CreateAnArray(vec_i& mas, vec_i& back_up_mas, size_t size)
{
	mas.clear();
	mas.reserve(size + 1);
	back_up_mas.clear();
	back_up_mas.reserve(size + 1);
	mas.resize(size);
	for (size_t i = 0; i < size; i++)
		mas[i] = A + rand() % (B - A + 1);
	back_up_mas = mas;
	DrawingTheStatusBar("������ ������ �������� " + to_string(size) + " ���������");
}

//�������: nanoseconds TimeMeasurement(void sort(vector <int>& mas), vector <int>& mas, vector <int>& back_up_mas)
//����: ��������� ������� ����������
//���������:
//sort(& mas) - ������� � ����������
//& mas - ��������� �� ������
//& back_up_mas - ��������� �� ������ ��� back up
size_t TimeMeasurement(void sort(vec_i& mas), vec_i& mas, vec_i& back_up_mas)
{
	mas = back_up_mas;
	auto begin = high_resolution_clock::now();
	sort(mas);
	auto end = high_resolution_clock::now();
	auto elapsed = duration_cast<nanoseconds>(end - begin);
	return (size_t)elapsed.count();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ����������     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//�������: void BubbleSortWithFlag(vector <int>& mas)
//����: ���������� ��������� � ������
//���������: & mas - ��������� �� ������
void BubbleSortWithFlag(vec_i& mas)
{
	for (size_t i = 0; i < mas.size(); i++)
	{
		bool flag = true;
		for (size_t j = 0; j < mas.size() - (i + 1); j++)
		{
			if (mas[j] > mas[j + 1])
			{
				flag = false;
				swap(mas[j], mas[j + 1]);
			}
		}
		if (flag)
			break;
	}

	/*bool flag = false;
	while (!flag)
	{
		for (size_t i = 0; i < mas.size() - 1; i++)
		{
			if (mas[i] > mas[i + 1])
			{
				swap(mas[i], mas[i + 1]);
				flag = false;
			}
		}
	}*/
}

//�������: void �ocktailSort(vector <int>& mas)
//����: ������-����������
//���������: & mas - ��������� �� ������
void CocktailSort(vec_i& mas)
{
	bool sort_or_not = true;
	do {
		sort_or_not = true;
		for (size_t i = 0; i < mas.size() - 1; i++)
		{
			if (mas[i] > mas[i + 1])
			{
				swap(mas[i], mas[i + 1]);
				sort_or_not = false;
			}
		}
		for (size_t i = 4; i >= 1; i--)
		{
			if (mas[i] < mas[i - 1])
			{
				swap(mas[i], mas[i - 1]);
				sort_or_not = false;
			}
		}
	} while (sort_or_not == false);
}

//�������: void InsertionSort(vector <int>& mas)
//����: ���������� ���������
//���������: & mas - ��������� �� ������
void InsertionSort(vec_i& mas)
{
	int key = 0, temp = 0;
	for (size_t i = 0; i < mas.size() - 1; i++)
	{
		key = (int)i + 1;
		temp = mas[key];
		for (size_t j = i + 1; j > 0; j--)
		{
			if (temp < mas[j - 1])
			{
				mas[j] = mas[j - 1];
				key = (int)j - 1;
			}
		}
		mas[key] = temp;
	}
}