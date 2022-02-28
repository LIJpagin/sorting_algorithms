

///////////////////// TODO LIST /////////////////////
/*
 * - ���������� �� �������� � �������
 * - ���������� ASCII ��������
 * + ���������� ���������� ���������� ��� ���������
 * - ���������� ��������� ������
 * - ������� ������ ����
 * + ��������� �������������� �� ������� sort 
 * 
 * + ��������� �� ������ ������ ����
 * + ������ ������� ��� ����
 * + ������� ������ ���������� ������� ����
 * + � ������� ���������� � ������ ���������� �������� ������ ����������, ��������� ������� ������� [-][+]�
 * + �������� � ������ ���������� "������� ����� ������� ��� �������� � ����"
 * + F1 ������ � ����, ������ �� ���������
 * - ��������������� ������ F1
 */
 ///////////////////// TODO LIST /////////////////////


#include "All.h" //���������� ������ ������������ ����
#include "Sort.h" // ���������� ������������ ���� � ������������
#include "Drawing.h" // ���������� ������������ ���� � �����������

/*
 * ������������ ���� All ��������� �� ���� ������ .cpp
 * � ������������ ����� All ���������:
 *  - ������������ ���� std
 *  - ������������ ���� FrontEnd
 *  - ������������ ���� chrono
 *  - ���������� <conio.h>
 *  - ���������� <iostream>
 *  - ���������� <string>
 *  - ���������� <vector>
 *  - ���������� <windows.h>
 *  - ���������� <ctime>
 *  - ���������� <string>
 *  - ���������� <chrono>
 *  - ��������� Data
 *  - ��������� CompareData
 *  - ����� enum Form
 *  - ����� enum Key
 *  - ��������� ���� vector <int> vec_i
 *  - ��������� ���� vector <Data> vec_d
 * ����� ��� �������� ������������ � ���� �����
 */

