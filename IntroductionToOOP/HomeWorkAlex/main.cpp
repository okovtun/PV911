#include<iostream>
using namespace std;

class Distance {
public:
	// вывод на экран оси координат с расположением точки
	void PrintDisplay(int x, int y) {
		x = set_X(x);
		y = set_Y(y);
		std::cout << "Y-" << this->get_Y_End() << std::endl;
		for (int i = this->Y_END; i > 0; i--) {
			std::cout << "|";
			for (int j = 0; j < this->X_END; j++) {
				if ((i == y) && (j == x)) {
					std::cout << "*";
				}
				else std::cout << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "0";
		for (int i = 0; i < this->X_END; i++) {
			std::cout << "-";
		}
		std::cout << " X-" << this->get_X_End() << std::endl;
		return;
	}
	// вывод на экран расположения точки в диапазоне координат
	void PrintBorderControl(int x, int y) {
		if (x < 0) {
			std::cout << "Ось x:\t" << x << " -> 0 -> " << this->get_X_End() << std::endl;
		}
		else if (x > this->get_X_End()) {
			std::cout << "Ось x:\t0 -> " << this->get_X_End() << " -> " << x << std::endl;
		}
		else {
			std::cout << "Ось x:\t0 -> " << x << " -> " << this->get_X_End() << std::endl;
		}
		if (y < 0) {
			std::cout << "Ось y:\t" << y << " -> 0 -> " << this->get_Y_End() << std::endl;
		}
		else if (y > this->get_Y_End()) {
			std::cout << "Ось y:\t0 -> " << this->get_Y_End() << " -> " << y << std::endl;
		}
		else {
			std::cout << "Ось y:\t0 -> " << y << " -> " << this->get_Y_End() << std::endl;
		}
		return;
	}
	// вывод на экран расстояния между точками x и y
	void PrintDistanceXY(int x, int y) {
		int d = 0;
		std::cout << "\n\t Расстояние от точки X до точки Y составляет: ";
		x = (x < 0) ? -(x) : x;
		y = (y < 0) ? -(y) : y;
		d = (x * x) + (y * y);
		//d = SquareRoot(d);
		std::cout << SquareRoot(d) << " точек" << std::endl;
	}
	// метод получения значения по оси x
	int get_X()const {
		return x;
	}
	// метод передачи значения по оси x и получение значения в рамках заданного диапазона
	int set_X(int x) {
		x = ErrorInputX(x);
		this->x = x;
		return x;
	}
	// метод получения граничного значения по оси x
	int get_X_End()const {
		return this->X_END;
	}
	// метод получения значения по оси y
	int get_Y()const {
		return y;
	}
	// метод передачи значения по оси y и получение значения в рамках заданного диапазона
	int set_Y(int y) {
		y = ErrorInputY(y);
		this->y = y;
		return y;
	}
	// метод получения граничного значения по оси y
	int get_Y_End()const {
		return this->Y_END;
	}
private:
	int x = 0;
	int y = 0;
	const int X_END = 30;			// зададим границу по оси x
	const int Y_END = 20;			// зададим границу по оси y
	// метод проверки на выход за рамки заданных координат по оси x
	int ErrorInputX(int x) {
		if (x > X_END) return X_END - 1;
		else return x;
	}
	// метод проверки на выход за рамки заданных координат по оси 
	int ErrorInputY(int y) {
		if (y > Y_END) return Y_END - 1;
		else return y;
	}
	// метод вычисления квадратного корня
	float SquareRoot(int d) {
		float sd = 0;
		while ((sd * sd) < d) {	// выполняем пока не достигним максимально-приближенного результата
			sd = sd + 0.01;
		}
		int temp = (sd - 0.01) * 100;	// проведем округление до сотых
		sd = (float)temp / 100;			// 
		return sd;						// вернем результат вычисления квадратного корня
	}
};

void main() {
	setlocale(LC_ALL, "");
	Distance D;
	int x = 0;
	int y = 0;
	std::cout << "Введите ваше расположение по оси x - "; std::cin >> x; std::cout << std::endl;
	std::cout << "Введите ваше расположение по оси y - "; std::cin >> y; std::cout << std::endl;

	D.PrintDisplay(x, y);
	D.PrintBorderControl(x, y);
	D.PrintDistanceXY(x, y);
	return;
}