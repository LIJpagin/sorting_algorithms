#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ����������� ��� ������ � ��������     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//�������:
//template <typename T> void Print(T buf, int x, int y, byte color)
//template <typename T> void Print(T buf, int x, int y)
//template <typename T> void Print(T buf, byte color)
//����: ������������ ������� ������� � ������ y � ������� x, ����� � ������� ������ ������, �������� color
//���������:
//buf - ������ ��� ������
//x - ������� � �������
//y - ������ � �������
//color - ���� ������ � ���� 
template <typename T> void Print(T, int, int, byte);
template <typename T> void Print(T, int, int);
template <typename T> void Print(T, byte);


/*�������: void Color(byte color)
* ����: ������� ����� ���������� � ������� ������
* ���������: color - ���� ������ � ����
*
* �����
* 0, 7, 8, 15 - �� ������� �� ������
* 1, 3, 9, 11 - �� ������ �� ��������
* 4, 12 - �������
* 2, 10 - �������
* 5, 13 - ����������
* 6, 14 - ������
*
* ���
* 0..15 - ������
* 112..127, 128..143 - �����
* 240..255 - �����
* 32..47, 160..175 - �������
* 16..31, 48..63, 144..159, 176..191 - �����
* 64..79, 192..207 - �������
* 80..95, 208..223 - ����������
* 96..111, 224..239 - ������
*/
void Color(byte);


//�������: GotoXY(int x, int y)
//����: ������������ ������� ������� � ������ y � ������� x
//���������:
//x - ������� � �������
//y - ������ � �������
void GotoXY(int, int);


//�������: string Tab(int k)
//����: �������� ������ � �������� ����������� ���������
//���������: k - ���������� ���������
string Tab(int);


//�������: string Enter(int k)
//����: �������� ������ � �������� ����������� ��������� �� ��������� ������
//���������: k - ���������� ��������� �� ��������� ������
string Enter(int);


//�������: Key GetKey()
//����: ��������� �������� ������� �������
Key GetKey();


//�������: void DirectingInMenu(Key key, Form menu, int& dir_forms, byte number_of_lines)
//����: ������������� ������� ��� ����������� � ������ ����
//���������:
//key - �������, ������� ��� ����������� � ����
//menu - ����� ����, � ������� ���������� �����������
//& dir_forms - ��������� �� ���������� ����������� �� ������ ����
//number_of_lines - ���������� ������� � ����� ����
void DirectingInMenu(Key, Form, int&, byte);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ��������� ����     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//�������: void DrawingForms(Form menu, byte line)
//����: ������� ����� �������
//���������: 
//menu - ����� ��� ���������
//line - ������� ������� � �����
void DrawingForms(Form, byte);


//�������: void DrawingTheInitialForm(byte line)
//����: ��������� �������� ����
//���������: line - ������� ������� � �����
void DrawingTheInitialForm(byte);


//�������: void DrawingTheCreationForm(byte line)
//����: ��������� ���� �������� �������
//���������: line - ������� ������� � �����
void DrawingTheCreationForm(byte);


//�������: void DrawingTheOrderingForm(byte line)
//����: ��������� ���� �������������� �������
//���������: line - ������� ������� � �����
void DrawingTheOrderingForm(byte);


//�������: void DrawingTheSortingForm(byte line)
//����: ��������� ���� ���������� �������
//���������: line - ������� ������� � �����
void DrawingTheSortingForm(byte);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ��������� �������������� ����     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//�������: void DrawingManualInput(vector <int>& mas, vector <int>& back_up_mas)
//����: ��������� ���������� ��� ������ �����
//���������: 
//& mas - ��������� �� ������
//& back_up_mas - ��������� �� ������ ��� back up
void DrawingManualInput(vec_i&, vec_i&);


//�������: void DrawingAnArray(vector <int>& mas)
//����: ��������� �������
//���������: & mas - ��������� �� ������
void DrawingAnArray(vec_i&);


//�������: void DrawingAnOrder(vector <int>& mas, vector <int>& back_up_mas, bool ordering)
//����: ��������� ���� ������ ��������������
//���������: 
//& mas - ��������� �� ������
//& back_up_mas - ��������� �� ������ ��� back up
//ordering - � ����� ������� ���������� �������������
void DrawingAnOrder(vec_i&, vec_i&, bool);


//�������: void DrawingTheSortingOperation(string name_sort, void sort(vector <int>& mas), vector <Data>& SortingLog, vector <int>& mas, vector <int>& back_up_mas)
//����: ��������� ���������� ��� ����������
//���������: 
//name_sort - ��� ����������
//sort(& mas) -  ������� � ����������
//SortingLog - ��������� �� ������ ������� ����������
//& mas - ��������� �� ������
//& back_up_mas - ��������� �� ������ ��� back up
void DrawingTheSortingOperation(string, void sort(vec_i& mas), vec_d&, vec_i&, vec_i&);


//�������: void DrawingHint()
//����: ��������� ���� �� ���������� � "� ���������" � ������� ��� ������� �� ������� F1
void DrawingHint();


//�������: void DrawingTheSortingLog(vector <Data>& SortingLog)
//����: ��������� ������� ����������
//���������: 
//SortingLog - ��������� �� ������ ������� ����������
void DrawingTheSortingLog(vec_d&);


void DrawingTheStatusBar(string message = "0");


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ������     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//�������: void NewEntryInTheSortingLog(vector <Data>& SortingLog, string name_sort, size_t number_of_elements, nanoseconds working_time)
//����: ���������� ������ � ��������� ������� ����������
//���������: 
//SortingLog - ��������� �� ������ ������� ����������
//name_sort - ��� ����������
//number_of_elements - ���������� ���������, ������������� � ����������
//working_time - ����� ����������
void NewEntryInTheSortingLog(vec_d&, string, size_t, size_t);


//�������: bool CheckingAndDrawingErrors(vector <int>& mas, vector <Data> SortingLog, bool key)
//����: ��������� � ��������� ������
//���������: 
//& mas - ��������� �� ������
//SortingLog - ��������� �� ������ ������� ����������
//key - ����� ������ ���� ���������
bool CheckingAndDrawingErrors(vec_i& mas, vec_d SortingLog, bool key);