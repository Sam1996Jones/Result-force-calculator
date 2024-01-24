#ifndef Force_H
#define Force_H

#include <iostream>
#include <vector>
#include "cmath"
using namespace std;

class Force {
	char PorC; //Polar or Cartesian
	vector <double> CartesianCoord; //Vector to hold x & y (cartesian )
	vector <double> PolarCoord;		//Vector to hold r & theta (Polar)

	/*
	converts coords to other coord type and stores into a vector
	type 'p' converts to polar
	type 'c' converts to cartesian
	*/
	void ConvertCoords(char type); 
	
public:

	/*
	Constructor to initialise variables
	CoordType is either 'p' for polar or 'c' for cartesian
	*/
	Force(char coordType = 'c', double val1 = 5 , double val2 = 5 ); //Default cartesian (5,5)
	
	/*
	destructor to clear vector memory
	*/
	~Force() { CartesianCoord.pop_back(), CartesianCoord.pop_back(), PolarCoord.pop_back(), PolarCoord.pop_back(); }; //inline 

	/*
	Returns coordinates as a vector
	CoordType is either 'p' for polar or 'c' for cartesian
	*/
	vector <double> ReturnCoords(char CoordType = 'c'); 

	/*
	This function prints the coordinates in either cartesian or polar form
	CoordType is either 'p' for polar or 'c' for cartesian
	*/
	void PrintCoords(char type = 'c'); 

	 /*
	Allows modification of the two types of coordinate forms.
	'p' to modify polar 
	'c' to modify cartesian
	*/
	void ModifyCoords(char type, double val1, double val2); 
	
	/*
	Overload + operator to add two force objects
	*/
	Force operator+(Force F);

	/*
	Overload - operator to subtract two force objects
	*/
	Force operator-(Force F);

	/*
	Overload - operator... F = -F
	*/
	Force operator-();
};

#endif