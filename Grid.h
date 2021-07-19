// Chris Frey
// CSCI 2312-001
// Final Project

#ifndef GRID_
#define GRID_

#include "Ship.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Grid
{
private:
	Ship carrier;
	Ship battleship;
	Ship cruiser;
	Ship submarine;
	Ship destroyer;
	char board[10][10]; // holds ship locations
	char shotBoard[10][10]; // holds shot locations
	vector<int> shipLog; // holds ship locations to prevent overlays

public:
	Grid();

	// accessors
	Ship getCarrier() const { return carrier; }
	Ship getBattleship() const { return battleship; }
	Ship getCruiser() const { return cruiser; }
	Ship getSubmarine() const { return submarine; }
	Ship getDestroyer() const { return destroyer; }
	
	void printBoard() const;
	void defineShip(const string &_shipName, const char &_xLoc,
									const int &_yLoc, const char &_hv);
	void freeShipLog() { shipLog.clear(); }
	void processShot(const int &_shot, const Ship &_ship);
	void setShotBoard(int _shot, Ship _ship);
	bool placeShip(const Ship &_ship);
	bool isCollision(const Ship &_ship);
	bool isRepeatShot(int _y, int _x) const;
	bool isGameOver() const;
	bool isHit(int _y, int _x) const;
	char getLocChar(int _y, int _x) const;
};
#endif
