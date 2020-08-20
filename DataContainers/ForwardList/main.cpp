#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

#define tab "\t"

//1) Element - описывает структуру элемента
//2) ForwardList - отвечает за объединение элементов в список, добавление/удавление элементов, и т.д.

class Element
{
	int Data;	//Содержит значение элемента
	Element* pNext;// Адрес следующего элемента
	static int count;	//Количество элементов
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
#ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Element()
	{
		count--;
#ifdef DEBUG
		cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

	}
	friend class ForwardList;
};

int Element::count = 0;

class ForwardList
{
	Element* Head;
	int size;
public:
	int get_size()const
	{
		return this->size;
	}
	ForwardList()
	{
		this->Head = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(int size) :ForwardList()
	{
		while (size--)push_front(0);
	}
	ForwardList(const std::initializer_list<int>& il)
	{
		for (const int* it = il.begin(); it != il.end(); it++)
		{
			//*it = 5;
			push_back(*it);
		}
	}
	ForwardList(const ForwardList& other)
	{
		this->Head = nullptr;
		this->size = 0;
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
		cout << "LCopyConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		while (Head != nullptr)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

	//			Operators
	int& operator[](int index)
	{
		if (index >= this->size)throw std::exception("Error: Out of range");
		Element* Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
		return Temp->Data;
	}

	//			Добавление элементов
	void push_front(int Data)
	{
		/*
		Element* New = new Element(Data);	//Создаем новый элемент, и сохраняем в него добавляемое значение.
		//Теперь этот элемент нужно ключить в список:
		New->pNext = Head;
		Head = New;*/

		Head = new Element(Data, Head);

		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
		size++;
	}
	void insert(int index, int data)
	{
		if (index > size)return;
		if (index == 0)
		{
			push_front(data);
			return;
		}
		Element* New = new Element(data);
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
			Temp = Temp->pNext;
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}

	//			Удавление элементов:
	void pop_front()
	{
		Element* to_del = Head;	//1) запоминаем адрес удаляемого элемента
		Head = Head->pNext;	//2) исключаем элемент из списка
		delete to_del;	//3) удаляем элемент из памяти
		size--;
	}

	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	//			Methods:
	void print()
	{
#ifdef OLD_STYLE
		Element* Temp = Head;	//Temp - это итератор.
//Итератор - это указатель, при помощи которого можно получить доступ 
//к элементам структуры данных.
		while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;//Переход на следующий элемент.
}
#endif // OLD_STYLE
		for (Element* Temp = Head; Temp; /*Temp = Temp->pNext*/Temp++)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "List size: " << size << endl;
	}
};

#define delimiter "\n----------------------------------\n"

//#define BASE_CHECK
//#define PREFORMANCE_CHECK

void main()
{
	//int n;
	//cout << "Input list size: "; cin >> n;
#ifdef BASE_CHECK
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	//list.push_back(123);
	list.print();
	cout << delimiter;
	ForwardList list2 = list;
	list2.print();
	/*list.pop_front();
	list.pop_back();
	list.print();
	int index;
	int value;
	cout << "Input index: "; cin >> index;
	cout << "Input value: "; cin >> value;
	list.insert(index, value);
	list.print();*/
#endif // BASE_CHECK

#ifdef PREFORMANCE_CHECK
	ForwardList list(n);	//Создается список на 'n' элементов
//list.print();

	try
	{
		for (int i = 0; i < list.get_size(); i++)
		{
			list[i] = rand() % 100;
		}
		cout << "List loaded" << endl;
		for (int i = 0; i < list.get_size(); i++)
		{
			//cout << list[i] << "\t";
		}
		cout << endl;
		cout << "List printed" << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
#endif // PREFORMANCE_CHECK

	//const int n = 5;
	int arr[] = {3, 5, 8, 13, 21};
	for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

	ForwardList list = { 3, 5, 8, 13, 21 };
	list.print();
	/*ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.print();
	cout << delimiter;

	ForwardList list2;
	list2.push_back(21);
	list2.push_back(34);
	list2.push_back(55);
	list2.print();
	cout << delimiter;
	list1.print();*/
}