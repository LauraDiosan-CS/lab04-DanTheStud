#include <iostream>
#include "Test.h"
#include "Console.h"

using namespace std;

int main() 
{
	test_cheltuieli_familie();
	test_repo_cheltuieli_familie();
	test_service_cheltuieli_familie();

	Console c;
	c.console();

	return 0;
}					