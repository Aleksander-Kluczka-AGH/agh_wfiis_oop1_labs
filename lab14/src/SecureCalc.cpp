#include "../include/SecureCalc.h"

#include <iostream>

void SecureCalc::run(const Func &f, float x)
{
	try
	{
		std::cout << "Obliczamy: " << f << "(" << x << ")" << std::endl;
		f(x);
	}
	catch(std::exception &e)
	{
		std::cout << "-> Error: " << e.what() << std::endl;
	}
	catch(float &result)
	{
		std::cout << "-> Wynik: " << result << std::endl;
	}
}