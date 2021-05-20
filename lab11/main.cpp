/*
  Celem zadania jest przećwiczenie funkcji szablonowych. 
  Chcemy utworzyć klasę Factory, która gwarantuje, że mamy możliwość wytworzenia identycznych obiektów jak podany prototyp.
  Sama klasa Factory nie jest szablonowa, tylko jej funkcje są szablonowe.
  W rozwiązaniu należy wykorzystać statyczne składniki w funkcji i to, że każda instancja szablonu to odrębna funkcja.
  Dodatkowo potrzebna jest jeszcze prosta klasa Car. Proszę zawrzeć w niej tylko niezbędne funkcje.
 */

#include <iostream>
#include <string>

#include "include/Factory.h"
#include "include/Car.h"

int main() {   
	Factory f1;
	f1.prototype<int>(7);
	f1.prototype<float>(3.14);
	std::cout << f1.manufacture<int>() << std::endl;
	std::cout << f1.manufacture<float>() << std::endl;
	std::cout << f1.manufacture<float>() << std::endl;

	std::cout << "==== Zmiana int i wymiana fabryki ====" << std::endl;
	Factory f2;
	f2.prototype<int>(9);
	std::cout << f2.manufacture<int>() << std::endl;
	std::cout << f2.manufacture<float>() << std::endl;

	f1.prototype<Car>(Car("Porsche"));
	Car x = f1.manufacture<Car>();
	x.print();
	Car y = f1.manufacture<Car>();
	y.print();
	f1.prototype(Car("Ferrari"));
	Car z = f1.manufacture<Car>();
	z.print();

	std::cout << f1.manufacture<double>() << std::endl;

	f1.prototype<double>(10.4);
	std::cout << f1.manufacture<double>() << std::endl;
	std::cout << f1.manufacture<float>() << std::endl;
}

/* wynik
7
3.14
3.14
==== Zmiana int i wymiana fabryki ====
9
3.14
Car: Porsche
Car: Porsche
Car: Ferrari
No prototype for this type: 0
10.4
3.14
 */
