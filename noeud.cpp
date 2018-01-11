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

Noeud * creer_noeud(char c, size_t p)
{
	Noeud * noeud = new Noeud;
	noeud->setelemc(c);
	noeud->setelemp(p);
	noeud->setABR_G(nullptr);
	noeud->setABR_D(nullptr);
	noeud->set_noeud_parent(nullptr);
	return noeud;
}

// Noeud operator+(Noeud *n){
	// Noeud noeud = new Noeud()
	// noeud->elem_cod=" ";
	// noeud->elem.poids=this->elem.poids+n->elem.poids;
	// noeud->ABR_G=this;
	// noeud->ABR_D=n;
	// this->pere=n;
	// n->pere=noeud;
	// return noeud;
// }

// Noeud operator=(Noeud *n){
	// this->elem=n->elem;
	// this->ABR_G=n->ABR_G;
	// this->ABR_D=n->ABR_D;
	// this->pere=n->pere;
	// return this;
// }

