// ���������� STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap
#include "H.h"
int _tmain(int argc, _TCHAR* argv[])
{
/*
�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
�������� �������� �� ��, ��� ���������� ������������� ������ ������ ��� 
��������� ��������
*/

////////////////////////////////////////////////////////////////////////////////////
//stack

/*
�������� ���� ����� �������, �����
�) �������� ����� ����� ������� ��������� �������
�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 
*/

////////////////////////////////////////////////////////////////////////////////////
//queue

/*
�������� �������, ������� �������� ��������� �� ������� ���� Point,
��� ���� ���� ������� ������� ���������.
�������� �������� ������� � ���������� ��������� ����������� front() � back()
���������, ��� ��������� ������� ��� ����������� ����� �������?
*/

////////////////////////////////////////////////////////////////////////////////////
/*
priority_queue
�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
��� ������������ ��� �������?	
*/
	
////////////////////////////////////////////////////////////////////////////////////
/*
set
a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
		� ������ Point (� ����� �������)
�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������
�) ���������� �������� ����� ��������...
�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
		���� int, �� ���������� � ������ �������
�) �������� � ����� ��������� �������� ��������� �� ������ �������
	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?)
*/

////////////////////////////////////////////////////////////////////////////////////
/*
map, multiset
�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
��� ���� ������ �������� ���������� ����������
�) ��������� ��������� ���������� ����������� operator[] � insert()
�) ������������ ����������
�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")	
*/
stop
/*
�) ����������� ����� �������� ������ � ���������� ���� string.
�������� (� ������������ ��� ��������) map<string, int>, ������� �����
��������� ������������� �� �������� ������ �
���������� ���������� ������ ������ � �������
*/
stop
/*
�) 
����� ������:
const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
�������� map, � ������� ������ ����� ����� ��������������� ������������ 
��������������� ������������� ����, ������������ � ���� �����.
���������: �� ����� ������� ����� ����� � ��� �� ������
	
//'A' -  "Abba" "Alfa"
//'B' -  "Beauty" "Beta"  ...
//...
*/
stop
/*
�)
�������� ��������� ������, ������� ����� ������� ���������� � ������������ �������.
��� ������ ������ ������ �������� ������� ��������� (�� ��������). ��� ���� 
������� ����� �������������
���� ������ ���� ������ ���� ����������� �� ������		
������ 
*/

////////////////////////////////////////////////////////////////////////////////////
/*
multimap
�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
�) �������� ��� ���������� ������� �� �����
�) �������� �� ����� ������ �������� "���������" ��� ��������� �����. ���������: ��� ���������� ���������
���������� ����� ������������ ������ lower_bound() � upper_bound()
*/
stop
	return 0;
}