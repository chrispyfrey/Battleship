// Chris Frey
// CSCI 2312-001
// Final Project

#ifndef ERROR_
#define ERROR_

#include <string>
#include <iostream>

using namespace std;

class Error
{
private:
	string errFile;
	string errLoc;
	int row;

public:
	// called for problems opening file
	Error(string _errFile) { errFile = _errFile, errLoc = " ", row = 0; }

	// called for problems with ship coordinates
	Error(string _errFile, string _errLoc);

	// called for problems with ship data
	Error(string _errFile, string _errLoc, int _row);
	  
	void errOutput(); // Outputs semi-specific error information
};
#endif
