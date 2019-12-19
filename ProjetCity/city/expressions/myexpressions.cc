#include "myexpressions.hh"


/*ASTNODE::ASTNODE(ExpressionPtr x):
_x(x){}

double ASTNODE::calculer(const Contexte& contexte){
	return 0; 
	/*
		This returns 	n o t h i n g
}
	*/

RAYON::RAYON(ExpressionPtr rayon):
_rayon(rayon){}

double RAYON::calculer(const Contexte& contexte){
	if(_rayon) return _rayon->calculer(contexte);
	else return 5;
}

Construire::Construire(ExpressionPtr x,std::vector<ExpressionPtr> y):
_rayon(x),_statements(y){}

double Construire::calculer(const Contexte& contexte){
	double rayon=_rayon->calculer(contexte);
	double lotCount=rayon*6; //hexagonal map
	//Initialise the Graph to the right size
	contexte.getCity()->Init(lotCount);

	//Execute instructions
	for(auto sts : _statements) sts->calculer();

	return 0; //success?
}


COORD::COORD(ExpressionPtr x,ExpressionPtr y,ExpressionPtr z):
_x(x),_y(y),_z(z){}

double COORD::calculer(const Contexte& contexte){
	for(double i=0; i<contexte.Houses().size();i++)
		if(contexte.Houses()[i].at(_x,_y,_z))
			return i;
	//returns the index of the house, or -1
	return -1; 
}

double COORD::distance(const COORD & o) {
	return HexDistance(
		x(contexte),y(contexte),z(contexte),
		(o->x(contexte)),(o->y(contexte)),(o->z(contexte))
		);/
}

NODE::NODE(ExpressionPtr iMaison):
_iMaison(iMaison){}

double NODE::calculer(const Contexte& contexte){
	return iMaison->calculer(contexte); 
}

Maison::Maison(std::string nom):
_nom(nom){}

double Maison::calculer(const Contexte& contexte){
	return 0; 
	/*
		Makes a house class in Context,
		add a vertex in the graph

		This returns 	1 if the house was made
						0 if not
	*/
}

IDMaison::IDMaison(std::string iMaison):
_iMaison(iMaison){}

double IDMaison::calculer(const Contexte& contexte){
	for(double i=0; i<contexte.Houses().size();i++)
		if(contexte.Houses()[i].id(iMaison))
			return i;
	//returns the index of the house, or -1
	return -1;
}

Route::Route(ExpressionPtr x, ExpressionPtr y):
_src(x),_dst(y){}

double Route::calculer(const Contexte& contexte){
	double src = _src->calculer(contexte);
	double dst = _dst->calculer(contexte);

	double distance=dst-src;// This needs to be corrected

	contexte.Graph()->Arc(src,dst,distance);

	return distance; 
	/*
		Adds an arc to the graph in Context

		This returns 	distance
	*/
}


Tourner::Tourner(ExpressionPtr x, double y):
_iMaison(x),_dir(y){}

double Tourner::calculer(const Contexte& contexte){
	double i=_iMaison->calculer();
	contexte.Houses()[i].orientation += 90*_dir;
	contexte.Houses()[i].orient();

	return contexte.Houses()[i].orientation; //updated angle
}

Orienter::Orienter(ExpressionPtr x, ExpressionPtr y):
_iMaison(x),_deg(y){}

double Orienter::calculer(const Contexte& contexte){
	double i=_iMaison->calculer();
	contexte.Houses()[i].orient(_deg->calculer());	
	return contexte.Houses()[i].orientation; //updated angle
}


Deplacer::Deplacer(ExpressionPtr x, ExpressionPtr y):
_iMaison(x),_coord(y){}

double Deplacer::calculer(const Contexte& contexte){
	if(_coord->calculer(contexte)!=-1) return 0;

	double i=_iMaison->calculer(contexte);
	contexte.Houses()[i].x=_coord->x();
	contexte.Houses()[i].y=_coord->y();
	contexte.Houses()[i].z=_coord->z();
	//Update Roads

	/*
		Moves a house in Context
		just the coords

		This returns 	success ?
	*/
}

Detruire::Detruire(ExpressionPtr x):
_src(x),_dst(), _maison(1){}
Detruire::Detruire(ExpressionPtr x, ExpressionPtr y):
_src(x),_dst(y), _maison(0){}

