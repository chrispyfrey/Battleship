// Chris Frey
// CSCI 2312-001
// Final Project

#include "Grid.h"

///////////////////////////////////
//       Default Constructor
///////////////////////////////////

Grid::Grid()
{
	// set known carrier data
  carrier.setSize(5);
	carrier.setBoardVal('C');

	// set known battleship data
	battleship.setSize(4);
	battleship.setBoardVal('B');

	// set known cruiser data
	cruiser.setSize(3);
	cruiser.setBoardVal('c');

	// set known submarine data
	submarine.setSize(3);
	submarine.setBoardVal('S');

	// set known destroyer data
	destroyer.setSize(2);
	destroyer.setBoardVal('D');

	// set 2d array to contain whitespace
	for (int c = 0; c < 10; ++c)
	{
		for (int r = 0; r < 10; ++r)
		{
			board[c][r] = ' ';
		}
	}

	for (int c = 0; c < 10; ++c)
	{
		for (int r = 0; r < 10; ++r)
		{
			shotBoard[c][r] = ' ';
		}
	}
}

///////////////////////////////////
//        Print Board
///////////////////////////////////

// Prints formatted 2d arrays that
// represent the gameboard and shotboard
void Grid::printBoard() const
{
	cout << "            Gameboard                         Shotboard\n";
	cout << "   A  B  C  D  E  F  G  H  I  J      A  B  C  D  E  F  G  H  I  J\n";
	
	for (int y = 0; y < 10; ++y)
	{
		if (y < 9)
		{
			cout << '0' << y + 1;
		}
		else
		{
			cout << y + 1;
		}
		
		for (int x = 0; x < 10; ++x)
		{
			cout << '[' << board[y][x] << ']';
		}

		cout << "  ";

		if (y < 9)
		{
			cout << '0' << y + 1;
		}
		else
		{
			cout << y + 1;
		}
			
		for (int x = 0; x < 10; ++x)
		{
			cout << '[' << shotBoard[y][x] << ']';
		}

		cout << '\n';
	}

	cout << '\n';
}

///////////////////////////////////
//          Define Ship
///////////////////////////////////

// Defines ship objects
void Grid::defineShip(const string &_shipName, const char &_xLoc,
											const int &_yLoc, const char &_hv)
{
	if(_shipName == "carrier")
	{
	  carrier.setYLoc(_yLoc);
		carrier.setXLoc(_xLoc);
		carrier.setVertical(_hv);
	}
	else if(_shipName == "battleship")
	{
		battleship.setYLoc(_yLoc);
		battleship.setXLoc(_xLoc);
		battleship.setVertical(_hv);
	}
	else if(_shipName == "cruiser")
	{
		cruiser.setYLoc(_yLoc);
		cruiser.setXLoc(_xLoc);
		cruiser.setVertical(_hv);
	}
	else if(_shipName == "submarine")
	{
		submarine.setYLoc(_yLoc);
		submarine.setXLoc(_xLoc);
		submarine.setVertical(_hv);
	}
	else
	{
		destroyer.setYLoc(_yLoc);
		destroyer.setXLoc(_xLoc);
		destroyer.setVertical(_hv);
	}
}

///////////////////////////////////
//        Process Shot
///////////////////////////////////

