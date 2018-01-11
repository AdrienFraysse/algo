#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "arbre.hpp"


using namespace std;

typedef vector<char> charVector;
typedef map<char, size_t> tempMap;
typedef map<size_t, char> invMap;


void ajouter_lettre(ifstream &is, charVector & vector)
{
	while(is.good())
	{
		//Met tous les caractères dans le vecteur.
		char c;
		is.get(c);
		vector.push_back(c);
	}	
}

void compter_lettre(tempMap &map, charVector &vector)
{
		size_t taille = vector.size();
		//Met tous les caractères du vecteur dans la map et compte le nombre d'occurence.
		for(size_t i=0; i<taille ; ++i)
			map[vector[i]]+=1;
}

void tri_map(tempMap &tmap, invMap &map)
{
	size_t taille = tmap.size();
	for(size_t i=0; i<taille ; ++i)
		map.insert(pair<size_t, char>(tmap.at(i), tmap[i]));
}

int main()
{
	charVector cVector;
	ifstream is1("autonomy.txt");
	ifstream is2("swann10.txt");
	if(is1 && is2)
	{
		tempMap tMap;
		invMap Map;
		
		//Etape 1 :
		
		//Stock tous les caractères des différents fichiers dans un vecteur
		ajouter_lettre(is1, cVector);
		ajouter_lettre(is2, cVector);
		//Ajoute tous les caractères dans une map (trié par ordre croissant) pour obtenir le caractère et son nombre d'occurence
		compter_lettre(tMap, cVector);
		tri_map(tMap, Map);
		
		if(Map.size()!=0)
		{
			//Etape 2 :
			Noeud * tab[Map.size()];
			for(size_t i=0; i<Map.size();++i)
				tab[i]=creer_noeud(Map[i], Map.at(i));
			
			//Etape 3 à n :
			do{
				Noeud * somme_noeud = new Noeud;
				somme_noeud=addition_noeud(tab[0], tab[1]);
				Noeud *temp[Map.size()];
				//Copie notre tableau de base dans un tableau temporaire
				for(size_t i=0; i<Map.size();++i)
					temp[i]=tab[i];
				//Vide le tableau pour pouvoir y reécrire dedans
				for(size_t i=0; i<Map.size();++i)
					delete tab[i];
				for(size_t i=2; i<Map.size();++i)
				{
					if(somme_noeud->getelemp() < temp[i]->getelemp())	
						tab[i-2]=temp[i];
					else
						tab[i-2]=somme_noeud;
				}
			 }while(tab[1]!='\0');
		}
	}
	else
		//Si impossible de lire un des fichiers d'entrée
		cout << "Erreur de lecture " << endl;
	return 0;
}