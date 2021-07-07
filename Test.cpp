#include "Test.h"
#include <string.h>
#include <cassert>
#include "Service.h"

void test_cheltuieli_familie() 
{
	char* tip_1 = new char[10];
	char* tip_2 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");

	Cheltuieli c1(3,25,tip_1);
	Cheltuieli c2(3, 25, tip_1);

	assert(c1.getZi() == 3);
	assert(c1.getSumaBani() == 25);
	assert( strcmp(c1.getTip(),"haine")==0);
	assert(c1 == c2);

	c1.setZi(9);
	c1.setSumaBani(200);
	c1.setTip(tip_2);

	assert(c1.getZi() == 9);
	assert(c1.getSumaBani() == 200);
	assert(strcmp(c1.getTip(), "mancare") == 0);

	delete[] tip_1;
	delete[] tip_2;
}

void test_repo_cheltuieli_familie() 
{
	char* tip_1 = new char[10];
	char* tip_2 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");

	Cheltuieli c1(3, 50, tip_1);
	Cheltuieli c2(6, 60, tip_2);

	Repo repository_cheltuieli_familie;
	repository_cheltuieli_familie.adaugare(c1);
	repository_cheltuieli_familie.adaugare(c2);

	assert(repository_cheltuieli_familie.getSize() == 2);
	assert(repository_cheltuieli_familie.getAll()[0] == c1);
	assert(repository_cheltuieli_familie.getAll()[1] == c2);
	assert(repository_cheltuieli_familie.getBuget() == 9890);

	delete[] tip_1;
	delete[] tip_2;
}

void test_eliminate_by_day_interval();
void test_get_by_condition();
void test_prop_based_on_sublist();
void test_sort_by_cond();
void test_filter_by_cond();

void test_service_cheltuieli_familie() 
{
	test_eliminate_by_day_interval();
	test_get_by_condition();
	test_prop_based_on_sublist();
	test_sort_by_cond();
	test_filter_by_cond();

	char* tip_1 = new char[10];
	char* tip_2 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");

	Service service_cheltuieli_familie;
	service_cheltuieli_familie.adaugare_cheltuiala_zi(100, tip_1);
	service_cheltuieli_familie.adaugare_cheltuiala(11, 100, tip_2);

	int currentDay = service_cheltuieli_familie.getCurrentDay();

	assert(service_cheltuieli_familie.getAll()[0].getZi() == currentDay);
	assert(service_cheltuieli_familie.getAll()[1].getZi() == 11);
	assert(service_cheltuieli_familie.getAll()[0].getSumaBani()==100);
	assert(service_cheltuieli_familie.getAll()[1].getSumaBani() == 100);
	assert(strcmp(service_cheltuieli_familie.getAll()[0].getTip(), "haine") == 0);
	assert(strcmp(service_cheltuieli_familie.getAll()[1].getTip(), "mancare") == 0);

	service_cheltuieli_familie.stergere_cu_zi(currentDay);

	assert(service_cheltuieli_familie.getAll()[0].getZi() == 11);
	assert(strcmp(service_cheltuieli_familie.getAll()[0].getTip(), "mancare") == 0);

	delete[] tip_1;
	delete[] tip_2;
}


void test_eliminate_by_day_interval()
{
	char* tip_1 = new char[10];
	char* tip_2 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");

	Service service_cheltuieli_familie;
	service_cheltuieli_familie.adaugare_cheltuiala_zi(100, tip_1);
	service_cheltuieli_familie.adaugare_cheltuiala(11, 100, tip_1);
	service_cheltuieli_familie.adaugare_cheltuiala(12, 100, tip_2);
	service_cheltuieli_familie.adaugare_cheltuiala(13, 100, tip_2);
	service_cheltuieli_familie.adaugare_cheltuiala(14, 100, tip_2);
	service_cheltuieli_familie.adaugare_cheltuiala(40, 100, tip_2);
	service_cheltuieli_familie.stergere_interval(12,30);

	assert(service_cheltuieli_familie.getAll()[0].getZi() == 11);
	assert(service_cheltuieli_familie.getAll()[1].getZi() == 40);

	service_cheltuieli_familie.stergere_tip(tip_1);

	assert(service_cheltuieli_familie.getAll()[0].getZi() == 40);

	delete[] tip_1;
	delete[] tip_2;
}

void test_get_by_condition() 
{
	char* tip_1 = new char[10];
	char* tip_2 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");

	Service service_cheltuieli_familie;
	service_cheltuieli_familie.adaugare_cheltuiala_zi(100, tip_1);
	service_cheltuieli_familie.adaugare_cheltuiala(11, 150, tip_1);
	service_cheltuieli_familie.adaugare_cheltuiala(12, 200, tip_2);
	service_cheltuieli_familie.adaugare_cheltuiala(13, 250, tip_1);
	service_cheltuieli_familie.adaugare_cheltuiala(14, 100, tip_2);
	service_cheltuieli_familie.adaugare_cheltuiala(30, 100, tip_2);

	Cheltuieli rezultat[100];
	int resultlen = 0;

	service_cheltuieli_familie.getElemByType(tip_1, rezultat, resultlen);

	assert(resultlen == 3);
	assert(rezultat[1].getZi() == 11);
	assert(rezultat[2].getZi() == 13);

	service_cheltuieli_familie.getElemByCondAndType(120, tip_1, rezultat, resultlen);

	assert(resultlen == 2);
	assert(rezultat[0].getZi() == 11);
	assert(rezultat[1].getZi() == 13);

	service_cheltuieli_familie.getElemByCond2AndType(100, tip_2, rezultat, resultlen);

	assert(resultlen == 2);
	assert(rezultat[0].getZi() == 14);
	assert(rezultat[1].getZi() == 30);

	delete[] tip_1;
	delete[] tip_2;
}


