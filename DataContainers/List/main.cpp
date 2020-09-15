#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
//#define DEBUG

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////		CLASS DECLARATION		///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>class List
{
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List;
	};// *Head, *Tail;
	Element* Head;
	Element* Tail;
	int size;
public:

	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr);
		~Iterator();
		Iterator& operator++();
		Iterator& operator--();

		const T& operator*()const;
		T& operator*();

		bool operator!=(const Iterator& other)const;

		operator bool()const;
	};

	class ReverseIterator
	{
		Element* Temp;
	public:
		ReverseIterator(Element* Temp = nullptr) :Temp(Temp)
		{
#ifdef DEBUG
			cout << "RItConstructor:\t" << this << endl;
#endif // DEBUG
		}
		~ReverseIterator()
		{
#ifdef DEBUG
			cout << "RItDestructor:\t" << this << endl;
#endif // DEBUG
		}

		ReverseIterator& operator++()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ReverseIterator& operator--()
		{
			Temp = Temp->pNext;
			return *this;
		}
		const T& operator*()const
		{
			return Temp->Data;
		}
		T& operator*()
		{
			return Temp->Data;
		}

		bool operator!=(const ReverseIterator& other)const
		{
			return this->Temp != other.Temp;
		}

		operator bool()const
		{
			return this->Temp;
		}
	};

	const Iterator begin()const;
	const Iterator end()const;
	const ReverseIterator rbegin()const;
	const ReverseIterator rend()const;

	List();
	List(const std::initializer_list<T>& il);
	List(const List& other);
	~List();

	//			Operators:
	List& operator=(const List& other);

	//			Adding elements:
	void push_front(T Data);
	void push_back(T Data);

	//			Removing elements:
	void pop_front();
	void pop_back();
	void erase(int Index);

	//			Methods:
	void print();
	void print_reverse();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////		CLASS DEFINITION		///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
List<T>::Element::Element(T Data, Element* pNext, Element* pPrev) :Data(Data), pNext(pNext), pPrev(pPrev)
{
	cout << "EConstructor:\t" << this << endl;
}
template<typename T>
List<T>::Element::~Element()
{
	cout << "EDestructor:\t" << this << endl;
}

/////////////////////////////////////////////	INTERATOR	///////////////////////////////////////////////////////

template<typename T>
List<T>::Iterator::Iterator(Element* Temp) :Temp(Temp)
{
#ifdef DEBUG
	cout << "ItConstructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>
List<T>::Iterator::~Iterator()
{
#ifdef DEBUG
	cout << "ItDestructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--()
{
	Temp = Temp->pPrev;
	return *this;
}

template<typename T>
const T& List<T>::Iterator::operator*()const
{
	return Temp->Data;
}
template<typename T>
T& List<T>::Iterator::operator*()
{
	return Temp->Data;
}
template<typename T>
bool List<T>::Iterator::operator!=(const Iterator& other)const
{
	return this->Temp != other.Temp;
}
template<typename T>
List<T>::Iterator::operator bool()const
{
	return Temp;
}

////////////////////////////////////////////

////////////////////////////////////////////	  LIST		///////////////////////////////////////////////////////

template<typename T>
typename const List<T>::Iterator List<T>::begin()const
{
	return this->Head;
}
template<typename T>
typename const List<T>::Iterator List<T>::end()const
{
	return nullptr;
}
template<typename T>
typename const List<T>::ReverseIterator List<T>::rbegin()const
{
	return Tail;
}
template<typename T>
typename const List<T>::ReverseIterator List<T>::rend()const
{
	return nullptr;
}
template<typename T>
List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>
List<T>::List(const std::initializer_list<T>& il) :List()
{
	for (const T* it = il.begin(); it != il.end(); it++)
	{
		//*it += 5;
		push_back(*it);
	}
	cout << "ILConstructor:\t" << this << endl;
}
template<typename T>
List<T>::List(const List& other) :List()
{
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	cout << "CopyConstructor:\t" << this << endl;
}
template<typename T>
List<T>::~List()
{
	while (Tail)pop_back();
	cout << "LDestructor:\t" << this << endl;
}

//			Operators:
template<typename T>
List<T>& List<T>::operator=(const List& other)
{
	if (this == &other)return *this;
	//while (Head)pop_front();
	this->~List();
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}


//			Adding elements:
template<typename T>
void List<T>::push_front(T Data)
{
	if (Head == nullptr&&Tail == nullptr)
		Head = Tail = new Element(Data);
	else
		Head = Head->pPrev = new Element(Data, Head);
	size++;
	//////////////////////////////////////////////////
}
template<typename T>
void List<T>::push_back(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
	}
	else
	{
		/*Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;*/
		Tail = Tail->pNext = new Element(Data, nullptr, Tail);
	}
	size++;
}

//			Removing elements:
template<typename T>
void List<T>::pop_front()
{
	if (Head == nullptr && Tail == nullptr)return;
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
	}
	else
	{
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
	}
	size--;
}
template<typename T>
void List<T>::pop_back()
{
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
	}
	else
	{
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
	}
	size--;
}
template<typename T>
void List<T>::erase(int Index)
{
	if (Index == 0)
	{
		pop_front();
		return;
	}
	if (Index == size - 1)
	{
		pop_back();	//TODO
		return;
	}
	if (Index >= size)
	{
		return;
	}
	Element* Temp;
	if (Index < size / 2)
	{
		//Если, элемент ближе к началу списка, 
		//то заходим с головы, и идем от начала списка до нужного элемента.
		Temp = Head;
		for (int i = 0; i < Index; i++)Temp = Temp->pNext;
	}
	else
	{
		//Иначе, заходим через Хвост, и движемся по списку в обратном направлении, 
		//от конца, до нужного элемента.
		Temp = Tail;
		for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
	}
	//Не важно, как мы дошли до элемента, процедура удаления будет одна:
	Temp->pPrev->pNext = Temp->pNext;	//В pNext предыдущего элемента от Temp (Temp->pPrev) записываем адрес элемента, следующего за Temp
	Temp->pNext->pPrev = Temp->pPrev;
	delete Temp;
	size--;
}

