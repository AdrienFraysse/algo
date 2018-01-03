struct element
{
	char code;
	size_t poids;
};

typedef struct element element;

class noeud
{
	private :
			element elem;
			Noeud * ABR_G;
			Noeud * ABR_D;
			Noeud * pere;
	public :
			Noeud(element elem);
			~Noeud();
			inline Noeud * g(){return ABR_G;}
			inline Noeud * d(){return ABR_D;}
			inline Noeud * noeud_parent(){return pere;}
			inline bool estExterne(){bool b=false; if(ABR_G==nullptr && ABR_D==nullptr) b=true; return b;}
			inline bool estInterne(){bool b=false; if(ABR_G!=nullptr || ABR_D!=nullptr) b=true; return b;}
	
};

inline bool est_Vide(Noeud *n){bool b=false; if(n==nullptr)b=true; return b;}