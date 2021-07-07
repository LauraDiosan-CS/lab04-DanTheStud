#include <ctime>
#include "Service.h"

int Service::getCurrentDay() 
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	return ltm->tm_mday;
}


void Service::adaugare_cheltuiala_zi(int suma, char* tip) 
{
	int currentDay = getCurrentDay();
	Cheltuieli newCheltuiala(currentDay, suma, tip);
	this->repo_cheltuiala.adaugare(newCheltuiala);
}

void Service::adaugare_cheltuiala( int zi, int suma, char* tip) 
{
	Cheltuieli newCheltuiala(zi, suma, tip);
	this->repo_cheltuiala.adaugare(newCheltuiala);
}


Cheltuieli* Service::getAll() 
{
	return this->repo_cheltuiala.getAll();
}


void Service::stergere_cu_zi(int day)
{
	for (int i = 0; i < this->repo_cheltuiala.getSize(); i++) 
	{
		if (this->getAll()[i].getZi() == day) 
		{
			this->repo_cheltuiala.stergere(this->getAll()[i]);
			i--;
		}
	}
}


void Service::stergere_interval(int day1, int day2) 
{
	for (int i = 0; i < this->repo_cheltuiala.getSize(); i++) 
	{
		if (this->getAll()[i].getZi()>=day1 && this->getAll()[i].getZi() <= day2) 
		{
			this->repo_cheltuiala.stergere(this->getAll()[i]);
			i--;
		}
	}
}

void Service::stergere_tip(char* tip) 
{
	int i = 0;
	while (i < this->repo_cheltuiala.getSize()) 
	{
		if (strcmp(this->getAll()[i].getTip(), tip) == 0) 
		{
			this->repo_cheltuiala.stergere(this->getAll()[i]);
		}
		else
			i++;
	}
}

void Service::getElemByType(char* tip,Cheltuieli cheltuieli[],int &resultlen) 
{
	resultlen = 0;
	for (int i = 0; i < this->repo_cheltuiala.getSize(); i++) 
	{
		if (strcmp(this->getAll()[i].getTip(), tip) == 0) 
		{
			cheltuieli[resultlen++] = this->getAll()[i];
		}
	}

}

void Service::getElemByCondAndType(int nr, char* tip, Cheltuieli cheltuieli[], int& resultlen) 
{
	resultlen = 0;
	for (int i = 0; i < this->repo_cheltuiala.getSize(); i++) 
	{
		if (strcmp(this->getAll()[i].getTip(), tip) == 0 && this->getAll()[i].getSumaBani() > nr) 
		{
			cheltuieli[resultlen++] = this->getAll()[i];
		}
	}

}

void Service::getElemByCond2AndType(int nr, char* tip, Cheltuieli cheltuieli[], int& resultlen) 
{
	resultlen = 0;
	for (int i = 0; i < this->repo_cheltuiala.getSize(); i++) 
	{
		if (strcmp(this->getAll()[i].getTip(), tip) == 0 && this->getAll()[i].getSumaBani() == nr) 
		{
			cheltuieli[resultlen++] = this->getAll()[i];
		}
	}

}

int Service::suma_elem_tip(char* tip) 
{
	int sum = 0;
	for (int i = 0; i < this->repo_cheltuiala.getSize(); i++) 
	{
		if (strcmp(this->getAll()[i].getTip(), tip) == 0) 
		{
			sum += this->getAll()[i].getSumaBani();
		}
	}
	return sum;
}


int Service::max_zi_suma() 
{
	int v[32] = { 0 };
	int max = -1;
	int max_zi = -1;
	for (int i = 0; i < this->repo_cheltuiala.getSize(); i++) 
	{
		v[this->getAll()[i].getZi()] += this->getAll()[i].getSumaBani();
		if (v[this->getAll()[i].getZi()]>max) 
		{
			max = v[this->getAll()[i].getZi()];
			max_zi = this->getAll()[i].getZi();
		}
	}
	return max_zi;
}

void Service::sortare_suma_desc(Cheltuieli cheltuieli[], int& resultlen) 
{
	int done = 1;
	resultlen = 0;
	for (int i = 0; i < this->repo_cheltuiala.getSize(); i++)
	{
		cheltuieli[resultlen++] = this->getAll()[i];
	}
	while (done == 1) 
	{
		done = 0;
		for(int i=0;i<resultlen-1;i++)
		{
			if (cheltuieli[i].getSumaBani() < cheltuieli[i + 1].getSumaBani())
			{
				Cheltuieli aux;
				aux = cheltuieli[i];
				cheltuieli[i] = cheltuieli[i + 1];
				cheltuieli[i + 1] = aux;
				done = 1;
			}
		}
	}

}

void Service::sortare_suma_tip(char * tip,Cheltuieli cheltuieli[], int& resultlen) {

	int done = 1;
	resultlen = 0;
	for (int i = 0; i < this->repo_cheltuiala.getSize(); i++)
	{
		if (strcmp(this->getAll()[i].getTip(), tip) == 0)
		{
			cheltuieli[resultlen++] = this->getAll()[i];
		}
	}
	while (done == 1) 
	{
		done = 0;
		for (int i = 0; i < resultlen - 1; i++)
		{
			if (cheltuieli[i].getSumaBani() > cheltuieli[i + 1].getSumaBani())
			{
				Cheltuieli aux;
				aux = cheltuieli[i];
				cheltuieli[i] = cheltuieli[i + 1];
				cheltuieli[i + 1] = aux;
				done = 1;
			}
		}
	}
}

void Service::filtrare_tip(char* tip) 
{
	int i = 0;
	while (i < this->repo_cheltuiala.getSize()) 
	{
		if (strcmp(this->getAll()[i].getTip(), tip) != 0)
		{
			this->repo_cheltuiala.stergere(this->getAll()[i]);
			
		}
		else
			i++;
	}
}

int Service::getBuget() 
{
	return this->repo_cheltuiala.getBuget();
}

int Service::getSizeRepo() 
{
	return this->repo_cheltuiala.getSize();
}

void Service::filtrare_tip_cond2(int nr, char* tip) 
{
	int i = 0;
	while (i < this->repo_cheltuiala.getSize()) 
	{
		if (strcmp(this->getAll()[i].getTip(), tip) == 0 && this->getAll()[i].getSumaBani() != nr)
		{
			this->repo_cheltuiala.stergere(this->getAll()[i]);
		}
		else if (strcmp(this->getAll()[i].getTip(), tip) != 0)
		{
			this->repo_cheltuiala.stergere(this->getAll()[i]);
		}
		else
			i++;
	}
}

void Service::filtrare_tip_cond(int nr, char* tip) 
{
	int i = 0;
	while (i < this->repo_cheltuiala.getSize()) 
	{
		if (strcmp(this->getAll()[i].getTip(), tip) == 0 && this->getAll()[i].getSumaBani() >= nr)
		{
			this->repo_cheltuiala.stergere(this->getAll()[i]);
		}
		else if (strcmp(this->getAll()[i].getTip(), tip) != 0)
		{
			this->repo_cheltuiala.stergere(this->getAll()[i]);
		}
		else
			i++;

	}
}