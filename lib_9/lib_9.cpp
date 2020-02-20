// ���������� STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap
#include "H.h"
//�������� ��� ����������� � ����� �����������
//�������� ��� ������� ��������� �������(��� �������)
template <typename T, typename TT, typename TTT> ostream& operator<<(ostream& os, map<T,TT,TTT> ms)
{
	typename map<T, TT>::iterator it = ms.begin();
	while(it != ms.end())
	{
		cout << (*it).first << "=" << (*it).second << endl;
		++it;
	}
	return os;
};
template <typename T> ostream& operator<<(ostream& os, string ms)
{
	cout << ms.back(); endl;
	return os;
};
//template <typename T> ostream& operator<<(ostream& os, stack<T> ms)
template <typename T, typename TT> ostream& operator<<(ostream& os, stack<T,TT> ms)
{
	while (ms.size())
	{
		cout << ms.top()<< endl;
		ms.pop();
	}
	return os;
};
template <typename T, typename TT> ostream& operator<<(ostream& os, queue<T,TT> ms)
{
	while (ms.size())
	{
		cout << ms.front() << endl;
		ms.pop();
	}
	return os;
};
template <typename T, typename TT> ostream& operator<<(ostream& os, priority_queue<T,TT> ms)
{
	while (ms.size())
	{
		cout << ms.top() << endl;
		ms.pop();
	}
	return os;
};
template <typename T> ostream& operator<<(ostream& os, const set<T> &ms)
{
	cout << "______________set______________" << endl;
	cout << "size     = " << ms.size() << endl;
	typename set<T>::iterator it = ms.begin();
	while (it != ms.end())
	{
		cout << "Point = " << *it << endl;
		++it;
	}
	cout << endl;
	return os;
};
template <typename T> ostream& operator<<(ostream& os, const vector<T> &ms)
{
	cout << "______________vector______________" << endl;
	cout << "size     = " << ms.size() << endl;
	for (int i = ms.size(); i > 0 ; i--)
	{
		cout << "[" << i << "]" << "=" << ms[i-1] << endl;
	}
	cout << endl;
	return os;
};
template <typename T> ostream& operator<<(ostream& os, const deque<T> &ms)
{
	cout << "______________deque______________" << endl;
	cout << "size     = " << ms.size() << endl;
	for (int i = ms.size(); i > 0; i--)
	{
		cout << "[" << i << "]" << "=" << ms[i - 1] << endl;
	}
	cout << endl;
	return os;
};
ostream& operator<<(ostream& os, const Point &ms)
{
	cout << ms.x << " " << ms.y;
	return os;
}
template<typename T>struct sort_ABC
{//������ � �� ���� ���������� � ��������� ����������(�����, ������ ��� ��� ����� �������(��� ����������) ���� �� ����������)
	bool operator()(const T &a, const  T &b)const
	{
		return (a[0] > b[0]);
	}
};
//bool sort_ABC(string a,string b)
//{
//	 return (a[0] < b[0]);
//};

