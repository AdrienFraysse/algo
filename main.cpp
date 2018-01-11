#include <iostream>
#include <fstream>
#include <vector>
#include <map>

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
	ofstream os("test.txt");
	if(is1 && is2)
	{
			tempMap tMap;
			invMap Map;
		//Stock tous les caractères des différents fichiers dans un vecteur
		ajouter_lettre(is1, cVector);
		ajouter_lettre(is2, cVector);
		//Ajoute tous les caractères dans une map (trié par ordre croissant) pour obtenir le caractère et son nombre d'occurence
		compter_lettre(tMap, cVector);
		tri_map(tMap, Map);
		for(invMap::iterator it = Map.begin(); it!=Map.end(); ++it )
			os << it->first << " : " << it->second << endl;
		
	}
		
		
	
	else
		//Si impossible de lire un des fichiers d'entrée
		cout << "Erreur de lecture " << endl;
	return 0;
}