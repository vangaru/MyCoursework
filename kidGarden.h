#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct kidGarden {
	char cipher[15];
	int numKids;
	char surname[20];
	char grd[20];
	enum grade { Younger = 1, Middle = 2, Older = 3, Preparatory = 4 };
	union foreignGroups {
		int numfG;
		char namefG;
		foreignGroups() {};
		~foreignGroups() {};
	}forGrp;
};