double Detruire::calculer(const Contexte& contexte){
	double src=_src->calculer();
	if(_maison) {/* 
	remove house from vector
	remove roads to and from
	*/}
	else {
		double dst=_dst->calculer();
		contexte.City().RemoveArc(src,dst);
	}
	return 0;
	/*
		If _maison 		destroys House and roads from it (in context and graph)
		else 			removes arc

		This returns 	success ?
	*/
}

Position::Position(ExpressionPtr iMaison):
_iMaison(iMaison){}

double Position::calculer(const Contexte& contexte){
	double i=_iMaison->calculer(contexte);

	std::cout << "(" 
	<< contexte.Houses()[i].x <<","
	<< contexte.Houses()[i].y <<","
	<< contexte.Houses()[i].z <<")";

	return 0; 
	/*
		cout position?
		This returns 	to hell from whence it came
	*/
}

Orientation::Orientation(ExpressionPtr iMaison):
_iMaison(iMaison){}

double Orientation::calculer(const Contexte& contexte){
	double i=_iMaison->calculer(contexte);

	std::cout 
	<< contexte.Houses()[i].orientation;

	return 0;
}

Voisinage::Voisinage(ExpressionPtr iMaison):
_iMaison(iMaison){}

double Voisinage::calculer(const Contexte& contexte){
	return 0; 
	/*
		cout remy sans amis?

		This s'appel returns
	*/
}

Affect::Affect(ExpressionPtr x, ExpressionPtr y):
_idvar(x),_exp(y){}

double Affect::calculer(const Contexte& contexte){
	return 0; 
	/*
		i=exp copy the TP3 exo2 code

		This returns 	success ? //Context throws an error with unknown var.. so if there's another way for it to mess up, we can return it here
	*/
}

Coloriser::Coloriser(ExpressionPtr iMaison,ExpressionPtr color):
_iMaison(iMaison),_color(color){}

double Coloriser::calculer(const Contexte& contexte){
	return 0; 
	/*
		Colors hours in context

		This return the wavelength of light associated for the color.. so you can change the color by step while it's below a threshold
	*/
}

Couleur::Couleur(ExpressionPtr iMaison):
_iMaison(iMaison){}

double Couleur::calculer(const Contexte& contexte){
	double i=_iMaison->calculer(contexte);

	std::cout << "(" 
	<< contexte.Houses()[i].r <<","
	<< contexte.Houses()[i].g <<","
	<< contexte.Houses()[i].b <<")";

	return 0; 
	/*
		cout couleur?
		This return f(r,g,b)
	*/
}

Voisin::Voisin(ExpressionPtr iMaison,ExpressionPtr exp):
_iMaison(iMaison),_exp(exp){}

double Voisin::calculer(const Contexte& contexte){
	return 0; 
	/*
		Makes house in random location in proximity

		This return 	success ?
	*/
}

hexRGB::hexRGB(const std::string & hexcode):
	_x( (double)std::strtoul(hexcode.substr(1,2),0,16)),
	_y( (double)std::strtoul(hexcode.substr(3,2),0,16)),
	_z( (double)std::strtoul(hexcode.substr(5,2),0,16)){}

double hexRGB::calculer(const Contexte& contexte){
	return 0; 
	/*
		You mainly use getters for this class
		This returns 	the wavelength of light
	*/
}

Si::Si(ExpressionPtr exp,std::vector<ExpressionPtr> sts,std::vector<ExpressionPtr> else_sts): 
_exp(exp),_statements(sts),_else_sts(else_sts){}

double Si::calculer(const Contexte& contexte){
	double condition = exp->calculer(contexte);
	if (condition) 		
		for(auto sts : _statments)
			sts.calculer(contexte);
	else
		for(auto sts : _else_sts)
			sts.calculer(contexte);
	
	return condition;
}

TantQue::TantQue(ExpressionPtr exp,std::vector<ExpressionPtr> sts,std::vector<ExpressionPtr> else_sts): 
_exp(exp),_statements(sts){}

double TantQue::calculer(const Contexte& contexte){
	double i=0;
	while (exp->calculer(contexte)){
		i++;
		for(auto sts : _statments)
			sts.calculer(contexte);
	}
	return i; 		//iterations
}

Repeter::Repeter(ExpressionPtr exp,std::vector<ExpressionPtr> sts,std::vector<ExpressionPtr> else_sts): 
_exp(exp),_statements(sts){}

double Repeter::calculer(const Contexte& contexte){
	double i=exp->calculer(contexte);
	while (i--)
		for(auto sts : _statments) 
			sts.calculer(contexte);

	return i;		//iterations restantes
}//J'aurrais bien aime' moins me repeter...