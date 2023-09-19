#include <iostream>
using namespace std ;
#include "maThread.h"

int main (int argc, char * const argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
	
	maThread mat;
	mat.start();
	
	std::cout << "Hello, World!\n";
	mat.wait();
	sleep(2);
	std::cout << "Hello, World!\n";
    return 0;
}
