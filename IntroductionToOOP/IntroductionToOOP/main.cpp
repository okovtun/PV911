#include<iostream>
using std::cin;
using std::cout;
using std::endl;

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
	/*Point()
	{
		x = y = double();
		cout << "DefultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = double();
		cout << "Constructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//			Methods:
	double distance(const Point& other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << ", Y = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
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
2. ~Destructor - это метод, который удаяет объект, по истечении его времени жизни;
3. Operator=   - удаляет значение объеккта, и присваивает ему значение другого объекта;

Constructors:
1. С параметрами;
2. Без параметров;
3. По умолчанию;
4. Копирования;
5. Переноса;
------------------------
*/

#define ENCAPSULATION
//#define CONSTRUCTORS
//#define COPY_METHODS

void main()
{
	setlocale(LC_ALL, "");

#ifdef ENCAPSULATION
	int a;	//Объявление переменной 'a', типа 'int'.
	Point A;//Объявление переменной 'A', типа 'Point'.
			//Создание экземпляра 'A', структуры 'Point'.

	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << "\n--------------------------------------------------\n";
	//Point* pA = &A;
	//cout << pA->get_x() << "\t" << pA->get_y() << endl;

	Point B;
	B.set_x(4);
	B.set_y(5);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << "\n--------------------------------------------------\n";
	cout << "Расстояние от точки 'A' до точки 'B':" << A.distance(B) << endl;
	cout << "\n--------------------------------------------------\n";
	cout << "Расстояние от точки 'B' до точки 'A':" << B.distance(A) << endl;
	cout << "Расстояние между точками 'A' и 'B':  " << distance(A, B) << endl;
	cout << "Расстояние между точками 'B' и 'A':  " << distance(B, A) << endl;

	//for (int i = 0; i < 5; i++)
	//{
	//	//Point A;
	//	//cout << i << "\t";
	//}
	////cout << i << endl;
#endif // ENCAPSULATION

#ifdef CONSTRUCTORS
	/*
	Default constructor - это конструктор, который МОЖЕТ БЫТЬ ВЫЗВАН без параметров.
	https://docs.microsoft.com/en-us/cpp/cpp/constructors-cpp?view=vs-2019#default_constructors
	(implicit)
	*/

	Point A;	//Default constructor
	A.print();

	Point B = 2;//Single argument constructor
	B.print();

	Point C(3);	//Single argument constructor
	C.print();

	Point D(2, 3);//Constructor
	D.print();

	/*
	1. Copy constructor (Конструктор копирования) - копирует объект;
	2. Single argument constructor (Конструктор с одним параметром) - может быть использован
		для преобразования типов;
	*/
#endif

#ifdef COPY_METHODS
	//CopyConstructor
//CopyAssignment (Assignment operator = )
//CopyMethods особенно актуальны, 
//если в классе использется динамическая память.
/*Class(const Class& other)
{
	group - of - statements;
}*/

	Point A = 2;	//Single argument constructor
	A.print();

	Point B = A;	//CopyConstructor
	B.print();

	Point C;	//Default constuctor
	C = A;	//CopyAssignment
#endif // COPY_METHODS

}

/*

.  - Оператор прямого доступа (Point operator).
-> - Оператор косвенного доступа (Arrow operator).

*/