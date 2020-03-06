// Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap
#include "H.h"
//Спросить про особенность с двумя параметрами
//Спросить про простую прегрузку методов(без шаблона)
template <typename T, typename TT, typename TTT> ostream& operator<<(ostream& os, map<T, TT, TTT> ms)
{
	typename map<T, TT>::iterator it = ms.begin();
	while (it != ms.end())
	{
		cout << (*it).first << "=" << (*it).second << endl;
		++it;
	}
	return os;
};
template <typename T, typename TT, typename TTT> ostream& operator<<(ostream& os, multimap<T, TT, TTT> ms)
{
	typename map<T, TT>::iterator it = ms.begin();
	while (it != ms.end())
	{
		cout << (*it).first << "=" << (*it).second << endl;
		++it;
	}
	return os;
};
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
ostream& operator<<(ostream& os, string ms)
{
	string::iterator it = ms.begin();
	while (it!= ms.end())
	{
		cout << *it;
		++it;
	}
	return os;
};
ostream& operator<<(ostream& os, const Point &ms)
{
	cout << ms.x << " " << ms.y;
	return os;
}
ostream& operator<<(ostream& os, pair<string, string> ms)
{
	cout << ms.first << "=" << ms.second << endl;
	return os;
};
bool sortString(const char* a, const char* b)
{
	return (strcmp(a, b) < 0);
};
class SortString_functor
{
public:
	bool operator()(const char* a, const  char* b) const
	{
		return sortString(a,b);
	}
};
bool sort_ABC(string a,string b)
{
	 return (a[0] < b[0]);
};
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
/*
Напишите шаблон функции для вывода значений stack, queue, priority_queue
обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
получения значений
*/
	stack<int> sInt;
	sInt.push(1);
	sInt.push(2);
	sInt.push(3);
	cout << sInt;
	stop
	system("cls");
	queue<int>qInt;
	qInt.push(1);
	qInt.push(2);
	qInt.push(3);
	cout << qInt;
	system("cls");
	stop 
	priority_queue<int> pqInt;
	pqInt.push(1);
	pqInt.push(5);
	pqInt.push(2);
	pqInt.push(4);
	pqInt.push(3);
	cout << pqInt;
	system("cls");
	stop
////////////////////////////////////////////////////////////////////////////////////
//stack

/*
Создайте стек таким образом, чтобы
а) элементы стека стали копиями элементов вектора
б) при выводе значений как вектора, так и стека порядок значений был одинаковым
*/
	vector<int> vInt = { 1, 2, 3, 4, 5 };
	stack<int, vector<int>> svInt(vInt);
	cout << vInt << endl;
	cout << svInt << endl;
	system("cls");
	stop
////////////////////////////////////////////////////////////////////////////////////
//queue
/*
Создайте очередь, которая содержит указатели на объекты типа Point,
при этом явно задайте базовый контейнер.
Измените значения первого и последнего элементов посредством front() и back()
Подумайте, что требуется сделать при уничтожении такой очереди?
*/
/*
Очередь смотрит на элементы базового вектора или это копии нового????????????
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
	{//POP должен вернуть объект типа указатель, и в тойже строчки я его удаляю. Но не работает. Пришлось разнести на две.
		delete qvPoint.front();
		qvPoint.pop();
	}
	stop
////////////////////////////////////////////////////////////////////////////////////
/*
priority_queue
а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
что сравнивается при вставке?
*/
	const char* p1[] = { "AAA" , "B" };//По адресам
	priority_queue<const char*> pqChar(p1,p1+2);
	stop
////////////////////////////////////////////////////////////////////////////////////
/*
set
a) создайте множество с элементами типа Point - подумайте, что необходимо определить
в классе Point (и каким образом)
*/
	set<Point> sPoint;
	sPoint.insert(Point(1, 1));
	sPoint.insert(Point(2, 2));
	pair<set<Point>::iterator,bool> Q = sPoint.insert(Point(3, 3));
	stop

//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	cout << sPoint;
	system("cls");
	stop
//в) попробуйте изменить любое значение...
	//set<Point>::iterator it = sPoint.begin(); 
	//*it = Point(8, 8); 
