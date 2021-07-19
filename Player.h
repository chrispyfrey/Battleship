// Chris Frey
// CSCI 2312-001
// Final Project

#ifndef PLAYER_
#define PLAYER_

#include "Grid.h"
#include "Error.h"
#include <fstream>
#include <cstdlib>
#include <cctype>

//////////////////////////////
//   Parent: Player Class
//////////////////////////////

class Player
{
protected:
	Grid gameBoard;

public:
	virtual void setBoard() { cout << "Not defined for base class.\n"; }
	virtual int getShot() { cout << "Not defined for base class.\n\n"; }
	
	Ship isHit(const int &_shot);
  void processShot(const int &_shot, const Ship &_ship);
  void setShotBoard(const int &_shot, const Ship &_ship);
	void printBoard();
	bool isGameOver();
};

//////////////////////////////
//    Child: User Class
//////////////////////////////

class User : public Player
{
private:
	void streamFile(ifstream &_inFile);
	bool checkY(const string &_y) const;
	
public:
	virtual void setBoard(ifstream &_inFile);
	virtual int getShot();
};

//////////////////////////////
//   Child: Computer Class
//////////////////////////////

class Computer : public Player
{
public:
	virtual void setBoard();
	virtual int getShot();
 };
#endif
