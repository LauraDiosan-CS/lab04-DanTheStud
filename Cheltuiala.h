#pragma once

#include <ostream>

using namespace std;

class Cheltuieli 
{
private:

	int zi;
	int sumaBani;
	char* tip;

public:

	Cheltuieli();
	Cheltuieli(int zi, int sumaBani, char* tip);
	~Cheltuieli();
	Cheltuieli(const Cheltuieli& c);

	int getZi();
	int getSumaBani();
	char* getTip();

	Cheltuieli& operator=(const Cheltuieli& c);

	bool operator==(const Cheltuieli& c);
	void setZi(int zi);
	void setSumaBani(int sumaBani);
	void setTip(char* tip);

	friend ostream& operator<<(ostream& os, const Cheltuieli& c);
};