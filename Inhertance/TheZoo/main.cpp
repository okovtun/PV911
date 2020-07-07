#include<iostream>
using namespace std;

class Animal
{
	int hunger;
public:
	virtual void sound() = 0;
};

class Cat :public Animal
{
public:
	void sound()
	{
		cout << "Myau..." << endl;
	}
};

class Dog :public Animal
{
	int evil;
public:
	void sound()
	{
		cout << "Gav..." << endl;
	}
};

void main()
{
	//Animal animal;	//Cannot instantiate.... 
						//Instance - ύκηεμολÿπ.
	Cat cat;
	cat.sound();
	Dog dog;
	dog.sound();
}