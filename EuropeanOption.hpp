//EurpeanOption.hpp
class EuropeanOption
{
private:
	void init(); //Initialize all default values
	void copy(const EuropeanOption& o2);
	//"Kernal" functions for option calculations
	double CallPrice() const;
	double PutPrice() const;
	double CallDelta() const;
	double PutDelta() const;

public:
	//Public member data for convenience only
	double r; //Interest rate
	double sig; //Volatility
	double K; //Strike Price
	double T; /Date of expiry
	double U; //Current price (underlying)
	double b; //Cost of carry
	string optType; //Option type

public:
//Constructors
EuropeanOption(); //Default call option
EuropeanOption(const EuropeanOption& option2); //Copy constructor
EuropeanOption(const string& optionType); //Create option type

//Destructor
virtual ~EuropeanOption();

//Assignment operator
EuropeanOption& operator = (const EuropeanOption& option2);

//Functions the calculate price and sensitives
double Price() const;
double Delta() const;

//Modifier functions 
void toggle(); //To change the option type 

};