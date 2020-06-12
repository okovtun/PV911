#include<iostream>
using namespace std;

class Fraction
{
	int integer;	//Целая часть
	int numerator;	//Числитель
	int denominator;//Знаменатель
public:
	const int get_integer()const
	{
		return integer;
	}
	const int get_numerator()const
	{
		return numerator;
	}
	const int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//		Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//		Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment: " << this << endl;
		return *this;
	}
	Fraction& operator*=(Fraction other)
	{
		this->reduce().to_improper();
		other.reduce().to_improper();
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		return this->reduce().to_proper();
	}

	//Fraction operator*(const Fraction& other) const
	//{
	//	Fraction result;
	//	Fraction left = this->to_improper();
	//	Fraction right = other.to_improper();
	//	/*left.to_improper();
	//	right.to_improper();*/
	//	result.numerator = left.numerator*right.numerator;
	//	result.denominator = left.denominator*right.denominator;
	//	result.reduce();
	//	result.to_proper();
	//	return result;
	//}

	//		Methods:
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "+";
			//if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			//if (integer)cout << ")";
		}
		else if (integer == 0)
			cout << 0;
		cout << endl;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		//numerator = numerator % denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& reduce()
	{
		//В дроби, в любом случае что-то больше. Числитель может быть больше знаменателя, или наоборот.
		int more;	//большее значение
		int less;	//меньшее значение
		int reminder = 0;	//остаток от деления
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			more = denominator;
			less = numerator;
		}
		do
		{
			reminder = more % less;
			more = less;
			less = reminder;
		} while (reminder);
		int GCD = more;	//Greatest Common Divider - Наибольший Общий Делитель.
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	//Fraction result(left.get_numerator()*right.get_numerator(), left.get_denominator()*right.get_denominator());
	/*result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*result.reduce();
	result.to_proper();*/
	return Fraction(left.get_numerator()*right.get_numerator(), left.get_denominator()*right.get_denominator()).to_proper().reduce();
}

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define METHODS_CHECK

void main()
{
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();
	Fraction B = 3;
	B.print();
	Fraction C(4, 5);
	C.print();
	Fraction D(5, 4, 7);
	Fraction E = D;//CopyConstructor
	E.print();
	Fraction F;		//DefaultConstructor
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	/*Fraction A(1, 2);
A.print();
Fraction B;
B.print();
cout << "\n-------------------------------------------\n";
B = A;
cout << "\n-------------------------------------------\n";*/

	int a, b, c;
	a = b = c = 0;
	Fraction D(1, 2);

	Fraction A, B, C;
	A = B = C = D;
#endif // ASSIGNMENT_CHECK

#ifdef METHODS_CHECK
	/*Fraction A(7, 5);
A.print();
A.to_proper();
A.print();
A.to_improper();
A.print();*/

	Fraction A(148, 44);
	A.reduce();
	A.print();
	Fraction B(251, 934);
	B.reduce();
	B.print();
	Fraction C = A * B;
#endif // METHODS_CHECK


	int a = 2;
	int b = 3;
	cout << a << endl;
	cout << b << endl;
	cout << "\n-------------------------\n";
	int c = a * b;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << "\n-------------------------\n";

	Fraction A(2, 3, 4);
	Fraction B(5, 7, 8);
	A.print();
	B.print();
	Fraction C = A * B;
	A.print();
	B.print();
	C.print();
	(A *= B).print();
}

//Operator overloading:
/*
1. Перегрузить можно только существующие операторы.
	+ перегружается;
	* перегружается;
	++ перегружается;
	** НЕ перегружается;
2. Не все существующие операторы можно перегрузить.
	Не перегружаются:
	?: - тернарный оператор
	.  - опертор прямого доступа
	.* - 
	:: - оператор разрешения видимости
	#
	##
3. Перегруженные оперторы сохраняют приоритет.
4. Изменить поведение операторов со встроенными типами данных НЕВОЗМОЖНО!
--------------------------------------------------------------------------------------------

=, +=, -=, *=, /=, %=;

--------------------------------------------------------------------------------------------
*/