int main(void)
{
	srand((unsigned int)time(NULL)); // ��������� ������������� ���������� ��������� �����
	setlocale(LC_ALL, "ru"); // ������������� ����� � �������
	system("color 03"); // �������� ����� ���� � ������ �������
	system("mode con cols=120 lines=28"); // ������ ������ �������

	// ��������� ��������� ������� �������
	CONSOLE_CURSOR_INFO curs = { 0 };
	curs.dwSize = sizeof(curs);
	curs.bVisible = FALSE;
	::SetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &curs);

	vec_i mas; // ������, ����������� � ����������� 
	vec_i back_up_mas; // ������, ��� ������ � ���������� ����������� ������� mas
	vec_d SortingLog; // ������, ��� �������� ������� ����������
	bool flag_completion = false; // ���� ��� ������ �� ���������
	auto dir_initial_form = 0; // ���������� ����������� �� �������� ����
	auto dir_forms = 0; // ���������� ����������� �� ��������� ���� ����
	Form what_form = Form::INITIAL; // ���������� ��� �������� ������� �����

	DrawingTheInitialForm(dir_initial_form); // ������ ��������� ��������� 

	while (!flag_completion)
	{
		Key key = GetKey();// ���������� ��� ��������� �������� ������� �������

		// ��������� ������� Esc ���������� �� ���� ������
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

		// ��������� ������� F1 ���������� �� ���� ������
		else if (key == Key::F1)
		{
			DrawingHint();
			DrawingForms(what_form, what_form == Form::INITIAL ? dir_initial_form : dir_forms);
		}

		//��������� ������� Ctrl+H ���������� �� ���� ������
		else if (key == Key::CTRL_H)
		{
			if (!CheckingAndDrawingErrors(mas, SortingLog, false))
				DrawingTheSortingLog(SortingLog);
			DrawingForms(what_form, what_form == Form::INITIAL ? dir_initial_form : dir_forms);
		}

		// ������� ����
		else if (what_form == Form::INITIAL)
		{
			DirectingInMenu(key, what_form, dir_initial_form, NUMBER_OF_LINES_IN_MENU_1);
			if (key == Key::ENTER)
			{
				dir_forms = 0;
				switch (dir_initial_form)
				{
				case 0: // �������� �������
					what_form = Form::CREATION;
					DrawingTheCreationForm(dir_forms);
					break;
				case 1: // ����� �������
					if (!CheckingAndDrawingErrors(mas, SortingLog, true))
						if (mas.size() < 30000)
							DrawingAnArray(mas);
						else
						{
							system("cls");
							Print("�� ����� �������, ��� ���������� ������� ����� ������� ������?\a", 25, 13, 13);
							Print("��� ������������� ������� ����� �������, ��� ������ - Esc", 28, 15, 11);
							if (GetKey() != Key::ESC)
								DrawingAnArray(mas);
						}
					DrawingTheInitialForm(dir_initial_form);
					break;
				case 2: // �������������� �������
					what_form = Form::ORDERING;
					DrawingTheOrderingForm(dir_forms);
					break;
				case 3: // ���������� �������
					what_form = Form::SORTING;
					DrawingTheSortingForm(dir_forms);
					break;
				case 4: // ������ ����������
					if (!CheckingAndDrawingErrors(mas, SortingLog, false))
						DrawingTheSortingLog(SortingLog);
					DrawingTheInitialForm(dir_initial_form);
					break;
				case 5: // � ���������
					DrawingHint();
					DrawingTheInitialForm(dir_initial_form);
					break;
				case 6: // ����� �� ���������
					system("cls");
					flag_completion = true;
					cout << "\a";
					break;
				}
			}
		}

		// ���� �������� �������
		else if (what_form == Form::CREATION)
		{
			DirectingInMenu(key, what_form, dir_forms, NUMBER_OF_LINES_IN_MENU_2);
			if (key == Key::ENTER)
			{
				switch (dir_forms)
				{
				case 0: // ������ ����
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
		
		// ���� �������������� �������
		else if (what_form == Form::ORDERING)
		{
			DirectingInMenu(key, what_form, dir_forms, NUMBER_OF_LINES_IN_MENU_3);
			if (key == Key::ENTER)
			{
				switch (dir_forms)
				{
				case 0: // ����������� �� �����������
					if (!CheckingAndDrawingErrors(mas, SortingLog, true))
						DrawingAnOrder(mas, back_up_mas, true);
					else
						dir_initial_form = 0;
					break;
				case 1: // ����������� �� ��������
					if (!CheckingAndDrawingErrors(mas, SortingLog, true))
						DrawingAnOrder(mas, back_up_mas, false);
					else
						dir_initial_form = 0;
					break;
				case 2: // ����� �� ���� ��������������
					break;
				}
				what_form = Form::INITIAL;
				DrawingTheInitialForm(dir_initial_form);
			}
		}
		
		// ���� ���������� �������
		else if (what_form == Form::SORTING)
		{
			DirectingInMenu(key, what_form, dir_forms, NUMBER_OF_LINES_IN_MENU_4);
			if (key == Key::ENTER)
			{
				switch (dir_forms)
				{
				case 0: // ������������� ���������
					if (!CheckingAndDrawingErrors(mas, SortingLog, true))
						DrawingTheSortingOperation("���������", InsertionSort, SortingLog, mas, back_up_mas);
					else
					{
						what_form = Form::INITIAL;
						dir_initial_form = 0;
					}
					break;
				case 1: // ������������� ��������� � ������
					if (!CheckingAndDrawingErrors(mas, SortingLog, true))
						DrawingTheSortingOperation("��������� � ������", BubbleSortWithFlag, SortingLog, mas, back_up_mas);
					else
					{
						what_form = Form::INITIAL;
						dir_initial_form = 0;
					}
					break;
				case 2: // ������������� ������-�����������
					if (!CheckingAndDrawingErrors(mas, SortingLog, true))
						DrawingTheSortingOperation("������-�����������", CocktailSort, SortingLog, mas, back_up_mas);
					else
					{
						what_form = Form::INITIAL;
						dir_initial_form = 0;
					}
					break;
				case 3: // ������������� ���������� ���������� ���������� �++
					if (!CheckingAndDrawingErrors(mas, SortingLog, true))
						DrawingTheSortingOperation("���������� ����������", [](vec_i& mas) { sort(mas.begin(), mas.end()); }, SortingLog, mas, back_up_mas);
					else
					{
						what_form = Form::INITIAL;
						dir_initial_form = 0;
					}
					break;
				case 4: // ����� �� ���� ���������� �������
					what_form = Form::INITIAL;
					break;
				}
				DrawingForms(what_form, what_form == Form::INITIAL ? dir_initial_form : dir_forms);
			}
		}
	}
}