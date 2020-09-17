#include<iostream>
using namespace std;

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :
			Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class Tree;
	}*Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree()
	{
		Root = nullptr;
		cout << "TConstructor:\t" << this << endl;
	}
	~Tree()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	void insert(int Data)
	{
		insert(Data, this->Root);
	}
	int minValue()
	{
		return minValue(this->Root);
	}
	int maxValue()
	{
		return maxValue(Root);
	}
	int count()
	{
		return count(Root);
	}
	int sum()
	{
		return sum(Root);
	}
	void print()
	{
		print(this->Root);
		cout << endl;
	}

private:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			/*if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);*/

			if (Root->pLeft)insert(Data, Root->pLeft);
			else Root->pLeft = new Element(Data);
		}
		else
		{
			if (!Root->pRight)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);

			/*if (Root->pRight)insert(Data, Root->pRight);
			else Root->pRight = new Element(Data);*/
		}
	}

	int minValue(Element* Root)
	{
		if (Root == nullptr)return int();
		if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);
	}

	int maxValue(Element* Root)
	{
		return Root ? Root->pRight ? maxValue(Root->pRight) : Root->Data : int();
		//return Root == nullptr ? int() : Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}

	int count(Element* Root)
	{
		if (Root == nullptr)return 0;
		if (Root->pLeft == Root->pRight)return 1;
		return 1 + count(Root->pLeft) + count(Root->pRight);
	}

	int sum(Element* Root)
	{
		if (Root == nullptr)return 0;
		if (Root->pLeft == Root->pRight)return Root->Data;
		return Root->Data + sum(Root->pLeft) + sum(Root->pRight);
	}

	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Type tree size: "; cin >> n;
	Tree T800;
	for (int i = 0; i < n; i++)
	{
		T800.insert(rand() % 100);
	}
	T800.print();
	cout << "Минимальное значение в дереве: " << T800.minValue() << endl;
	cout << "Максимальное значение в дереве: " << T800.maxValue() << endl;
	cout << "Количество элементов дерева: " << T800.count() << endl;
	cout << "Сумма элементов дерева: " << T800.sum() << endl;
	cout << endl;
}