void test_prop_based_on_sublist() 
{
	char* tip_1 = new char[10];
	char* tip_2 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");

	Service service_cheltuieli_familie;
	service_cheltuieli_familie.adaugare_cheltuiala_zi(100, tip_1);
	service_cheltuieli_familie.adaugare_cheltuiala(11, 150, tip_1);
	service_cheltuieli_familie.adaugare_cheltuiala(12, 200, tip_2);
	service_cheltuieli_familie.adaugare_cheltuiala(13, 250, tip_1);
	service_cheltuieli_familie.adaugare_cheltuiala(14, 100, tip_2);
	service_cheltuieli_familie.adaugare_cheltuiala(30, 100, tip_2);

	int sum = service_cheltuieli_familie.suma_elem_tip(tip_1);

	assert(sum == 500);

	int max_zi = service_cheltuieli_familie.max_zi_suma();

	assert(max_zi == 13);

	delete[] tip_1;
	delete[] tip_2;
}

void test_sort_by_cond()
{

	char* tip_1 = new char[10];
	char* tip_2 = new char[10];
	char* tip_3 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");
	strcpy_s(tip_3, strlen("internet") + 1, "internet");

	Service service_cheltuieli_familie;
	service_cheltuieli_familie.adaugare_cheltuiala(11, 150, tip_1);
	service_cheltuieli_familie.adaugare_cheltuiala(12, 200, tip_2);
	service_cheltuieli_familie.adaugare_cheltuiala(13, 250, tip_1);
	service_cheltuieli_familie.adaugare_cheltuiala(14, 100, tip_3);
	service_cheltuieli_familie.adaugare_cheltuiala(30, 120, tip_3);

	Cheltuieli rezultat[100];
	int resultlen;

	service_cheltuieli_familie.sortare_suma_desc(rezultat, resultlen);

	assert(resultlen == 5);
	assert(rezultat[0].getZi() == 13);
	assert(rezultat[1].getZi() == 12);
	assert(rezultat[4].getZi() == 14);

	service_cheltuieli_familie.sortare_suma_tip(tip_3, rezultat, resultlen);

	assert(resultlen == 2);
	assert(rezultat[0].getZi() == 14);
	assert(rezultat[0].getSumaBani() == 100);
	assert(rezultat[1].getZi() == 30);
	assert(rezultat[1].getSumaBani() == 120);

	delete[] tip_1;
	delete[] tip_2;
	delete[] tip_3;
}

void test_filter_by_cond() 
{
	char* tip_1 = new char[10];
	char* tip_2 = new char[10];
	char* tip_3 = new char[10];

	strcpy_s(tip_1, strlen("haine") + 1, "haine");
	strcpy_s(tip_2, strlen("mancare") + 1, "mancare");
	strcpy_s(tip_3, strlen("internet") + 1, "internet");

	Service service_cheltuieli_familie;
	service_cheltuieli_familie.adaugare_cheltuiala(11, 150, tip_1);
	service_cheltuieli_familie.adaugare_cheltuiala(12, 200, tip_2);
	service_cheltuieli_familie.adaugare_cheltuiala(13, 250, tip_3);
	service_cheltuieli_familie.adaugare_cheltuiala(14, 100, tip_3);
	service_cheltuieli_familie.adaugare_cheltuiala(30, 120, tip_2);
	service_cheltuieli_familie.filtrare_tip(tip_2);

	assert(service_cheltuieli_familie.getAll()[0].getZi() == 12);
	assert(service_cheltuieli_familie.getAll()[1].getZi() == 30);
	assert(service_cheltuieli_familie.getSizeRepo() == 2);

	service_cheltuieli_familie.filtrare_tip_cond(150, tip_2);

	assert(service_cheltuieli_familie.getAll()[0].getZi() == 30);
	assert(service_cheltuieli_familie.getAll()[0].getSumaBani() == 120);

	service_cheltuieli_familie.adaugare_cheltuiala(11, 140, tip_2);
	service_cheltuieli_familie.adaugare_cheltuiala(12, 150, tip_2);
	service_cheltuieli_familie.filtrare_tip_cond2(120, tip_2);

	assert(service_cheltuieli_familie.getAll()[0].getZi() == 30);
	assert(service_cheltuieli_familie.getAll()[0].getSumaBani() == 120);

	delete[] tip_1;
	delete[] tip_2;
	delete[] tip_3;

}


