#include <iostream>
#include "noeud.hpp"

using namespace std;

Noeud::Noeud(element _elem)
	: elem(_elem), ABR_G(nullptr), ABR_D(nullptr), pere(nullptr)
	{}
	
Noeud::Noeud(Noeud * n1, Noeud * n2)
	: elem.code(), elem.poids(n1->elem.poids+n2->elem.poids), ABR_G(n1), ABR_D(n2)
	{}
	
~Noeud()
{}