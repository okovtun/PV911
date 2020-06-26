#include"String.h"

//#define COPY_METHODS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef COPY_METHODS_CHECK
	String str(8);
	str.print();
	String str1 = "Hello";
	str1.print();

	String str2 = str1;	//Copy constructor
	cout << str2 << endl;

	str = str1;		//Copy assignment
	cout << str << endl;

	str = str;
	cout << str << endl;

	int a = 2;
	int b = 3;
	a = b;
#endif // COPY_METHODS_CHECK

	String str1 = "Hello";
	String str2("World");
	cout << "\n--------------------------	Operator Plus ----------------------------\n";
	String str3;
	str3 = str1 + str2;
	cout << str3 << endl;
	cout << "\n--------------------------	Operator +=   ----------------------------\n";
	str1 += str2;
	cout << str1 << endl;
	cout << "\n-----------------------------------------------------------------------\n";

	String str4();	//ќбъ€вл€етс€ функци€ str4, котора€ не принимает никаких параметров, 
					//и возвращает значение типа String.
	String str5{};	//явный вызов конструктора по умолчанию.
	String str6{ "Single argument constructor" };
	cout << str6 << endl;
}

//Move methods
//Move constructor
//Move assignment