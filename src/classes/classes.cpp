#include <iostream>
#include <string>

#include "learningCpp/pen.hpp"

template<class T>
void log(T message)
{
	std::cout << message;
}


void classOnTheHeap()
{
	// make a new Pen object on the heap that Pen is a pointer too
	// Use smart pointer for memory management
	log("creating a new pen on the heap");
	std::shared_ptr<Pen> pen = std::make_shared<Pen>(false);
	
	int lengthToWrite = 5;
	// To access class functions of a function pointer use -> instead of .
	for (int j = 0; j < 10; j++)
	{

		log("writing with pen to consume ");
		log<double>(lengthToWrite);
		log(" ink. ");
		log<double>(pen->getInk());
		log(" remains.\n");
		pen->write(lengthToWrite);
	}
	log("The pen is going to ge deleted when this function exits, freeing memory on the heap\n");
}

void classOnTheStack()
{
	log("creating a new pen on the stack");
	auto pen = Pen(false); //this has been declared on the stack and pen is an actual Pen object, not a pointer to one
	int lengthToWrite = 5;
	// To access class functions use ., do not need to use ->
	for (int j = 0; j < 10; j++)
	{

		log("writing with pen to consume ");
		log<double>(lengthToWrite);
		log(" ink. ");
		log<double>(pen.getInk());
		log(" remains.\n");
		pen.write(lengthToWrite);
	}
	// when the function exits pen will automatically be deleted because it goes out of scope
}

int main()
{
	classOnTheHeap(); // making a class object declared on the heap
	log("\n");
	classOnTheStack(); // Making a class object declared on the stack
	return 0;
}