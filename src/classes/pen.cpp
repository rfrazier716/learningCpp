#include <iostream>
#include <algorithm>    // std::min

#include "learningCpp/pen.hpp"

// The actual definition for pen is in "pen.hpp"
// These are member functions for the pen class, notice how they start with the "Pen::" namespace to say as much

//This is the constructor function that is called when a new pen object is created
// after the colon is an initialization list, this assigns variables and is the only way you can initialize a const variable when your class is created
Pen::Pen(bool capped): capped(capped)
{
	refill(); // when a pen is created we want to refill it so the inklevel is full
}

// This is the destructor, it is called when you delete the pen object, any data declared on teh heap should be deleted here
Pen::~Pen()
{
	std::cout << "Pen Destroyed" << std::endl;
}

// This is a member function, when you reference a class variable it uses the Pen:: namespace
void Pen::refill()
{
	inkLevel = 100;
}

// This is another member function
void Pen::write(int nCharacters)
{
	inkLevel = std::max(inkLevel - nCharacters, 0);
	if (inkLevel == 0)
	{
		std::cout << "The pen is empty" << std::endl;
	}
}