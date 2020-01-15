#include <memory>
#include <iostream>


int* TraditionalPointer()
{
	int* rawPointer = new int(27); // make a traditional pointer to an int declared on the heap
	std::cout << "A new int was declared on the heap at address 0x" << std::hex << rawPointer << " and value " << std::dec<< *rawPointer << std::endl;
	std::cout << "this pointer live in memory address 0x" << std::hex << &rawPointer << " and is defined on the stack" << std::endl;
	return rawPointer; // return the pointer value
	//we returned a value without deleting the object, so this memory still exists
}



int* smartPointer()
{
	std::shared_ptr<int> sharedPointer = std::make_shared<int>(27); // make a smart pointer that still puts memory on the heap
	std::cout << "A new int was declared on the heap at address 0x" << std::hex << sharedPointer.get() << " and value " << std::dec << *sharedPointer << std::endl;
	std::cout << "this pointer live in memory address 0x" << std::hex << &sharedPointer << "and is defined on the stack" << std::endl;
	return sharedPointer.get(); // return the pointer value
	//when we return from the function the shared pointer goes out of scope and deletes the int object from the heap
}

void memoryLeak()
{
	std::cout << std::endl << "Memory Leak Example" << std::endl;
	int* leakyPointer = new int(5000); // make a new pointer to an int on the heap
	int newNumber = 50;
	leakyPointer = &newNumber;	//THIS IS A MEMORY LEAK -- The first int still exists on the heap but is no longer referenced

	std::shared_ptr<int> nonLeakyPointer = std::make_shared<int>(5000); //make a shared pointer to an int on the heap
	int* oldMemoryLocation = nonLeakyPointer.get();
	std::cout << "Shared pointer points to int on the heap at address 0x" << std::hex << nonLeakyPointer.get() << " and value " << std::dec << *nonLeakyPointer << std::endl;
	nonLeakyPointer = std::make_shared<int>(5000); // overwrite the nonleaky pointer. Will delete the value on the heap
	std::cout << "After overwriting the shared pointer, the value on the heap is also destroyed. Is now: " << *oldMemoryLocation << std::endl;
}

int main()
{
	std::cout << "returning a pointer the traditional way" << std::endl;
	int* rawPointer=TraditionalPointer(); //Example of a traditional pointer and putting data onto the heap which exists after the function
	std::cout << "The new pointer that was returned from the function lives in address 0x" << std::hex << &rawPointer << std::endl;
	std::cout << "but still references the same address on the Heap (0x" << std::hex << rawPointer << ")" << " and retains the correct value: " <<std::dec << *rawPointer<< std::endl;
	std::cout << std::endl<<"creating a pointer with shared pointers" << std::endl;
	rawPointer = smartPointer(); // Smart pointer that deletes data from the heap after it goes out of scope
	std::cout << "The new (raw) pointer that was returned from the method lives in address 0x" << std::hex << &rawPointer << std::endl;
	std::cout << "But the data on the heap has been rewritten because the shared pointer went out of scope: " << std::dec << *rawPointer << std::endl;
	memoryLeak(); // An example of a memory leak and how smart pointers avoid them 
	std::cin.get();
	return 0;
}