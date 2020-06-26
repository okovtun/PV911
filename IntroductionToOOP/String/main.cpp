#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;
	char* str;
public:
	int get_size()const
	{
		return this->size;
	}
	const char* get_str()const
	{
		return this->str;
	}
	char* get_str()
	{
		return this->str;
	}
	//			Constructors:
	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char str[]) :String(strlen(str)+1)
	{
		for (int i = 0; str[i]; i++)
			this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other):String(other.str)
	{
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}

	//			Operators:
	String& operator=(const String& other)
	{
		//0) Проверяем, является ли тот объект этим объектом:
		if (this == &other)return *this;
		//1) Удалить текущее значение ЭТОГО объекта:
		delete[] this->str;
		//2) Скопировать в ЭТОТ объект ДРУГОЙ объект:
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
		//return *this += other;	//Stack overflow exception
	}

	const char& operator[](int i)const
	{
		return str[i];
	}

	char& operator[](int i)
	{
		return str[i];
	}

	//			Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		cat[i + left.get_size() - 1] = right[i];
	}
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

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

	String str4();	//Объявляется функция str4, которая не принимает никаких параметров, 
					//и возвращает значение типа String.
	String str5{};	//Явный вызов конструктора по умолчанию.
	String str6{ "Single argument constructor" };
	cout << str6 << endl;
}

//Move methods
//Move constructor
//Move assignment