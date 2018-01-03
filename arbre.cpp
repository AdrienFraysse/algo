#include <iostream>
#include "arbre.hpp"

using namespace std;

Arbre::Arbre(Noeud * racine)
	
{
	
}

void affiche_croissant(Noeud * noeud)
{
	if(!est_Vide(g(noeud)))
		affiche_croissant(g(noeud));
	cout << noeud->element-> valeur << endl;
	if(!est_Vide(d(noeud)))
		affiche_croissant(d(noeud));
}

Noeud trouve_noeud (int valeur, Noeud*noeud)
{
	position * Noeud =NULL;
	
	if (noeud->element->valeur = valeur)
	{
		position = noeud;
		return position;
	}
	if(noeud->element->valeur>valeur)
	{
		if(!est_vide g(noeud))
		{
			return trouve_noeud(int g(noeud));
		}
		else if(!est vide d(noeud))
		{
			return trouve_noeud(int d(noeud));
		}
	}
}
 /*void supprime_feuille(int valeur, Noeud*noeud)
 {
	 Noeud*noeud;
	 pere*noeud;
	 
	 noeud = trouve_noeud (_valeur, noeud);
	 
 }*/
 
 void noeud::insertion(size_t elem)
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
}
 
 
 