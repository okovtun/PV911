https://www.youtube.com/watch?v=4M3O83VYL1A&list=PLFkgzpHG4CYUP72FxA_04uuQO0URYRM1J&index=1
https://github.com/okovtun/PV911.git
https://ravesli.com/urok-166-rannee-i-pozdnee-svyazyvaniya/

Special members:
http://cplusplus.com/doc/tutorial/classes2/

https://www.youtube.com/watch?v=6vH8_9BX7qI&list=PLFkgzpHG4CYWNTJgB6ZQ7waGXpb5jg0G2&index=10&t=0s for loop ;-)

////////////////////////////////////////////////////////////////////////////
///////////////////	DATA CONTAINERS		////////////////////////////
////////////////////////////////////////////////////////////////////////////

TODO:
В класс List (Двусвязный список) добавить методы:
push_back();
pop_front();
pop_back();
insert();
erase();

~List();
CopyMethods;
MoveMethods;
operator+;
operator+=;

DONE:
Переход итератора на следующий элемент обеспечить оператором ++ (Temp=Temp->pNext);

DONE:
В класс ForwardList добавить:
1. Деструктор;
2. Конструктор копирования;
3. Оператор присваивания;
4. Оператор +, который будет конкатенировать списки;
5. MoveMethods;
6. Конструктор на заданное число элементов ForwardList list(5), элементы должны быть заполнены нулями;
7. Оператор [];
8. ForwardList list{3, 5, 8, 13, 21}; for(int i=0; i<list.size; i++)cout << list[i] << tab;cout << endl;

DONE vse, krome erase:
1. pop_front - удаляет начальный элемент;
2. pop_back  - удаляет последний элемент;
3. insert - вставляет значение по индексу;
4. erase - удаляет значение по индексу;

////////////////////////////////////////////////////////////////////////////

TOREAD:
http://cplusplus.com/doc/tutorial/exceptions/
https://docs.microsoft.com/en-us/cpp/cpp/exception-handling-in-visual-cpp?view=vs-2019

TODO:
Реализовать класс Binary, обеспечить арифметические и побитовые операции над двоичными числами

ToRead: http://cplusplus.com/doc/tutorial/inheritance/

DONE:
Вычислить площадь и периметр треугольника.

DONE:
Реализовать иерархию геометрических фигур. Area(), Perimeter(), Draw();

DONE:
Реализовать проект Academy;

DONE:
Классы Fraction и Point вынести в отдельные файлы в ветке Separated;

DONE:
1. str1 += str2;
2. Добавить в класс String MoveMethods: http://cplusplus.com/doc/tutorial/classes2/

DONE:
Проверчный код в проекте 'String' должен заработать.

///////////////////////////////////////////////////////////////////////////////


DONE:

Operators overload:
http://cplusplus.com/doc/tutorial/templates/
https://docs.microsoft.com/en-us/cpp/cpp/operator-overloading?view=vs-2019

Type conversions:
http://www.cplusplus.com/doc/tutorial/typecasting/

TODO:
0. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
1. Обеспечить преобразование Fraction в double;
2. Обеспечить преобразование double во Fraction;
3. Перегрузить операторы сравнения: ==, !=, >, <, >=, <=;


DONE:
1. Перегрузить арифметические операторы для типа данных Fraction: *, /, +, -.
2. Перегрузить составные присваивания: *=, /=, +=, -=;

DONE:
0. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
1. В класс Fraction добавить неконстантные методы:
	to_proper() - неправильную дробь переводит в правильную;
	to_improper() - правильную дробь переводит в неправильную;
	reduce() - сокращает дробь;




DONE:
2. Реализовать класс Fraction, описывающий простую дробь. Подумать над именованием переменных членов класса. В классе должны быть get/set методы, и обязательные методы - Конструкторы, Деструктор и оператор присваивания.

DONE:
2. Написать метод ??? Dispance(???), который возвращает расстояние до указанной точки;
3. Написать функцию ??? Distance(???), которая возвращает расстояние между двумя точками;