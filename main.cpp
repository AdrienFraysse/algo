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
		char c;
		is.get(c);
		vector.pushback(c);
	}	
}

void compter_lettrer(Mymap &map, charVector &vector)
{
		size_t taille = vector.size();
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
		ajouter_lettre(is1, cVector);
		ajouter_lettre(is2, cVector);
		
		compter_lettre(Map, cVector);
	}
	else
		cout << "Erreur de lecture " << endl;
	return 0;
}