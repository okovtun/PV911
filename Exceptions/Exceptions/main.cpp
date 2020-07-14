#include<iostream>
#include<exception>
#include<Windows.h>
using namespace std;

//#define DIVISION_BY_ZERO
//#define FACTORIAL

unsigned int factorial(unsigned int n)
{
	if (n > 12)throw exception("Too large number");

	unsigned int f = 1;
	for (int i = 1; i <= n; i++)
	{
		cout << i << "! = ";
		f *= i;
		cout << f << endl;
	}
	return f;
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef DIVISION_BY_ZERO
	int a = 2;
	int b = 0;
	try
	{
		//throw exception("Eto nashe isluchenie");
		cout << a / 0 << endl;
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
	catch (...)
	{
		cerr << "Error: Something happened" << endl;
		MessageBox(NULL, "Шото произошло О_О", "Some exception reised", MB_OK | MB_ICONERROR);
	}
#endif // DIVISION_BY_ZERO

#ifdef FACTORIAL
	throw exception("Ex");

	int n;
	cout << "Введите число: "; cin >> n;
	try
	{
		cout << factorial(n) << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
#endif // FACTORIAL

	int n;
	cout << "Введите размер массива: "; cin >> n;
	//int* arr = nullptr;
	try
	{
		int* arr = new int[n];
		
		delete[] arr;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}

}