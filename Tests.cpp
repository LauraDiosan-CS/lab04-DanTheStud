#include "Tests.h"
#include "Cheltuiala.h"
#include <string.h>
#include <cassert>
#include "Repo.h"

void test_cheltuieli() 
{
	char* tip_1 = new char[10];
	char* tip_2 = new char[10];
	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");
	Cheltuieli c1(3, 25, tip_1);
	Cheltuieli c2(3, 25, tip_1);
	assert(c1.getZi() == 3);
	assert(c1.getSumaBani() == 25);
	assert(strcmp(c1.getTip(), "haine") == 0);
	assert(c1 == c2);
	c1.setZi(9);
	c1.setSumaBani(200);
	c1.setTip(tip_2);
	assert(c1.getZi() == 9);
	assert(c1.getSumaBani() == 200);
	assert(strcmp(c1.getTip(), "mancare") == 0);
}

void test_repo_cheltuieli() 
{
	char* tip_1 = new char[10];
	char* tip_2 = new char[10];
	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");
	Cheltuieli c1(3, 50, tip_1);
	Cheltuieli c2(6, 60, tip_2);
	Repo repository_cheltuieli;
	repository_cheltuieli.addElem(c1);
	repository_cheltuieli.addElem(c2);
	assert(repository_cheltuieli.getSize() == 2);
	assert(repository_cheltuieli.getAll()[0] == c1);
	assert(repository_cheltuieli.getAll()[1] == c2);
}