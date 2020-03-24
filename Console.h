#pragma once
#include "Service.h"

class Console 
{
private:
	Service service_cheltuieli;
public:
	void meniu();
	int console();
	int read_int();
	char read_op();
	char* read_p_char();
	void show_cheltuieli_familie();
	void adaugare_fara_zi();
	void adaugare_cu_zi();
	void sterge_cheltuiala();
	void sterge_cheltuiala_intre_zile();
	void sterge_dupa_tip();
	void show_cheltuiala_by_type();
	void show_cheltuiala_by_type_and_cond();
	void show_cheltuiala_by_type_and_cond_eq();
	void show_by_len(int n, Cheltuieli cheltuieli[]);
	void max_suma_tip();
	void max_zi();
	void suma_ord_desc();
	void suma_tip_cresc();
	void filtrare_tip();
	void filtrare_tip_cond();
	void filtrare_tip_cond2();
};