#include "IteratorColectie.h"
#include "Colectie.h"
#include <iostream>

IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	cp = c.dim();
	poz = 0;
	contor_frecv = 0;
}

TElem IteratorColectie::element() const{
	return col.colectie[poz].elem;
}

bool IteratorColectie::valid() const {
	return poz < col.n;
}

void IteratorColectie::urmator() {
	if (contor_frecv == 0)
	{
		poz++;
		if (valid())
			contor_frecv = col.colectie[poz].frecventa;
		else
			contor_frecv = 0;
	}
	else
	{
		contor_frecv--;
	}
}

void IteratorColectie::prim() {
	poz = 0;
	contor_frecv = col.colectie[0].frecventa;
}
