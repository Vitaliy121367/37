#include "Song.h"

Song::Song()
{
	name = "undefined";
	author = "undefined";
	year = 0;
}

Song::Song(string name, string author, int year)
{
	this->name = name;
	this->author = author;
	this->year = year;
}

void Song::show() const
{
	cout << "Name: " << name << endl;
	cout << "Author: " << author << endl;
	cout << "Year: " << year << endl;
}

void Song::load(ifstream& file)
{
	getline(file, name);
	getline(file, author);
	file >> year;
	file.get();
}
