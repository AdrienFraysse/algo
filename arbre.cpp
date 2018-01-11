#include <iostream>
#include "arbre.hpp"

using namespace std;

Arbre::Arbre()
	: racine(nullptr)
{
	
}

Arbre::~Arbre(){}

void affiche_croissant(Noeud * noeud)
{
	if(!est_Vide(noeud->g()))
		affiche_croissant(noeud->g());
	cout << noeud->getelemp() << endl;
	if(!est_Vide(noeud->d()))
		affiche_croissant(noeud->d());
}

Noeud * trouve_noeud (size_t _valeur, Noeud*noeud)
{
	Noeud * position  = new Noeud();
	position = nullptr;
	
	if (noeud->getelemp() == _valeur)
	{
		position = noeud;
		return position;
	}
	if(noeud->getelemp()>_valeur)
	{
		if(!est_Vide(noeud->g()))
		{
			return trouve_noeud(_valeur, noeud->g());
		}
		else if(!est_Vide(noeud->d()))
		{
			return trouve_noeud(_valeur, noeud->d());
		}
	}
	return position;
}

string  trouve_chemin (size_t _valeur, Noeud*noeud, string chemin)
{
	char num;

	if(noeud->getelemp()>_valeur)
	{
		if(!est_Vide(noeud->g()))
		{
			num = 0;
			chemin = chemin + num;
			return trouve_chemin(_valeur, noeud->g(), chemin);
		}
		else if(!est_Vide(noeud->d()))
		{
			num = 1;
			chemin = chemin + num; 
			return trouve_chemin(_valeur, noeud->d(), chemin);
		}
	}
	return chemin;
}

 void supprime_feuille(int _valeur, Noeud *n)
 {
	 Noeud *noeud;
	 Noeud *pere;
	 
	 noeud = trouve_noeud (_valeur, n);
	 if(noeud->estExterne())
		 pere=noeud->noeud_parent();
	 if(noeud->getelemp() > pere->getelemp())
		 pere->setABR_G(nullptr);
	 else if(noeud->getelemp() < pere->getelemp())
		 pere->setABR_D(nullptr);
 }
 
/*void insertion(size_t elem)
{
  if(elem != getelement())
  {
    if(elem<getelement())
    {
      if(fils_g == nullptr)
        fils_g = new noeud(this, elem);
      else
        fils_g->insertion(elem);
    }
    else
    {
      if(fils_d == nullptr)
        fils_d = new noeud(this, elem);
      else
        fils_d->insertion(elem);
    }
  }
}*/

Noeud * addition_noeud(Noeud * n1, Noeud *n2)
{	
	Noeud * noeud = new Noeud();
	noeud->setelemp(n1->getelemp()+n2->getelemp());
	noeud->setABR_G(n1);
	noeud->setABR_D(n2);
	n1->set_noeud_parent(noeud);
	n2->set_noeud_parent(noeud);
	return noeud;
}
 
 