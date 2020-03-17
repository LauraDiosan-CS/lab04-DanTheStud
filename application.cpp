#include <iostream>
#include "Tests.h"
#include "Cheltuiala.h"

using namespace std;

int main() 
{
	test_cheltuieli();
	test_repo_cheltuieli();

	int zi;
	int sumaBani;
	char tip[100];
	cout << "Dati ziua: ";
	cin >> zi;
	cout << "Dati suma: ";
	cin >> sumaBani;
	cout << "Dati tipul: ";
	cin >> tip;
	Cheltuieli c1(zi, sumaBani, tip);
	cout << c1;

	Cheltuieli c2(c1);
	Cheltuieli c3 = c1;
	Cheltuieli c4;
	c4 = c2;

	return 0;
}