// Processes torpedo shots
void Grid::processShot(const int &_shot, const Ship &_ship)
{
  int x = 0;
	int y = 0;
	

	if(_ship.getBoardVal() == ' ') // if shot is a miss
	{
		x = _shot % 10; 

		x == 0 ? x = 10 : x = x; // set shot X coord

		y = (_shot - x) / 10; // set shot Y coord

		--x; // decrement for direct use on array
		--y;

		board[y][x] = 'x'; // place 'x' on shotboard @ coord
	}
	else // if shot is a hit
	{
		int shipSize = 0;

		x = _ship.getXLoc() - 96; // set hit ship X coord ASCII math
	
		y = _ship.getYLoc(); // set hit ship Y coord

		--x; // decrement for direct use on array
		--y;
		
		if(_ship.getBoardVal() == 'C') // if hit ship is a carrier
		{
			carrier.setSunk(true);

			shipSize = _ship.getSize();
			
			if(_ship.getVertical()) // if carrier is vertical
			{
				for(int i = 0; i < shipSize; ++i) // replace carrier with 'o's
				{
					board[y][x] = 'o';

					++y;
				}
			}
			else // if carrier is horizontal
			{
				for(int i = 0; i < shipSize; ++i)
				{
					board[y][x] = 'o'; // replace carrier with 'o's
					
					++x;
				}
			}
		}
		else if(_ship.getBoardVal() == 'B') // if hit ship is a battleship
		{
			battleship.setSunk(true);
			
			shipSize = _ship.getSize();
			
			if(_ship.getVertical()) // if battleship is vertical
			{
				for(int i = 0; i < shipSize; ++i)
				{
					board[y][x] = 'o'; // replace battleship with 'o's

					++y;
				}
			}
			else // if battleship is horizontal
			{
				for(int i = 0; i < shipSize; ++i)
				{
					board[y][x] = 'o'; // replace battleship with 'o's

					++x;
				}
			}
		}
		else if(_ship.getBoardVal() == 'c') // if hit ship is a cruiser
		{
			cruiser.setSunk(true);
			
			shipSize = _ship.getSize();
			
			if(_ship.getVertical()) // if cruiser is vertical
			{
				for(int i = 0; i < shipSize; ++i)
				{
					board[y][x] = 'o'; // replace cruiser with 'o's

					++y;
				}
			}
			else // if cruiser is horizontal
			{
				for(int i = 0; i < shipSize; ++i)
				{
					board[y][x] = 'o'; // replace cruiser with 'o's

					++x;
				}
			}
		}
		else if(_ship.getBoardVal() == 'S') // if hit ship is a submarine
		{
			submarine.setSunk(true);
			
			shipSize = _ship.getSize();
			
			if(_ship.getVertical()) // if submarine is vertical
			{
				for(int i = 0; i < shipSize; ++i)
				{
					board[y][x] = 'o'; // replace submarine with 'o's

					++y;
				}
			}
			else // if submarine is vertical
			{
				for(int i = 0; i < shipSize; ++i)
				{
					board[y][x] = 'o'; // replace submarine with 'o's

					++x;
				}
			}
		}
		else // if hit ship is a destroyer
		{
			destroyer.setSunk(true);
			
			shipSize = _ship.getSize();
			
			if(_ship.getVertical()) // if destroyer is vertical
			{
				for(int i = 0; i < shipSize; ++i)
				{
					board[y][x] = 'o'; // replace destroyer with 'o's

					++y;
				}
			}
			else // if destroyer is horizontal
			{
				for(int i = 0; i < shipSize; ++i)
				{
					board[y][x] = 'o'; // replace destroyer with 'o's

					++x;
				}
			}
		}
	}
}

///////////////////////////////////
//        Set Shot Board
///////////////////////////////////

// Places missed shots and hit ships
// on the shotboard.
void Grid::setShotBoard(int _shot, Ship _ship)
{
	int x = 0;
	int y = 0;

	if(_ship.getBoardVal() == ' ') // if shot is a miss
	{
		x = _shot % 10; 

		x == 0 ? x = 10 : x = x; // set X shot coord

		y = (_shot - x) / 10; // set Y shot coord

		--x; // decrement for direct use on array
		--y;
		
		shotBoard[y][x] = 'x'; // place 'x' on coord on shotboard
	}
	else // if shot is a hit
	{
		int shipSize = 0;

		x = _ship.getXLoc() - 96; // set hit ship X coord ASCII math
	
		y = _ship.getYLoc(); // set hit ship Y coord

		--x; // decrement for direct use on array
		--y;
		
		shipSize = _ship.getSize();

		if(_ship.getVertical()) // if hit ship is vertical
		{
			for(int i = 0; i < shipSize; ++i)
			{
				shotBoard[y][x] = 'o'; // place 'o's on shotboard where hit ship was

				++y;
			}
		}
		else // if hit ship is horizontal
		{
			for(int i = 0; i < shipSize; ++i)
			{
				shotBoard[y][x] = 'o'; // place 'o's on shotboard where hit ship was

				++x;
			}
		}
	}
}

///////////////////////////////////
//        Place Ship
///////////////////////////////////

