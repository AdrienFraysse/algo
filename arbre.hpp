 #include <iostream>
 #include "noeud.hpp"

//getopt -> option
//graphig -> visualiser arbre
//langage dot
// yuml.me
 
 using namespace std; 
 
 class Arbre {
	private:
		Noeud * racine;
	public : 
		Arbre();
		~Arbre();
		inline void setracine(Noeud *n){racine=n;}
		inline Noeud * getracine(){return racine;}
		bool estRacine(Noeud * noeud);
		Noeud * trouve_mot(string mot);
		void affiche_croissant(Noeud * noeud);
		Noeud * trouve_noeud(char val, Noeud * noeud);
		void supprime_feuille(size_t val, Noeud * noeud);
		
		
		
	 private :
	 
	 Noeud recherche(string mot, Noeud * pere);
	 
 };
Noeud * addition_noeud(Noeud * n1, Noeud * n2);
string  trouve_chemin (char _valeur, Noeud *noeud, string chemin);