//			Methods:
template<typename T>
void List<T>::print()
{
	//for (Element* Temp = Head; Temp; Temp++/*Temp = Temp->pNext*/)
	for (Iterator it = Head; it; ++it)
	{
		//cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << *it << "\t";
	}
	cout << "List size: \t" << size << endl;

	int a = 2;
	int* pa = &a;
	cout << pa << endl;
}
template<typename T>
void List<T>::print_reverse()
{
	for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
	{
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	}
	cout << "List size: \t" << size << endl;
}

//#define BASE_CHECK
//#define COPY_METHODS
//#define ITERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef BASE_CHECK
	int n;
	cout << "Input list size: "; cin >> n;
	List list;
	list.pop_front();
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	//list.pop_front();
	list = list;
	list.print_reverse();
#endif // BASE_CHECK


	/*int index;
	cout << "Type index of deleting element: "; cin >> index;
	list.erase(index);

	list.print();
	list.print_reverse();*/

#ifdef COPY_METHODS
	cout << "\n===============================================\n";
	List list2;
	list2.push_back(123);
	list2.push_back(234);
	list2.push_back(345);
	cout << "\n-----------------------------------------------\n";
	list2 = list;
	cout << "\n-----------------------------------------------\n";
	list2.print();
	list2.print_reverse();
	cout << "\n===============================================\n";
#endif // COPY_METHODS

#ifdef ITERATORS_CHECK
	List list = { 3, 5, 8, 13, 21 };
	//list.print();

	for (List::Iterator it = list.begin(); it != list.end(); ++it)
	{
		cout << *it << "\t";
	}
	cout << endl;

	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;

	//for (List::Iterator it = list.end(); it; --it)
	for (List::ReverseIterator rit = list.rbegin(); rit != list.rend(); ++rit)
	{
		cout << *rit << "\t";
	}
	cout << endl;
#endif // ITERATORS_CHECK

	//Class<type> object;
	//List<int> list;	//Объявление объекта шаблонного класса.

	List<int> list1 = { 3, 5, 8, 13, 21 };
	for (List<int>::Iterator it = list1.begin(); it != list1.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (List<int>::ReverseIterator it = list1.rbegin(); it != list1.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	////////////////////////////////////////////////////////////////////////////////////
	List<double> list2 = { 2.5, 3.14, 8.2, 12.21 };
	for (double i : list2)
	{
		cout << i << tab;
	}
	cout << endl;
	////////////////////////////////////////////////////////////////////////////////////
	List<std::string> list3 = {"живет", "на", "свете"};
	list3.push_front("Хорошо");
	list3.push_back("Винни-Пух");
	for (std::string i : list3)
	{
		cout << i << tab;
	}
	cout << endl;
	for (List<std::string>::ReverseIterator it = list3.rbegin(); it != list3.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
}