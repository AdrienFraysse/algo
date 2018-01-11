#include <iostream>
#include "noeud.hpp"

using namespace std;

Noeud::Noeud()
	:elem(), ABR_G(nullptr), ABR_D(nullptr), pere(nullptr)
	{}

Noeud::Noeud(element _elem)
	: elem(_elem), ABR_G(nullptr), ABR_D(nullptr), pere(nullptr)
	{}
	
Noeud::~Noeud()
{
	delete ABR_G;
	delete ABR_D; 
	delete pere;
}

Noeud * creer_noeud(size_t p, char c)
{
	Noeud * noeud = new Noeud;
	noeud->setelemc(c);
	noeud->setelemp(p);
	noeud->setABR_G(nullptr);
	noeud->setABR_D(nullptr);
	noeud->set_noeud_parent(nullptr);
	return noeud;
}

