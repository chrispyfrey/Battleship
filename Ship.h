// Chris Frey
// CSCI 2312-001
// Final Project

#ifndef SHIP_
#define SHIP_

class Ship
{
private:
	int size;
	int hits;
	int yLoc;
	char xLoc;
	char boardVal;
	bool isVertical;
	bool isSunk;
	
public:
	Ship() { size = 0, hits = 0, yLoc = 0, xLoc = ' ',
			boardVal = ' ', isVertical = false, isSunk = false; }

	// mutators
	void setSize(const int &_size) { size = _size; }
	void setHits(const int &_hits) { hits = _hits; }
	void setYLoc(const int &_yLoc) { yLoc = _yLoc; }
	void setXLoc(const char &_xLoc) { xLoc = _xLoc; }
	void setBoardVal(const char &_boardVal) { boardVal = _boardVal;}
	void setVertical(const char &_hv) { _hv == 'v' ? isVertical = true : isVertical = false; }
	void setSunk(const bool &_isSunk) { isSunk = _isSunk; }

	// accessors
	int getSize() const { return size; }
	int getHits() const { return hits; }
	int getYLoc() const { return yLoc; }
	char getXLoc() const { return xLoc; }
	char getBoardVal() const { return boardVal; }
	bool getVertical() const { return isVertical; }
	bool getSunk() const { return isSunk; }

	// direct object copy operator overload
	Ship operator = (const Ship &rhs)
	{
		size = rhs.size;
		hits = rhs.hits;
		yLoc = rhs.yLoc;
		xLoc = rhs.xLoc;
		boardVal = rhs.boardVal;
		isVertical = rhs.isVertical;
		isSunk = rhs.isSunk;
		
		return *this;
	}
};
#endif
