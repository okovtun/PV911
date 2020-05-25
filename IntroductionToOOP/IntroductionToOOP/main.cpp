#include<iostream>
using namespace std;

//	Inheritance
//	Polymorphism

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//			Constructors:
	Point()
	{
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//			Methods:
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

class Point3D :public Point
{
	double z;
public:
	double get_z() const
	{
		return z;
	}
	void set_z(double z)
	{
		this->z = z;
	}


};

/*
	Создавая структуру или класс, мы создаем новый тип данных.

	КЛАСС - ЭТО ТИП ДАННЫХ!!!
	СТРУКТУРА - ЭТО ТИП ДАННЫХ!!!
*/

/*
------------------------
Special members:
1. Constructor - это метод, который создает объект;
2. ~Destructor  - это метод, который удаяет объект, по истечении его времени жизни;
3. Operator=   - удаляет значение объеккта, и присваивает ему значение другого объекта;

Constructors:
1. С параметрами;
2. Без параметров;
3. По умолчанию;
4. Копирования;
5. Переноса;
------------------------
*/

void main()
{
	setlocale(LC_ALL, "");
	int a;	//Объявление переменной 'a', типа 'int'.
	Point A;//Объявление переменной 'A', типа 'Point'.
			//Создание экземпляра 'A', структуры 'Point'.

	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* pA = &A;
	cout << pA->get_x() << "\t" << pA->get_y() << endl;

	Point B;
	B.set_x(4);
	B.set_y(5);
	cout << "Расстояние от точки 'A' до точки 'B':" << A.distance(B) << endl;
	cout << "Расстояние от точки 'B' до точки 'A':" << B.distance(A) << endl;
	cout << "Расстояние между точками 'A' и 'B':  " << distance(A, B) << endl;
	cout << "Расстояние между точками 'B' и 'A':  " << distance(B, A) << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << i << "\t";
	}
	cout << i << endl;
}

/*

.  - Оператор прямого доступа (Point operator).
-> - Оператор косвенного доступа (Arrow operator).

*/