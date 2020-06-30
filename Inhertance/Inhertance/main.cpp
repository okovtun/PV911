//Inhertance
//"Является" ("is-a")
//Собака является животным? Да <=>	Dog is an Animal! true
//Машина является транспортным средством? <=> Car is a vehicle!
//Колесо является машиной?  НЕТ   Wheel is a car! NOOOOOOOOO!!!!!

//Generalization

#include<iostream>
#include<string>
using namespace std;

class Box
{
protected:
	double width;
	double height;
	double length;
public:
	double get_width()const
	{
		return width;
	}
	double get_height()const
	{
		return height;
	}
	double get_length()const
	{
		return length;
	}
	double set_width(double width)
	{
		if (width < 0)width = -width;
		return this->width = width;
	}
	double set_height(double height)
	{
		if (height < 0)height = -height;
		return this->height = height;
	}
	double set_length(double length)
	{
		if (length < 0)length = -length;
		return this->length = length;
	}
	//			Constructors:
	Box(double width, double height, double length) :
		width(set_width(width)),
		height(set_height(height)),
		length(set_length(length))
	{
		cout << "BConstructor:\t" << this << endl;
	}
	~Box()
	{
		cout << "BDestructor:\t" << this << endl;
	}

	//		Methods:
	void print()const
	{
		cout << width << "x" << height << "x" << length << endl;
	}
};

class GiftBox :public Box
{
	string cover;
	bool bant;
public:
	const string& get_cover()const
	{
		return this->cover;
	}
	bool get_bant()const
	{
		return this->bant;
	}

	GiftBox
	(
		double width, double height, double length, 
		const string& cover, bool bant
	):Box(width,height,length)
	{
		this->cover = cover;
		this->bant = bant;
		cout << "GBConstructor:\t" << this << endl;
	}
	~GiftBox()
	{
		cout << "GBDestructor:\t" << this << endl;
	}

	void print()const
	{
		Box::print();
		cout << cover << endl;
		cout << "Bant " << (bant ? "yes" : "no") << endl;
	}
	void print_address()const
	{
		cout << this << endl;
		cout << &width << endl;
		cout << &height<< endl;
		cout << &length << endl;
		cout << &cover << "\t" << sizeof(string) << "\t" << sizeof(cover) << endl;
		cout << &bant << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Box box(2,1,3);	box.print();
	GiftBox gb(2, 1, 3, "with flowers", true);
	gb.print();
	//gb.print_address();
}