/*
* Author: M1043833 ( Srinivasan Rajendran )
* Description: This file (File1.cpp) contains simple functions to test dll load 
*
* */
#include <iostream>
#include "File1.h"
using namespace std;


/*
Author: M1043833
Function Name: Func1
Description:
Simple function just print the function function and it has no arguments and no return type
*/
extern "C" void Func1(){
	std::cout << "Calling Func1" << std::endl;
}

/*
Author: M1043833
Function Name: Func2
Description:
Simple function just print the function function and it has no arguments and no return type
*/
extern "C" void Func2(){
	std::cout << "Calling Func2" << std::endl;
}