int _tmain(int argc, _TCHAR* argv[])
{
/*
�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
�������� �������� �� ��, ��� ���������� ������������� ������ ������ ��� 
��������� ��������
*/
	stack<int> sInt;
	sInt.push(1);
	sInt.push(2);
	sInt.push(3);
	cout << sInt;
	stop
	queue<int>qInt;
	qInt.push(1);
	qInt.push(2);
	qInt.push(3);
	cout << qInt;
	stop 
	priority_queue<int> pqInt;
	pqInt.push(1);
	pqInt.push(5);
	pqInt.push(2);
	pqInt.push(4);
	pqInt.push(3);
	cout << pqInt;
	stop
////////////////////////////////////////////////////////////////////////////////////
//stack

/*
�������� ���� ����� �������, �����
�) �������� ����� ����� ������� ��������� �������
�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ����������
*/
	vector<int> vInt = { 1, 2, 3, 4, 5 };
	stack<int, vector<int>> svInt(vInt);
	cout << vInt << endl;
	cout << svInt << endl;
	stop

	//deque<int> dInt = {1, 2, 3, 4, 5};
	//stack<int, deque<int>> svInt(dInt);//��� ����������  � �������� �������������????????
	//cout << dInt << endl;
	//cout << svInt << endl;
	//stop

	
////////////////////////////////////////////////////////////////////////////////////
//queue
/*
�������� �������, ������� �������� ��������� �� ������� ���� Point,
��� ���� ���� ������� ������� ���������.
�������� �������� ������� � ���������� ��������� ����������� front() � back()
���������, ��� ��������� ������� ��� ����������� ����� �������?
*/
/*
������� ������� �� �������� �������� ������� ��� ��� ����� ������????????????
*/
	vector<Point> vPoint(5, Point(1, 1));
	queue<Point*>qvPoint;
	for (size_t i = 0; i < vPoint.size(); i++)
	{
		qvPoint.push(new Point(vPoint[i]));
	}
	stop
	*qvPoint.front() = Point(2,2);
	*qvPoint.back() = Point(3, 3);
	stop
	size_t I = qvPoint.size();
	for (size_t i = 0; i < I; i++)
	{//POP ������ ������� ������ ���� ���������, � � ����� ������� � ��� ������. �� �� ��������. �������� �������� �� ���.
		delete qvPoint.front();
		qvPoint.pop();
	}
	stop
////////////////////////////////////////////////////////////////////////////////////
/*
priority_queue
�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
��� ������������ ��� �������?
*/
	const char* p1[] = { "AAA" , "B" };//�� �������
	priority_queue<const char*> pqChar(p1,p1+2);
	stop
////////////////////////////////////////////////////////////////////////////////////
/*
set
a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
� ������ Point (� ����� �������)
*/
	set<Point> sPoint;
	sPoint.insert(Point(1, 1));
	sPoint.insert(Point(2, 2));
	pair<set<Point>::iterator,bool> Q = sPoint.insert(Point(3, 3));
	stop

//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������
	cout << sPoint;
	stop
//�) ���������� �������� ����� ��������...
	//set<Point>::iterator it = sPoint.begin(); 
	//*it = Point(8, 8); 
/*
� ������ Set ����������� ��������� �������������� � ������� �������� �����������.
��� ������ ������� ������� ��������� ��������� �������� �� ������. ������� ������. ����� ���� �������� �����.
��� ������� ��� ����, ��� �� �� �������� ������ ������������ ������� � �������.(����������)
*/
//�) �������� ��� ���������, ������� ����� ��������� ���������� �������� ���� int, �� ���������� � ������ �������
	int vInt1[] = { 1,2,3,4,5 };
	set<int,less<int>> svInt1(vInt1, vInt1 + 5);//������� ������ ���� ������ � sete.
	set<int,greater<int>> svInt2(vInt1, vInt1+5);
	stop
//�) �������� � ����� ��������� �������� ��������� �� ������ ������� ����������, ��������, ��������� ������� (��� ����������, ���� � ������� ������� �����?)
	int vInt2[] = { 1,2,3,4,5 };
	int rvInt2[] = { 5,4,3,2,1,6 };//����� ���������
	set<int> svInt3(vInt2, vInt2 + 5);
	svInt3.insert( rvInt2, rvInt2+6);
	stop
////////////////////////////////////////////////////////////////////////////////////
/*
map, multiset
*/
//�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,��� ���� ������ �������� ���������� ����������
	map<const char*,double> mList;
//�) ��������� ��������� ���������� ����������� operator[] � insert()
	mList["QQQ"] = 100;
	mList.insert({ "WWW", 200 }); //��� ��������������� ��� �������??
	stop
//�) ������������ ����������
		cout << mList;
	stop
	//�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")	
	const char *old_name = "QQQ";
	const char *new_name = "UUU";
	map<const char*, double>::iterator it = mList.begin();
	while (it != mList.end())
	{
		if (!strcmp(old_name,(*it).first))
		{
			double prom = (*it).second;
			it = mList.erase(it);
			mList.insert({ new_name , prom });
		}
		++it;
	}
	stop
/*
�) ����������� ����� �������� ������ � ���������� ���� string.
�������� (� ������������ ��� ��������) map<string, int>, ������� ����� ��������� ������������� �� �������� ������ �
���������� ���������� ������ ������ � �������
*/
	vector<string> vString = { "QWE" , "RTY" , "UIO" , "QWE" , "RTY" };
	map<string, int, sort_ABC<string>> mString;
	map < string, int>::iterator iteratorString;
	vector<string>::iterator iterator_vector = vString.begin();

	while (iterator_vector != vString.end())//��� �� �������� ����� ����������. ������� ��������.
	{
		iteratorString = mString.find(*iterator_vector);
		if (iteratorString == mString.end())
		{
			mString.insert({ *iterator_vector,1 });
		}
		else	{ ++(*iteratorString).second; }
		++iterator_vector;
	}
	cout << mString;
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
	const char* words[] = { "Abba", "Alfa", "Beta", "Beauty, Abba", "Alfa", "Beta", "Beauty" };
	map<char,char*> mWords;

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                     




	while (iterator_vector != vString.end())//��� �� �������� ����� ����������. ������� ��������.
	{
		iteratorString = mString.find(*iterator_vector);
		if (iteratorString == mString.end())
		{
			mString.insert({ *iterator_vector,1 });
		}
		else { ++(*iteratorString).second; }
		++iterator_vector;
	}
	cout << mString;

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
