/*
* Author: M1043833 ( Srinivasan Rajendran )
* Description: This file (LoadLib.cpp) contains simple functions to load library for Windows/Linux/Mac
*
* */
#include <iostream>
#include <cstdio>
#include <stdexcept>



#define LIBRARY_EXPORTS
#include "LoadLib.h"
using namespace std;
typedef void(*LibraryFunc)();


#ifdef WIN32
#include <windows.h>

/*
Author: M1043833
Function Name: LoadDLL(const char*, const char *)
Description:
function to load the library and read the exported symbols of the library and invoke the func.
It will take two arguments (const char*) 1st argument contains libpath and second argument is function name.
This function will use in Windows enviroment.
*/
void LoadDLL(const char *libPath, const char *fName){
	LibraryFunc LibFunc;

	try {
		LPCWSTR p = LPCWSTR(libPath);
		HINSTANCE hInstLibrary = LoadLibrary(p);

		if (hInstLibrary)
		{
			LibFunc = (LibraryFunc)GetProcAddress(hInstLibrary, fName);

			if (LibFunc)
			{
				std::cout << "Calling Library Function: " << std::endl;
				LibFunc();
			}
			FreeLibrary(hInstLibrary);
		}
		else
		{
			std::cout << "DLL Failed To Load!" << std::endl;
			throw std::runtime_error("DLL Failed To Load");
		}
	}
	catch (std::runtime_error){
		throw;
	}

}
#else
/*
Author: M1043833
Function Name: LoadSharedObject(const char*, const char *)
Description:
function to load the library and read the exported symbols of the library and invoke the func.
It will take two arguments (const char*) 1st argument contains libpath and second argument is function name.
This function will use in Linux enviroment.
*/
void LoadSharedObject(const char* libPath, const char *funcName){
}
#endif


/*
Author: M1043833
Function Name: LoadLibrary(const char *, const char *)
Description:
Simple function to load the library and read the exported symbols of the library and invoke the func.
It will take two arguments (const char*) 1st argument contains libpath and second argument is function name.
It is wrapper function based on the enviroment it will invoke LoadDLL or LoadSharedObject.
*/
bool LoadLibrary(const char *libPath, const char *funcName){

	try{

		if (!libPath || !funcName || (strlen(libPath) == 0) || (strlen(funcName) == 0)){
			throw std::runtime_error("Invalid library name and/or funciton name");
			return false;
		}

#ifdef WIN32
		LoadDLL(libPath, funcName);
#else
		LoadSharedObject(libPath, funcName);
#endif

	}
	catch (std::runtime_error &ex){
		std::cout << "Error in Library load: " << ex.what() << std::endl;
		return false;
	}
	return true;
}
