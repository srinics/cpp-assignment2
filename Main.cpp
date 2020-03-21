/*
* Author: M1043833 ( Srinivasan Rajendran )
* Description: This file (Main.c) contains main function*
* */

#include <iostream>


#include "LoadLib.h"
using namespace std;

//bool LoadLibrary(const char *libPath, const char *funcName);
int main(int argv, char **argc){

	if (argv < 3 || strlen(argc[1]) == 0 || strlen(argc[2]) == 0 ){
		std::cout << "Invalid argument provided" << std::endl;
		return -1;
	}
	LoadLibrary(argc[1], argc[2]);
	return 0;
}
