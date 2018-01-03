 #include <iostream>
 #include "noeud.hpp"

//getopt -> option
//graphig -> visualiser arbre
//langage dot
// yuml.me
 
 using namespace std; 
 
 Class Arbre {
	private:
		Noeud * racine;
	public : 
		Arbre();
		~Arbre();
		Noeud racine(Arbre Abr);
		bool estRacine(Noeud * noeud);
		trouve_mot(string mot);
		void affiche_croissant(Noeud * noeud);
		Noeud trouve_noeud(size_t val, Noeud * noeud);
		void supprime_feuille(size_t val, Noeud * noeud);
		void supprime_noeud_int(size_t val, Noeud * noeud);
		
	 private :
	 
	 Noeud recherche(string mot, Noeud * pere);
	 
 };
 