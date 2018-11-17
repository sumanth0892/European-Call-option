#include "EuropeanOption.hpp" //Declarations of functions
#include <math.h>

double EuropeanOption::CallPrice() const
{

	double tmp = sig*sqrt(T);
	double d1 = (log(U/K) + (b + (sig*sig)*0.5)*T)/tmp;
	double d2 = d1-tmp
	return (K*exp(b-r*T)*N(d1)) - (U*exp((-r)*T)*N(d2));
}

double EuropeanOption::PutPrice() const
{

	double tmp = sig*sqrt(T);
	double d1 = (log(U/K) + (b + (sig*sig)*0.5)*T)/tmp;
	double d2 = d1-tmp
	return (K*exp(-r*T)*N(-d2)) - (U*exp((b-r)*T)*N(-d1));
}

double EuropeanOption::CallDelta() const
{
	double tmp = sig*sqrt(T);
	double d1 = (log(U/K) + (b+(sig*sig)*0.5)*T)/tmp;
	return exp((b-r)*T) * N(d1);
}

double EuropeanOption::PutDelta() const
{
	double tmp = sig*sqrt(T);
	double d1 = (log(U/K) + (b+(sig*sig)*0.5)*T)/tmp;
	return exp((b-r)*T)*(N(d1) - 1.0);
}

void EuropeanOption::init()
{
//Initialize all default values
//default values
	r  =0.08;
	sig = 0.30;
	K = 65.0;
	T = 0.25;
	U = 60.0; //Stock
	b = r; //Black-Scholes model
	optType = "C";
}

void EuropeanOption::copy(const EuropeanOption& o2)
{
	r = o2.r;
	sig = o2.sig;
	K = o2.K;
	T = o2.T;
	U = o2.U;
	b = o2.b;

	optType = o2.optType
}

EuropeanOption::EuropeanOption()
{
 //Default call option
	init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{
	//Copy constructor
	copy(o2);
}

EuropeanOption::EuropeanOption(const string& optionType)
{//Create an option type
	init();
	optType = optionType;

	if (optType == "c")
		optType = "C";
}

EuropeanOption::~EuropeanOption()
{//Destructor
}

EuropeanOption& EuropeanOption::operator  =(const EuropeanOption& opt2)
{//Assignment operator
	if (this==&opt2) return *this;

	copy(opt2);
	return *this;
}

//Functions that calculate option price and sensitivities
double EuropeanOption::Price() const
{
 if (optType=="C")
	{
		return CallPrice();
	}
	else
		return PutPrice();	
}

double EuropeanOption::Delta() const
{
	if(optType=="C")
		return CallDelta();
	else
		return PutDelta();	
}

//Modifier functions
void EuropeanOption::toggle()
{//Change option to type
	if(optType=="C")
		optType = "P";
	else
		optType = "C";

}

