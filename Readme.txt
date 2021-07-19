*******************************************************
*  Name      : Christopher Frey         
*  Student ID: 108198583 
*  Class     : CSCI 2312 001           
*  HW#       : Final Project                
*  Due Date  : November 28, 2017
*
*******************************************************
		     Read Me
*******************************************************
*  	     Description of the program
*******************************************************
This program implements a version of the Battleship game.

The Gameboard on the left shows the placement of your 
ships as read from the ship_placement.csv file and the 
shots of your opponent. If one of you ships is hit, the
ships identifying character is changed to a o's. If your
opponent's shot missed, its location is displayed as an
"x".

The Shotboard on the right shows your shots. If you hit
one of your opponent's ships, the placement of that ship
is represented on your Shotboard by o's. Your misses 
are displayed on your Shotboard by x's.

It only takes one hit on a ship to sink that ship.

Your opponent's Gameboard and Shotboard are displayed
at the conclusion of the game.

The game may be played again without exiting the program.

Semi-specific error output is displayed in the event that
there is an error encountered while reading the provided
ship data file.

The game may be exited during shot coordinate input by
entering 'q' or 'Q'.

-------------------------------------------------------

At the highest level, this program is run by the Computer
and User classes which are derived from the Player class.

Operations that modify the 2D arrays that represent the
Gameboard and Shotboard are performed by calls to the Grid 
class which is a member of the Player class.

The Ship class lies at the lowest level. Each Grid class
contains five instances of the Ship class (one for each 
unique ship). The Ship class is used largely for data 
storage and contains a "=" operator overload used for
making direct copies of the calling Ship class.

The Error class is used to report three unique errors
that may be encountered while reading ship data from 
the in-file and placing those ships on the User Gameboard.

*******************************************************
*  Source files
*******************************************************
Name: 	main.cpp
      	Main program.  
	Contains main function, high level program 
	loops, and minor input/output. Drives program 
	by defining necessary objects and calling
	their member functions.
	
	Player.h
	Header File
	Contains Player class and it's two derived
	classes: User and Computer.
	All three classes contain a Grid object. 
	Two member functions are defined as virtual. 

	Player.cpp
	Function File
	Contains member function definitions for 
	the Player, User, and Computer class.

	Grid.h
	Header File
	Contains the Grid class. 
	The grid class contains five Ship classes.

	Grid.cpp
	Function File
	Contains member function definitions for the
	Grid class.

	Ship.h
	Header File
	Contains the Ship class which stores ship
	attributes. 

	Exception.h
	Header File
	Contains the Error class. 

	Exception.cpp
	Function File
	Contains member function definitions for the
	Error class.

-------------------------------------------------------

	ship_placement.csv
	Comma Seperated Valu File
	Contains valid user ship attributes.

*******************************************************
*  Circumstances of programs
*******************************************************
This program runs successfully.  

Text editing was performed in GUI Emacs.

Program developed and tested on GUI g++ (GCC) 5.4.0
(Linux terminal).

Program compiled, run, and tested on g++ (GCC) 4.8.2 (csegrid.ucdenver.pvt).

*******************************************************
*  How to build and run the program
*******************************************************
1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
   
   unzip FreyFP

   Now you should see a directory named homework with the files:

   main.cpp
   Player.h
   Player.cpp
   Grid.h
   Grid.cpp
   Ship.h
   Exception.h
   Exception.cpp
   ship_placement.csv
   makefile
   Readme.txt

2. Build the program.

   Change to the directory that contains the file by:
   cd FreyFP

   Compile the program by:
   make

3. Run the program by:
   ./battleship

4. Delete the obj files, executables, and core dump by
   make clean
