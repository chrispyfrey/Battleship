// Chris Frey
// CSCI 2312-001
// Final Project

#include "Error.h"

/////////////////////////////
//      Constructors
/////////////////////////////

// For use with ship placement errors
Error::Error(string _errFile, string _errLoc)
{
	errFile = _errFile;
	errLoc = _errLoc;
	row = 0;
}

// For use with invalid data errors
Error::Error(string _errFile, string _errLoc, int _row)
{
	errFile = _errFile;
	errLoc = _errLoc;
	row = _row;
}

/////////////////////////////
//      Error Output
/////////////////////////////

void Error::errOutput()
{
	if(errLoc == " ") // Output if file could not be opened
	{
		cout << "Error: Could not open " << errFile
				 << ". Check file path/name.\n\n";
	}
	else if(errLoc != " " && row == 0) // Output for ship placement errors
	{
		cout << "Error: Placement issue (out of legal bounds or ship collision)\n";
		cout << "found while placing " << errLoc << " from " << errFile << " on the grid\n\n";
	}
	else // Output for invalid data errors
	{
		cout << "Error: Issue found with " << errLoc
				 << " parameter in row " << row << " in file: " << errFile << ".\n\n";
	}
}
