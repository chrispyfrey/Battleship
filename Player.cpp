// Chris Frey
// CSCI 2312-001
// Final Project

#include "Player.h"

//*********************************
//
//            PLAYER
//
//*********************************

//////////////////////////////
//    PLAYER: Is Hit
//////////////////////////////

// checks if torpedo shot has hit a ship
Ship Player::isHit(const int &_shot)
{
	int x = 0;
	int y = 0;
	char shipVal = ' ';
	Ship tmpShip;

	x = _shot % 10;

	x == 0 ? x = 10 : x = x; // set x coordinate in int terms
	
	y = (_shot - x) / 10; // set y coordinate in int terms

	if(!gameBoard.isHit(y, x)) // if shot is a miss
	{
		return tmpShip; // return default/empty obj
	}
  else // if shot is a hit
	{
		// get ship char designator from grid location
		shipVal = gameBoard.getLocChar(y, x); 

		if(shipVal == 'C') // if char implies a carrier
		{
			tmpShip = gameBoard.getCarrier(); // set carrier object
		}
		else if(shipVal =='B') // if char implies a battleship
		{
			tmpShip = gameBoard.getBattleship(); // set battleship object
		}
		else if(shipVal == 'c') // if char implies a cruiser
		{
			tmpShip = gameBoard.getCruiser(); // set cruiser object
		}
		else if(shipVal == 'S') // if char implies a submarine
		{
			tmpShip = gameBoard.getSubmarine(); // set submarine object
		}
		else // if char implies a destroyer
		{
			tmpShip = gameBoard.getDestroyer(); // set destroyer object
		}

		return tmpShip; // return ship object
	}
}

//////////////////////////////
//    PLAYER: Process Shot
//////////////////////////////

void Player::processShot(const int &_shot, const Ship &_ship)
{
	gameBoard.processShot(_shot, _ship); 
}

//////////////////////////////
//   PLAYER: Set Shot Board
//////////////////////////////

void Player::setShotBoard(const int &_shot, const Ship &_ship)
{
	gameBoard.setShotBoard(_shot, _ship);
}

//////////////////////////////
//    PLAYER: Print Board
//////////////////////////////

void Player::printBoard()
{
	gameBoard.printBoard();
}

//////////////////////////////
//    PLAYER: Is Game Over
//////////////////////////////

bool Player::isGameOver()
{
	return gameBoard.isGameOver();
}


//*********************************
//
//             USER
//
//*********************************


//////////////////////////////
//    USER: Stream File
//////////////////////////////

// Places ships on user grid based on
// streamed data.
// Throws errors encountered with file
// streaming.
void User::streamFile(ifstream &_inFile)
{
	string ship;
	string loc;
	char xLoc;
	int yLoc;
	string horVer;
	char hv;
	vector<string> shipDuplicate; // stores ship names as they are streamed

	if(!_inFile.is_open())
	{
	  throw Error("ship_placement.csv");
	}

	getline(_inFile, ship); // discard first line

	for(int i = 0; i < 5; ++i) // start main stream loop
	{
		getline(_inFile, ship, ','); // get ship data

		for(int c = 0; c < ship.size(); ++c) // convert ship string to lowercase
		{
			ship[c] = tolower(ship[c]);
		}

		// if ship data is not valid
		if(ship != "carrier" && ship != "battleship" && ship != "cruiser"
			 && ship != "submarine" && ship != "destroyer")
		{
			throw Error("ship_placement.csv", "Ship", i + 2); // invalid ship type
		}
		else // if ship data is valid
		{
			if(shipDuplicate.empty()) // if ship name vector is empty
			{
				shipDuplicate.push_back(ship); // push valid ship
			}
			else // if ship name vector is not empty
			{
				for(int y = 0; y < shipDuplicate.size(); ++y)
				{
					if(shipDuplicate[y] == ship) // check if ship name is already in vector
					{
						throw Error("ship_placement.csv", "duplicate Ship", i + 2); // duplicate ship type
					}
				}
				
				shipDuplicate.push_back(ship); // push valid ship
			}
		}

		getline(_inFile, loc, ','); // get location data

		loc[0] = tolower(loc[0]); // convert location string to lowercase
		
		xLoc = loc[0]; // set X coord (a-j)

		if(xLoc < 97 || xLoc > 106) // if X coord is out of range
		{
			throw Error("ship_placement.csv", "Location", i + 2); // X coord out of range
		}
		
		loc.erase(0, 1); // remove X coord from location string

		if(!checkY(loc)) // if Y coord is out of range
		{
			throw Error("ship_placement.csv", "Location", i + 2); // Y coord out of range
		}

	  yLoc = stoi(loc); // convert string of Y coord to integer
	  
		getline(_inFile, horVer, '\n'); // get horizontal or vertical data

		hv = tolower(horVer[0]); // convert H/V string to lowercase 

		if(hv != 'h' && hv != 'v') // if H/V data is out of range
		{
			throw Error("ship_placement.csv", "Horizontal or Vertical", i + 2); // H/V out of range
		}

		gameBoard.defineShip(ship, xLoc, yLoc, hv); // define ship object with valid data
		
	} // end main stream loop
}

//////////////////////////////
//      USER: Check Y
//////////////////////////////

// returns Y coord in valid range
bool User::checkY(const string &_y) const
{
	return _y == "1" || _y == "2" || _y == "3" || _y == "4" || _y == "5"
		|| _y == "6" || _y == "7" || _y == "8" || _y == "9" || _y == "10";
}

//////////////////////////////
// USER: Set Board : Virtual
//////////////////////////////

