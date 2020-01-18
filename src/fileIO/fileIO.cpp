#include <iostream>
#include <fstream>

int main() {
    std::ofstream myfile; //make a file stream object
    myfile.open("example.txt"); //the parent path is where the .exe is called from, not sure how to set relative path right now?
    myfile << "Writing this to a file.\n";  //inserts the string onto the stream
    myfile.close(); //close file
    return 0;
}