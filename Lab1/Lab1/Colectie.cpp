#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {
	return e1 <= e2;
}

Colectie::Colectie() {
	this->n = 0;
	this->cp = 10;
	colectie = new Pereche[cp];
}


void Colectie::redim()
{
	Pereche* colectieNou = new Pereche[2 * this->cp];
	cp *= 2;

	for (int i = 0; i < n; i++)
		colectieNou[i] = colectie[i];

	delete[] colectie;

	colectie = colectieNou;
}

void Colectie::adauga(TElem e) {
	if (n == cp)
	{
		redim();
	}
	/*
	for (int i = 0; i < n; i++) 
		if (colectie[i].elem == e)
		{
			colectie[i].frecventa++;
			return;
		}
	
	*/
	int st = 0, dr = n - 1;


	while (st <= dr)
	{
		int m = (st + dr) / 2;

		if (colectie[m].elem == e)
		{
			colectie[m].frecventa++;
			return;
		}

		if (rel(colectie[m].elem, e))
			st = m + 1;
		else
			dr = m - 1;
	}
	

	int i;
	for (i = n - 1; i >= 0 && rel(e, colectie[i].elem); i--) {
		colectie[i + 1] = colectie[i];
	}
	i++;
	Pereche p = {e, 1};
	colectie[i] = p;
	n++;
}

bool Colectie::sterge(TElem e) {
	int st = 0, dr = n - 1;

	while (st <= dr)
	{
		int m = (st + dr) / 2;

		if (colectie[m].elem == e)
		{
			colectie[m].frecventa--;
			if (colectie[m].frecventa == 0)
			{
				for (int j = m; j < n - 1; j++)
				{
					colectie[j] = colectie[j + 1];
				}
				n--;
			}

			return true;
		}

		if (rel(colectie[m].elem, e))
			st = m + 1;
		else
			dr = m - 1;
	}
	
	return false;
}


bool Colectie::cauta(TElem elem) const {
	/*for (int i = 0; i < n; i++)
		if (colectie[i].elem == elem)
			return true;
	*/
	
	int st = 0, dr = n - 1;
	
	while (st <= dr)
	{
		int m = (st + dr) / 2;

		if (colectie[m].elem == elem)
			return true;

		if (rel(colectie[m].elem, elem))
			st = m + 1;
		else
			dr = m - 1;
	}
	return false;
}


int Colectie::nrAparitii(TElem elem) const {
	/*
	for (int i = 0; i < n; i++)
		if (colectie[i].elem == elem)
			return colectie[i].frecventa;
	*/


	int st = 0, dr = n - 1;

	while (st <= dr)
	{
		int m = (st + dr) / 2;

		if (colectie[m].elem == elem)
			return colectie[m].frecventa;

		if (rel(colectie[m].elem, elem))
			st = m + 1;
		else
			dr = m - 1;
	}

	return 0;
}



int Colectie::dim() const {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count += colectie[i].frecventa;
	}
	
	return count;
}


bool Colectie::vida() const {
	return n == 0;
}


IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	delete[] colectie;
}
