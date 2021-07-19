// Chris Frey
// CSCI 2312-001
// Final Project

#include "Player.h"
#include "Grid.h"
#include "Error.h"

string getShipName(const Ship &_ship); // converts ship char designator to ship name

int main()
{
	srand(time(NULL)); // seed rand once for computer ship generation

	char replay; // replay game loop condition

	try
	{
	  do // start replay game loop
		{
			replay = ' '; // reset replay game loop condition
			
			ifstream inFile("ship_placement.csv"); // user ship placement data
			int shot = 0; // used for passing torpedo data from user to comp objects
			string shipName = " "; // name of hit ship for output
			User user; 
			Computer comp;
			Ship ship; // used for passing misses and ship data from user to comp objects

			// places ships on user gameboard based on input file data
			user.setBoard(inFile); // throws file stream errors

			inFile.close();

			// places ships on computer gameboard based on pseudo random data
			comp.setBoard();
			
			while(!(user.isGameOver() || comp.isGameOver())) // start main game loop
			{
				user.printBoard();
				
				shot = user.getShot(); // request and return torpedo shot from user
				ship = comp.isHit(shot); // checks if torpedo shot hit a comp ship
				
				if(ship.getBoardVal() == ' ') // if user shot was a miss
				{
					user.setShotBoard(shot, ship); // place x on user shotBoard

					cout << "\nYour torpedo shot missed.\n\n";
				}
				else // if user shot was a hit
				{
					comp.processShot(shot, ship); // change hit ship to 'o's on comp gameboard
					user.setShotBoard(shot, ship); // place 'o's on user shotboard

					shipName = getShipName(ship); // convert ship char designator to ship name
					
					cout << "\nYou sunk their " << shipName << "!\n\n";
				}
				
				if(!comp.isGameOver()) // if not all comp ships are sunk
				{
					shot = comp.getShot(); // get and return torpedo shot from comp
					ship = user.isHit(shot); // check if torpedo shot hit a user ship
					
					if(ship.getBoardVal() == ' ') // if comp shot was a miss
					{
						comp.setShotBoard(shot, ship); // place 'x' on comp shotBoard
						user.processShot(shot, ship); // place 'x' on user board

						cout << "Their torpedo missed!\n\n";
					}
					else // if comp shot was a hit
					{
						user.processShot(shot, ship); // change hit ship to 'o's on player board
						comp.setShotBoard(shot, ship); // place 'o's on comp shotBoard

						shipName = getShipName(ship); // convert ship char designator to ship name

						cout << "They sunk your " << shipName << "!\n\n";
					}
				}
				else // if all comp ships are sunk
				{
					cout << "You won!\n\n";
					cout << "Your board:\n\n";
					
					user.printBoard();
					
					cout << "Computer board:\n\n";
					
					comp.printBoard();
				}

				if(user.isGameOver()) // if all user ships are sunk
				{
					cout << "You lost!\n\n";
					cout << "Your board:\n\n";

					user.printBoard();

					cout << "Computer board:\n\n";

					comp.printBoard();
				}
			} // end main game loop

			// query game replay loop
			while(replay != 'Y' && replay != 'y' && replay != 'N' && replay != 'n')
			{
				cout << "Play again? [Y/N]: ";

				cin >> replay;

				if(replay != 'Y' && replay != 'y' && replay != 'N' && replay != 'n')
				{
					cout << "\nInvalid entry.\n\n";

					cin.clear();
					cin.ignore();
				}
			} // end query gameplay loop

			cout << "\n";
			
		} while(replay == 'Y' || replay == 'y'); // end replay game loop
	}
	catch(Error errObj)
	{
		errObj.errOutput(); // formatted text output that describes location
	}                     // of possible file streaming errors
	
	return 0;
}

// converts ship char designator to ship name
string getShipName(const Ship &_ship)
{
	if(_ship.getBoardVal() == 'C')
	{
		return "Carrier";
	}
	else if(_ship.getBoardVal() == 'B')
	{
		return "Battleship";
	}
	else if(_ship.getBoardVal() == 'c')
	{
		return "Cruiser";
	}
	else if(_ship.getBoardVal() == 'S')
	{
		return "Submarine";
	}
	else
	{
		return "Destroyer";
	}
}
