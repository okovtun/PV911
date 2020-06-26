#include"String.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////		CLASS DEFINITION (ÎÏÐÅÄÅËÅÍÈÅ ÊËÀÑÑÀ)			/////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

int String::get_size()const
{
	return this->size;
}
const char* String::get_str()const
{
	return this->str;
}
char* String::get_str()
{
	return this->str;
}
//			Constructors:
String::String(int size)
{
	this->size = size;
	this->str = new char[size] {};
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char str[])
{
	this->size = strlen(str) + 1;
	this->str = new char[size] {};
	for (int i = 0; str[i]; i++)
		this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other)
{
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
}
String::~String()
{
	delete[] str;
	cout << "Destructor:\t" << this << endl;
}

//			Operators:
String& String::operator=(const String& other)
{
	//0) Ïðîâåðÿåì, ÿâëÿåòñÿ ëè òîò îáúåêò ýòèì îáúåêòîì:
	if (this == &other)return *this;
	//1) Óäàëèòü òåêóùåå çíà÷åíèå ÝÒÎÃÎ îáúåêòà:
	delete[] this->str;
	//2) Ñêîïèðîâàòü â ÝÒÎÒ îáúåêò ÄÐÓÃÎÉ îáúåêò:
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
	//return *this += other;	//Stack overflow exception
}

const char& String::operator[](int i)const
{
	return str[i];
}

char& String::operator[](int i)
{
	return str[i];
}

//			Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

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

/////////////////////////////////////////////////////////////////////////////////////////////////////