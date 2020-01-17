//Use these guards in the class definition to avoid including it twice in a program
// Remember, when you include a header it's code is literally copied into the file before being compiled
// #ifndef is a preprocessor command 

#ifndef EXAMPLE_CLASS
#define EXAMPLE_CLASS

// an example class for a pen object
class Pen
{
private:
// private class variables are defined here, these cannot be accessed outside of the class
	int inkLevel; // the level of ink left in the pen
	bool capped; // whether the cap is on the pen
public:
// public class variables defined here, anybody can access them

	//these short functions are declared in the header and return the values of private variables
	int getInk() { return inkLevel; }
	bool getCapped() { return capped; }

	//Initializing public functions defined in pen.cpp
	Pen(bool); 
	~Pen();
	void write(int);
	void refill();


};

// Additional member functions are defined in pen.cpp 
#endif