// Places passed ship on board/grid.
// Returns false if overlay or
// out of bounds is encounterd.
bool Grid::placeShip(const Ship &_ship)
{
	int y = _ship.getYLoc();
	int x = (_ship.getXLoc() - 96);
	int shipSize = _ship.getSize();
	int bound = 11 - shipSize;
	char v = _ship.getBoardVal();
	bool isVertical = _ship.getVertical();

	// if out of bounds error is encounterd
	if((isVertical && y > bound) || (!isVertical && x > bound))
	{
	  return false;
	}
	else if(!isCollision(_ship)) // if ship overlay is encounterd
	{
		return false;
	}
	else // if no errors are encountered
	{
		--y; // decrement for direct use on array
		--x;
		
		if(!isVertical) // if ship is vertical
		{
			for(int i = 0; i < shipSize; ++i) // place ship
			{
				board[y][x] = v;

				++x;
			}
		}
		else // if ship is horizontal
		{
			for(int i = 0; i < shipSize; ++i) // place ship
			{
				board[y][x] = v;
				
				++y;
			}
		}

		return true;
	}
}

///////////////////////////////////
//         Is Collision
///////////////////////////////////

// Check if a ship is already occupying
// a location of passed ship.
// Returns true if error is encountered
bool Grid::isCollision(const Ship &_ship)
{
  int y = _ship.getYLoc();
	int x = (_ship.getXLoc() - 96);
	int loc = x + (y * 10); // ship location int
	int locCopy = 0;
	int shipSize = _ship.getSize();
	bool isVertical = _ship.getVertical();

	if(shipLog.empty()) // if passed ship is the first ship
	{
		if(!isVertical) // if first ship is horizontal
		{
			for(int i = 0; i < shipSize; ++i) // push all ship grid coords
			{
				shipLog.push_back(loc);

				++loc; // increment location int
			}
		}
		else // if first ship is vertical
		{
			for(int i = 0; i < shipSize; ++i) // push all ship grid coords
			{
				shipLog.push_back(loc);

				loc += 10; // increment location int by 10
			}
		}

		return true;
	}
	else // if passed ship is not the first ship
	{
		if(!isVertical) // if ship is horizontal
		{
			// check passed ship locations for collisions with previously laid ships
			for(int i = 0; i < shipLog.size(); ++i) 
			{
				locCopy = loc;
				
				for(int iter = 0; iter < shipSize; ++iter)
				{
					if(shipLog[i] == locCopy) // if a ship already lies in passed ship coords
					{
						return false;
					}

					++locCopy;
				}
			}

			for(int i = 0; i < shipSize; ++i) // push all ship grid coords
			{
				shipLog.push_back(loc);

				++loc;
			}
			
			return true;
		}
		else // if ship is vertical
		{
			// check passed ship locations for collisions with previously laid ships
			for(int i = 0; i < shipLog.size(); ++i)
			{
				locCopy = loc;
				
				for(int iter = 0; iter < shipSize; ++iter)
				{
					if(shipLog[i] == locCopy) // if a ship already lies in passed ship coords
					{
						return false;
					}
 
					locCopy += 10;
				}
			}

			for(int i = 0; i < shipSize; ++i) // push all ship grid coords
			{
				shipLog.push_back(loc);

				loc += 10;
			}

			return true;
		}
	}
}

///////////////////////////////////
//        Is Repeat Shot
///////////////////////////////////

// Check shotboard for duplicate shot
// Returns true if duplicate shot
bool Grid::isRepeatShot(int _y, int _x) const
{
	--_x; // decrement for direct use on array
	--_y;
	
	return shotBoard[_y][_x] == 'x' || shotBoard[_y][_x] == 'o';
}

///////////////////////////////////
//         Is Game Over
///////////////////////////////////

// Check if all ships are sunk.
// Returns true if all ships are sunk.
bool Grid::isGameOver() const
{
	return carrier.getSunk() && battleship.getSunk() && cruiser.getSunk()
		&& submarine.getSunk() && destroyer.getSunk();
}

///////////////////////////////////
//            Is Hit
///////////////////////////////////

// Check if torpedo shot hit a ship.
// Returns true if the shot was a hit.
bool Grid::isHit(int _y, int _x) const
{
	--_x; // decrement for direct use on array
	--_y;
	
	return !(board[_y][_x] == ' ' || board[_y][_x] == 'o');
}

///////////////////////////////////
//     Get Location Character
///////////////////////////////////

// Return the character that lies
// in the passed coordinate position
// on board/grid.
char Grid::getLocChar(int _y, int _x) const
{
	--_x; // decrement for direct use on array
	--_y;
		
	return board[_y][_x];
}
