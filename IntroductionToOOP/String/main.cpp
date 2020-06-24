#include<iostream>
using std::cin;
using std::cout;
using std::endl;;

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
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)
			this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
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
	String str2 = "World";
	String str3 = str1 + " " + str2;
	cout << str3 << endl;
}