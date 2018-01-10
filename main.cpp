#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<char> charVector;
typedef map<char, size_t> MyMap;


void ajouter_lettre(ifstream &is, charVector & vector)
{
	while(is.good)
	{
		//Met tous les caractères dans le vecteur.
		char c;
		is.get(c);
		vector.pushback(c);
	}	
}

void compter_lettrer(Mymap &map, charVector &vector)
{
		size_t taille = vector.size();
		//Met tous les caractères du vecteur dans la map et compte le nombre d'occurence.
		for(size_t i=0; i<taille ; ++i)
		{
			map[vector[i]]+=1;
		}
}

int main()
{
	charVector cVector;
	MyMap Map;
	ifstream is1("autonomy.txt");
	ifstream is2("swann10.txt");
	if(is1 & is2)
	{
		//Stock tous les caractères des différents fichiers dans un vecteur
		ajouter_lettre(is1, cVector);
		ajouter_lettre(is2, cVector);
		//Ajoute tous les caractères dans une map (trié par ordre croissant) pour obtenir le caractère et son nombre d'occurence
		compter_lettre(Map, cVector);
		
	}
	else
		//Si impossible de lire un des fichiers d'entrée
		cout << "Erreur de lecture " << endl;
	return 0;
}