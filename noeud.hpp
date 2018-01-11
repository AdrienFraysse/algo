#include <iostream>

struct element
{
	char code;
	size_t poids;
};

typedef struct element element;

class Noeud
{
	private :
			element elem;
			Noeud * ABR_G;
			Noeud * ABR_D;
			Noeud * pere;
	public :
			Noeud();
			Noeud(element _elem);
			Noeud(Noeud * n1, Noeud * n2);
			~Noeud();
			inline Noeud * g(){return ABR_G;}
			inline Noeud * d(){return ABR_D;}
			inline Noeud * noeud_parent(){return pere;}
			inline void set_noeud_parent(Noeud * p){pere=p;}
			inline bool estExterne(){bool b=false; if(ABR_G==nullptr && ABR_D==nullptr) b=true; return b;}
			inline bool estInterne(){bool b=false; if(ABR_G!=nullptr || ABR_D!=nullptr) b=true; return b;}
			inline element getelem(){return elem;}
			inline size_t getelemp(){return elem.poids;}
			inline void setelemp(size_t p){elem.poids=p;}
			inline char getelemc(){return elem.code;}
			inline void setelemc(char c){elem.code=c;}
			inline void setABR_G(Noeud * n){ABR_G=n;}
			inline void setABR_D(Noeud * n){ABR_D=n;}

};
Noeud * creer_noeud(char c, size_t p);
inline bool est_Vide(Noeud *n){bool b=false; if(n==nullptr)b=true; return b;}