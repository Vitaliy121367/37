#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Song
{
	string name;
	string author;
	int year;
public:
	Song();
	Song(string name, string author, int year);

	void show()const;
	void load(ifstream& file);
};

