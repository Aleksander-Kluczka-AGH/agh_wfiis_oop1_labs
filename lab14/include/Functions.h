#pragma once

#include <cmath>
#include <exception>

/** Base class for mathematical functions with error handling
 */
class Func
{
	public: 
	/** Operator allowing to handle class objects as functions
	 * @param argument for the class function
	 */
	virtual void operator()(float x) const = 0;

	/** Getter to name of deriving math function class
	 * @return The name of the function
	 */
	virtual std::string name() const = 0;

	/** Pritning deriving function's name to stream
	 * @param target stream
	 * @param const reference to Func object which will be printed
	 */
	friend std::ostream &operator<<(std::ostream &stream, const Func& func)
	{
		stream << func.name();
		return stream;
	}
};

/** Returns the value of arcsinus of x
 */
class Asin : public Func
{
	public:
	void operator()(float x) const override
	{
		if(x < -1.f || x > 1.f)
		{
			throw std::invalid_argument("wrong argument of arcsin");
		}
		else
		{
			throw std::asin(x);
		}
	}

	std::string name() const override
	{
		return "arcsin";
	}
};

/** Returns the value of log10 of x
 */
class Log10 : public Func
{
	public:
	void operator()(float x) const override
	{
		if(x < 0.f)
		{
			throw std::invalid_argument("wrong argument of log10");
		}
		else
		{
			throw std::log10(x);
		}
	}

	std::string name() const override 
	{
		return "log10";
	}
};

/** Returns the value of arg divided by x
 */
class DivideBy : public Func
{
	public:
	DivideBy(float arg) : arg(arg) { }

	void operator()(float x) const override
	{
		if(x == 0.f)
		{
			throw std::invalid_argument("divide by zero!");
		}
		else
		{
			throw arg/x;
		}
	}

	std::string name() const override
	{
		return "DivideBy";
	}

	private:
	float arg;
};