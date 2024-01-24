#include "Force.h"

/*
Constructor to initialise variables
*/
Force::Force(char coordType , double val1 , double val2 ) 
{
	
	if (coordType == 'c' || coordType == 'p' || coordType == 'P' || coordType == 'C')	//if statement to determine if the user has input a coord type.
		PorC = tolower(coordType);						
	else
		PorC = 'c';				//if the user only inputs coords then cartesian is default 
		
	switch (PorC) {
	case 'p':						//Stores polar coordinates
		PolarCoord.push_back(val1);
		PolarCoord.push_back(val2);
		ConvertCoords('c');			//converts and stores cartesian coords
		break;
	case 'c':						//stores cartesian coords
		CartesianCoord.push_back(val1);
		CartesianCoord.push_back(val2);
		ConvertCoords('p');			//converts and stores polar coords
		break;
	}
}

/*
Returns coordinates as a vector
*/
vector <double> Force::ReturnCoords(char CoordType) 
{
	switch (CoordType) {
	case 'p':					//returns polar coordinates
		return PolarCoord;
		break;
	case 'c':					//returns cartesian coordinates
		return CartesianCoord;
		break;
	}
}

/*
converts coords to other coord type and stores into a vector
type 'p' converts to polar
type 'c' converts to cartesian
*/
void Force::ConvertCoords(char type)
{
		switch (type) {
		case 'p':					//converts coords to Polar
			PolarCoord.push_back(sqrt((CartesianCoord[0] * CartesianCoord[0]) + (CartesianCoord[1] * CartesianCoord[1])));
			PolarCoord.push_back(atan(CartesianCoord[1] / CartesianCoord[0]));
			break;

		case 'c':					//converts coords to cartesian
			CartesianCoord.push_back((PolarCoord[0] * cos(PolarCoord[1])));
			CartesianCoord.push_back((PolarCoord[0] * sin(PolarCoord[1])));
			break;
		}
}

/*
This function prints the coordinates in either cartesian or polar form
*/
void Force::PrintCoords(char type)
{
	if (type == 'c')
	cout << "Cartesian coordinates:  " << "(" << CartesianCoord[0] << "," << CartesianCoord[1] << ")" << endl;
	else if (type == 'p')
	cout << "Polar coordinates:  " << "(" << PolarCoord[0] << "," << PolarCoord[1] << ")" << endl;
}

/*
Allows modification of the two types of coordinate forms.
*/
void Force::ModifyCoords(char type, double val1, double val2)
{
	switch (type) {
	case 'p':					//modify polar coordinates
		PolarCoord[0] = val1;
		PolarCoord[1] = val2;
		CartesianCoord.pop_back(); //Clears previous cartesian coordinates so that modified coords can be added to the vector
		CartesianCoord.pop_back(); 
		ConvertCoords('c');		//converts newly modified polar coords to cartesian
		break;
	case 'c':					//modify cartesian coordinates
		CartesianCoord[0] = val1;
		CartesianCoord[1] = val2;
		PolarCoord.pop_back();
		PolarCoord.pop_back();	//clears previous polar coords so that modified coords can be pushed on to the vector
		ConvertCoords('p');		//converts newly modified cartesian coords to polar 
		break;
	}
}

/*
Overload + operator to add two force objects
*/
Force Force::operator+(Force F)
{
	vector <double> Ccords = F.ReturnCoords('c');
	Force Res('c', (CartesianCoord[0] + Ccords[0]), CartesianCoord[1] + Ccords[1]);
	return Res;
}

/*
Overload - operator to subtract two force objects
*/
Force Force::operator-(Force F)
{
	vector <double> Ccords = F.ReturnCoords('c');
	Force Res('c', (CartesianCoord[0] - Ccords[0]), CartesianCoord[1] - Ccords[1]);
	return Res;
}

/*
Overload - operator... F = -F
*/
Force Force::operator-()
{
	Force F('c', -(CartesianCoord[0]), -(CartesianCoord[1]));
	return F;
}