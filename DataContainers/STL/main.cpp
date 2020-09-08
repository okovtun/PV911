#include<iostream>
#include<list>
//using namespace std;
//STL - Standard Template Libriary (Стандартная Шаблонная Библиотека). 
//STL это набор шаблонных контейнеров - списки, деревья, массивы.
void main()
{
	setlocale(LC_ALL, "");
	std::list<int> my_list = { 3, 5, 8, 13, 21 };

	for (std::list<int>::iterator it = my_list.begin(); it != my_list.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

	for (std::list<int>::reverse_iterator it = my_list.rbegin(); it != my_list.rend(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
}