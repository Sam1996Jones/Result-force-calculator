#include "Force.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	{
		// section 2 coursework
		vector <string> fileVals;
		vector <Force> ListOfForces;
		ifstream in("ForceList.txt");
		string word;

		while (in >> word)
		{
			fileVals.push_back(word);      //Reads each word in a file and stores it into a vector
		}

		for (int i = 0; i < fileVals.size(); i = i + 3)     //stores the string value of the coord into a char
		{													//converts the string coordinate from the file to a double and stores it in a variable
			Force TempObj(fileVals[i][0], atof(fileVals[i + 1].c_str()), atof(fileVals[i + 2].c_str()));	//creates a temporary object to store objects into a vector of objects
			ListOfForces.push_back(TempObj);
		}

		for (int j = 0; j < ListOfForces.size(); j++)		//Displays force coords in both polar and cartesian
		{
			cout << "Force [" << (j+1) << "]" << endl;
			ListOfForces[j].PrintCoords('c');
			ListOfForces[j].PrintCoords('p');
			cout << "\n";
		}
		
		// section 3 coursework
		Force ResSum('c', 0, 0); //initialise the resultant force to 0;
		for (int z = 0; z < ListOfForces.size(); z++)
			ResSum = ResSum + ListOfForces[z];

		cout << "\nSum of forces in file: " << endl;
		ResSum.PrintCoords('c');
		ResSum.PrintCoords('p');
		cout << "\n\n";

		Force ResForce = -(ListOfForces[0] - ListOfForces[1] + ListOfForces[2]);
		cout << "-(F1 - F2 + F3) = " << endl;
		ResForce.PrintCoords('c');
		ResForce.PrintCoords('p');
		cout << "\n\n"; 
	}
	system("pause");
	return 0;
}
 