/*
В классе Set отсутствует свободное индексирование а главное оператор копирования.
Для замены значеня объекта требуется направить итератор на объект. Удалить данное. После чего вставить новое.
Это сделано для того, что бы не нарушать способ формирования очереди в объекте.(Сортировка)
*/
//г) Создайте два множества, которые будут содержать одинаковые значения типа int, но занесенные в разном порядке
	int vInt1[] = { 1,2,3,4,5 };
	set<int,less<int>> svInt1(vInt1, vInt1 + 5);//Порядок вызова типа данных в sete.
	set<int,greater<int>> svInt2(vInt1, vInt1+5);
	stop
//д) Вставьте в любое множество диапазон элементов из любого другого контейнера, например, элементов массива (что происходит, если в массиве имеются дубли?)
	int vInt2[] = { 1,2,3,4,5 };
	int rvInt2[] = { 5,4,3,2,1,6 };//Дубли игнорируются
	set<int> svInt3(vInt2, vInt2 + 5);
	svInt3.insert( rvInt2, rvInt2+6);
	stop
////////////////////////////////////////////////////////////////////////////////////
/*
map, multiset
*/
//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,при этом строки задаются строковыми литералами
	map<const char*,double> mList;
//б) заполните контейнер значениями посредством operator[] и insert()
	mList["QQQ"] = 100;
	mList.insert({ "WWW", 200 }); //Как интерпритироать эту строчку??
	stop
//в) распечатайте содержимое
	cout << mList;
	system("cls");
	stop
	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")	
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
д) Сформируйте любым способом вектор с элементами типа string.
Создайте (и распечатайте для проверки) map<string, int>, который будет содержать упорядоченные по алфавиту строки и
количество повторений каждой строки в векторе
*/
	vector<string> vString = { "QWE" , "RTY" , "UIO" , "QWE" , "RTY" };
	map<string, int,bool (*)(string a, string b)> mString(sort_ABC);

	for (size_t i = 0; i < vString.size(); i++)
	{
		mString[vString[i]] = mString[vString[i]]++;
	}
	cout << mString;
	system("cls");
	stop
/*
е) 
задан массив:
const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
создайте map, в котором каждой букве будет соответствовать совокупность 
лексиграфически упорядоченных слов, начинающихся с этой буквы.
Подсказка: не стоит хранить дубли одной и той же строки
	
//'A' -  "Abba" "Alfa"
//'B' -  "Beauty" "Beta"  ...
//...
*/
	const char* words[] = { "Abba", "Alfa", "Beta", "Beauty", "Abba", "Alfa", "Beta", "Beauty" };
	//const char* words[] = { "AA", "AAA", "BB", "BBB", "CC", "CCC", "Q", "QA" };
	stop
	//map<char,set<const char*,sortString<const char*>>,sort_ABC2<char>> mWords;
	//map<char,set<const char*,bool (*)(const char* a, const char* b)>, sort_ABC2<char>> mWords;
	map<char,set<const char*, SortString_functor>> mWords;
	for (size_t i = 0; i < 8; i++)
	{
		(mWords[*words[i]]).insert(words[i]);
	}
	stop
/*
ж)
создайте структуру данных, которая будет хранить информацию о студенческих группах.
Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
фамилии могут дублироваться
Сами группы тоже должны быть упорядочены по номеру		
номера 
*/
	map<int, multiset<const char*, SortString_functor>> mGroups;
	(mGroups[4512]).insert("Paramoshkin");
	(mGroups[4513]).insert("Paramoshkin");
	(mGroups[4513]).insert("Paramoshkin");
	(mGroups[4513]).insert("Ivanov");
	stop
////////////////////////////////////////////////////////////////////////////////////
/*
multimap
а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
несколько русских значений - pair<string,string>, например: strange: чужой, странный...
*/
	multimap<string, string> mmGlossary;
/*
б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью
вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
*/
	mmGlossary.insert({ "red","Красный" });
	mmGlossary.insert({ "red","Багровый" });
	mmGlossary.insert({ "orange","Апельсиновый" });
	mmGlossary.insert({ "red","Рубиновый" });
	mmGlossary.insert({ "orange","Ораньжевый" });
	stop
/*
в) Выведите все содержимое словаря на экран
*/
	cout << mmGlossary;
	system("cls");
	stop;
/*
г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
итераторов можно использовать методы lower_bound() и upper_bound()
*/
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	multimap<string, string>::iterator it_multset;
	multimap<string, string>::iterator it_multset2;
	it_multset = mmGlossary.lower_bound("red");
	it_multset2 = mmGlossary.upper_bound("red");
	while (it_multset!= it_multset2)
	{
		cout << *it_multset;
		++it_multset;
	}
	system("cls");
	stop
	return 0;
}
