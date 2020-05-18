#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
};

/*
	Создавая структуру или класс, мы создаем новый тип данных.

	КЛАСС - ЭТО ТИП ДАННЫХ!!!
	СТРУКТУРА - ЭТО ТИП ДАННЫХ!!!
*/

void main()
{
	int a;	//Объявление переменной 'a', типа 'int'.
	Point A;//Объявление переменной 'A', типа 'Point'.
			//Создание экземпляра 'A', структуры 'Point'.

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
}

/*

.  - Оператор прямого доступа (Point operator).
-> - Оператор косвенного доступа (Arrow operator).

*/