// Places ship objects on grid.
// Throws errors with ship overlays
// or ship lying off grid.
void User::setBoard(ifstream &_inFile)
{
  streamFile(_inFile); // stream ship data
	
	if(!gameBoard.placeShip(gameBoard.getCarrier()))
	{
		throw Error("ship_placement.csv", "Carrier");
	}
	if(!gameBoard.placeShip(gameBoard.getBattleship()))
	{
		throw Error("ship_placement.csv", "Battleship");
	}
	if(!gameBoard.placeShip(gameBoard.getCruiser()))
	{
		throw Error("ship_placement.csv", "Cruiser");
	}
	if(!gameBoard.placeShip(gameBoard.getSubmarine()))
	{
		throw Error("ship_placement.csv", "Submarine");
	}
	if(!gameBoard.placeShip(gameBoard.getDestroyer()))
	{
		throw Error("ship_placement.csv", "Destroyer");
	}
	
	gameBoard.freeShipLog(); // free location collision vector memory
}

//////////////////////////////
//  USER: Get Shot : Virtual
//////////////////////////////

// Request torpedo shot data from user.
// Returns shot data as one integer
int User::getShot()
{
	char xChar = ' ';
	string yStr = " ";
	int x = 0;
	int y = 0;
	int coord = 0;

	do // start input loop
	{ // while X coord is out of range ASCII math
		
		while(xChar < 65 || (xChar > 74 && xChar < 97) || xChar > 106)
		{
			cout << "Enter a X (horizontal) coordinate for your torpedo shot (A-J), or\n";
			cout << "enter 'q' to exit the game: ";
			
			cin >> xChar;
			
			if(xChar == 'q' || xChar == 'Q') // if user wants to exit game
			{
				exit(0);
			}

			// if X coord is out of range
			if(xChar < 65 || (xChar > 74 && xChar < 97) || xChar > 106)
			{
				cout << "\nInvalid entry.\n\n";
																				 
				
				cin.clear();
				cin.ignore();
			}
		} // end while X coord is out of range

		cin.ignore(); // called before getline() function to prevent input issues

		while(!checkY(yStr)) // while Y coord is out of range
		{
			cout << "\nEnter a Y (vertical) coordinate for your torpedo shot (1-10), or\n";
			cout << "enter 'q' to exit the game: ";
			
			getline(cin, yStr);
			
			if(yStr == "q" || yStr == "Q") // if user wants to exit game
			{
				exit(0);
			}

			// if Y coord is out of range
			if(!checkY(yStr))
			{
				cout << "\nInvalid entry.\n";
			}
		}

		xChar = tolower(xChar); // convert X coord to lowercase
		x = (xChar - 96); // convert X coord to int ASCII math
		y = stoi(yStr); // convert Y coord to int

		if(gameBoard.isRepeatShot(y, x)) // if shot has already be made
		{
			cout << "\nThat shot has already been made!\n\n";

			xChar = ' ';
			yStr = " ";
		}

		// while shot coord has not already been used
	} while(gameBoard.isRepeatShot(y, x)); // end input loop

	coord = x + (y * 10); // convert X, Y coord to one integer
	
	return coord; // return shot coord
}


//*********************************
//
//            COMPUTER
//
//*********************************


/////////////////////////////////
// COMPUTER: Set Board : Virtual
/////////////////////////////////

// Get psuedo random ship data from computer.
// Place ships on computer grid
void Computer::setBoard()
{
  int hvRand = 0;
	int y = 0;
	char x = 0;
	char hv = ' ';

	for(int i = 0; i < 5; ++i) // start ship data gen loop
	{
		hvRand = rand() % 2; // gen random horizontal or vertical
		y = rand() % 10 + 1; // gen random y coord
		x = rand() % 10 + 97; // gen random x coord ASCII math

		if(hvRand == 1)
		{
			hv = 'v'; // set horizontal/vertical
		}
		else
		{
			hv = 'h'; // set horizontal/vertical
		}

		if(i == 0) // if iter 0
		{
			gameBoard.defineShip("carrier", x, y, hv); // define carrier object

			// try to place carrier, re-do loop iter if ship overlay
			if(!gameBoard.placeShip(gameBoard.getCarrier()))
			{
				--i;
			}
		}
		else if(i == 1) // if iter 1
		{
			gameBoard.defineShip("battleship", x, y, hv); // define battleship object

			// try to place battleship, re-do loop iter if ship overlay
			if(!gameBoard.placeShip(gameBoard.getBattleship()))
			{
				--i;
			}
		}
		else if(i == 2) // if iter 2
		{
			gameBoard.defineShip("cruiser", x, y, hv); // define cruiser object

			// try to place cruiser, re-do loop iter if ship overlay
			if(!gameBoard.placeShip(gameBoard.getCruiser()))
			{
				--i;
			}
		}
		else if(i == 3)
		{
			gameBoard.defineShip("submarine", x, y, hv); // define submarine object

			// try to place submarine, re-do loop iter if ship overlay
			if(!gameBoard.placeShip(gameBoard.getSubmarine()))
			{
				--i;
			}
		}
		else
		{
			gameBoard.defineShip("destroyer", x, y, hv); // define destroyer object

			// try to place destroyer, re-do loop iter if ship overlay
			if(!gameBoard.placeShip(gameBoard.getDestroyer()))
			{
				--i;
			}
		}
	} // end ship data gen loop

	gameBoard.freeShipLog(); // free collision vector memory
}

////////////////////////////////
// COMPUTER: Get Shot : Virtual
////////////////////////////////

// Generates psuedo random torpedo shot coord
int Computer::getShot()
{
	int x = 0;
	int y = 0;
	int coord = 0;

	do
	{
	  x = rand() % 10 + 1; // gen int 1-10
		y = rand() % 10 + 1; // gen int 1-10
		
	} while(gameBoard.isRepeatShot(y, x));

	coord = x + (y * 10); // combine shot coords into one int
	
	return coord; // return shot coord
}
