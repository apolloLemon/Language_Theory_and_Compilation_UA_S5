#include "myexpressions.hh"
#include "variable.hh"
#include "contexte.hh"

#include <iostream>
#define COUT(x) std::cout << x <<std::endl

double HexDistance(double x1,double y1,double z1,double x2,double y2,double z2) {
    return (
        x1-x2
    +   y1-y2
    +   z1-z2
        )/2;
}
	/*
ASTNODE::ASTNODE(ExpressionPtr x):
_x(x){}

double ASTNODE::calculer(Contexte& contexte){
	return 0; 
		This returns 	n o t h i n g
}
	*/

RAYON::RAYON(ExpressionPtr rayon):
_rayon(rayon){COUT("Rayon::");}
//Returns the radius of the city
double RAYON::calculer(Contexte& contexte){
	COUT("Rayon::calculer");
	if(_rayon) return _rayon->calculer(contexte);
	else return 5;
} //


Construire::Construire(ExpressionPtr x,std::vector<ExpressionPtr> y):
_rayon(x),_statements(y){COUT("Construire::");}
//Inits Graph and launches instructions
double Construire::calculer(Contexte& contexte){
	COUT("Construire::calculer");
	contexte.Citinit(_rayon->calculer(contexte)); //Initialise the Graph to the right size
	for(auto sts : _statements) sts->calculer(contexte); //Execute instructions
	return contexte.City().VertexCount(); //size of graph
}


COORD::COORD(ExpressionPtr x,ExpressionPtr y,ExpressionPtr z):
_x(x),_y(y),_z(z){COUT("COORD::");}
//returns house index or -1
double COORD::calculer(Contexte& contexte){
	COUT("COORD::calculer");
	return contexte.Occupied( x(contexte),y(contexte),z(contexte) ); //will throw exception if illegal coord is attempted
}
//returns distance between this and arg(other)
double COORD::distance(const COORD & o,Contexte& contexte) const {
	COUT("COORD::distance");
	return HexDistance(
		x(contexte),y(contexte),z(contexte),
		(o.x(contexte)),(o.y(contexte)),(o.z(contexte))
		);
}

NODE::NODE(ExpressionPtr iMaison):
_iMaison(iMaison){COUT("NODE::");}
//returns house index
double NODE::calculer(Contexte& contexte){
	COUT("NODE::calculer");
	return _iMaison->calculer(contexte); 
}

Maison::Maison(const std::string& nom):
_nom(nom){COUT("Maison::");}
//Creates a house node
double Maison::calculer(Contexte& contexte){
	COUT("Maison::calculer");
	double vc=contexte.City().VertexCount();
	House h; h.identifier=_nom;



	if(vc<=contexte.Houses().size()) return 0; //are there spaces left?
	if(!_coord) {
		auto chooseFrom = contexte.UnOccupied();
		int choice = chooseFrom[rand()%chooseFrom.size()]; // YAY needed optimisation
		auto chosen = contexte.GraphCoords()[choice];

		h.pos = chosen.first;
		chosen.second = -1;
	}
	else {
		if(_coord->calculer(contexte)!=-1) return 0; //will throw exception if illegal coord is attempted
		h.pos.x=_coord->x(contexte);
		h.pos.y=_coord->y(contexte);
		h.pos.z=_coord->z(contexte);
		for(auto & i : contexte.GraphCoords())
			if(i.first == h.pos)
				i.second = -1;
	}

	contexte.Houses().push_back(h);
	return 1;
	/*
		This returns 	1 if the house was made
						0 if not
	*/
}

IDMaison::IDMaison(const std::string& nom):
_nom(nom){COUT("IDMaison::");}

double IDMaison::calculer(Contexte& contexte){
	COUT("IDMaison::calculer");
	for(double i=0; i<contexte.Houses().size();i++)
		if(contexte.Houses()[i].id(_nom))
			return i;
	//returns the index of the house, or -1
	return -1;
}

Route::Route(ExpressionPtr x, ExpressionPtr y):
_src(x),_dst(y){COUT("Route::");}

double Route::calculer(Contexte& contexte){
	COUT("Route::calculer");
	double src = _src->calculer(contexte);
	double dst = _dst->calculer(contexte);

	double distance=contexte.Houses()[src].pos.distance(contexte.Houses()[dst].pos);// This needs to be corrected

	contexte.City().Arc(src,dst,distance);

	return distance; 
}


Tourner::Tourner(ExpressionPtr x, double y):
_iMaison(x),_dir(y){COUT("Tourner::");}

double Tourner::calculer(Contexte& contexte){
	COUT("Tourner::calculer");
	double i=_iMaison->calculer(contexte);
	contexte.Houses()[i].orientation += 90*_dir;
	contexte.Houses()[i].orient();

	return contexte.Houses()[i].orientation; //updated angle
}

Orienter::Orienter(ExpressionPtr x, ExpressionPtr y):
_iMaison(x),_deg(y){COUT("Orienter::");}

double Orienter::calculer(Contexte& contexte){
	COUT("Orienter::calculer");
	double i=_iMaison->calculer(contexte);
	contexte.Houses()[i].orient(_deg->calculer(contexte));	
	return contexte.Houses()[i].orientation; //updated angle
}


Deplacer::Deplacer(ExpressionPtr x, ExpressionPtr y):
_iMaison(x),_coord(std::dynamic_pointer_cast<COORD>(y)){COUT("Deplacer::");}

double Deplacer::calculer(Contexte& contexte){
	COUT("Deplacer::calculer");
	if(_coord->calculer(contexte)!=-1) return 0;

	double i=_iMaison->calculer(contexte);
	coord old = contexte.Houses()[i].pos;
	coord newpos = {_coord->x(contexte),_coord->y(contexte),_coord->z(contexte)};
	
	contexte.Houses()[i].pos=newpos;
	for(auto & i : contexte.GraphCoords())
		if(i.first==old)
			i.second=-1;
	//Update Road Distances
	contexte.UpdateRoads(i);


	/*
		Moves a house in Context
		just the coords

		This returns 	success ?
	*/
	return 0;
}

Detruire::Detruire(ExpressionPtr x):
_src(x),_dst(), _maison(1){COUT("Detruire::");}
Detruire::Detruire(ExpressionPtr x, ExpressionPtr y):
_src(x),_dst(y), _maison(0){COUT("Detruire::(route)");}

double Detruire::calculer(Contexte& contexte){
	COUT("Detruire::calculer");
	double src=_src->calculer(contexte);
	if(_maison) {/* 
	remove house from vector
	remove roads to and from
	*/
		coord pos = contexte.Houses()[src].pos;
		for(auto & i : contexte.GraphCoords())
			if(i.first==pos)
				i.second=-1;
		contexte.Houses().erase(contexte.Houses().begin()+src);
		contexte.City().RemoveNode(src); //I don't like this, my data structure isn't thought out well enough..    ...ok turns out I might be more pessimistic than usual
	}
	else {
		double dst=_dst->calculer(contexte);
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
_iMaison(iMaison){COUT("Position::");}

double Position::calculer(Contexte& contexte){
	COUT("Position::calculer");
	double i=_iMaison->calculer(contexte);

	std::cout << "(" 
	<< contexte.Houses()[i].pos.x <<","
	<< contexte.Houses()[i].pos.y <<","
	<< contexte.Houses()[i].pos.z <<")";

	return 0; 
	/*
		cout position?
		This returns 	to hell from whence it came
	*/
}

Orientation::Orientation(ExpressionPtr iMaison):
_iMaison(iMaison){COUT("Orientation::");}

double Orientation::calculer(Contexte& contexte){
	COUT("Orientation::calculer");
	double i=_iMaison->calculer(contexte);

	std::cout 
	<< contexte.Houses()[i].orientation;

	return 0;
}

Voisinage::Voisinage(ExpressionPtr iMaison):
_iMaison(iMaison){COUT("Voisinage::");}

double Voisinage::calculer(Contexte& contexte){
	COUT("Voisinage::calculer");
	return 0; 
	/*
		cout remy sans amis?

		This s'appel returns
	*/
}

Affect::Affect(ExpressionPtr x, ExpressionPtr y):
_idvar(x),_exp(y){COUT("Affect::");}

double Affect::calculer(Contexte& contexte){
	COUT("Affect::calculer");
	double val = _exp->calculer(contexte);
	contexte[std::dynamic_pointer_cast<Variable>(_idvar)->str()]=val;

	return val;//returns the value affected 
}

Coloriser::Coloriser(ExpressionPtr iMaison,ExpressionPtr color):
_iMaison(iMaison),_color(std::dynamic_pointer_cast<COORD>(color)){COUT("Coloriser::");}

double Coloriser::calculer(Contexte& contexte){
	COUT("Coloriser::calculer");
	double i=_iMaison->calculer(contexte);

	contexte.Houses()[i].col.x=(int)_color->x(contexte)%256;
	contexte.Houses()[i].col.y=(int)_color->y(contexte)%256;
	contexte.Houses()[i].col.z=(int)_color->z(contexte)%256;

	return (contexte.Houses()[i].col.x
		+contexte.Houses()[i].col.y
		+contexte.Houses()[i].col.z);//(color != black) 
	/*
		Colors hours in context

		This return the wavelength of light associated for the color.. so you can change the color by step while it's below a threshold
	*/
}

Couleur::Couleur(ExpressionPtr iMaison):
_iMaison(iMaison){COUT("Couleur::");}

double Couleur::calculer(Contexte& contexte){
	COUT("Couleur::calculer");
	double i=_iMaison->calculer(contexte);

	std::cout << "(" 
	<< contexte.Houses()[i].col.x <<","
	<< contexte.Houses()[i].col.y <<","
	<< contexte.Houses()[i].col.z <<")";

	return (contexte.Houses()[i].col.x
		+contexte.Houses()[i].col.y
		+contexte.Houses()[i].col.z); // return (color != black) 
	/*
		cout couleur?
		This return f(r,g,b)
	*/
}

Voisin::Voisin(ExpressionPtr iMaison,ExpressionPtr exp):
_iMaison(iMaison),_exp(exp){COUT("Voisin::");}

double Voisin::calculer(Contexte& contexte){
	COUT("Voisin::calculer");
	double vc=contexte.City().VertexCount();
	if(vc<=contexte.Houses().size()) return 0; //are there spaces left?
	
	double r=_exp->calculer(contexte);
	
	auto chooseFrom = contexte.UnOccupied(r,contexte.Houses()[_iMaison->calculer(contexte)].pos);
	int choice = chooseFrom[rand()%chooseFrom.size()]; // YAY needed optimisation
	auto chosen = contexte.GraphCoords()[choice];

	House h;
	h.pos = chosen.first;
	chosen.second = -1;

	contexte.Houses().push_back(h);
	return 1; 
	/*
		Makes house in random location in proximity

		This return 	success ?
	*/
}

hexRGB::hexRGB(const std::string & hexcode):
	_x( (double)std::strtoul(hexcode.substr(1,2).c_str(),0,16)),
	_y( (double)std::strtoul(hexcode.substr(3,2).c_str(),0,16)),
	_z( (double)std::strtoul(hexcode.substr(5,2).c_str(),0,16)){COUT("hexRGB::");}

double hexRGB::calculer(Contexte& contexte){
	COUT("hexRGB::calculer");
	return (_x+_z+_z); // return (color != black)
	/*
		You mainly use getters for this class
		This returns 	the wavelength of light
	*/
}

Si::Si(ExpressionPtr exp,std::vector<ExpressionPtr> sts,std::vector<ExpressionPtr> else_sts): 
_exp(exp),_statements(sts),_else_sts(else_sts){COUT("Si::");}

double Si::calculer(Contexte& contexte){
	COUT("SI::calculer");
	double condition = _exp->calculer(contexte);
	if (condition) 		
		for(auto sts : _statements)
			sts->calculer(contexte);
	else
		for(auto sts : _else_sts)
			sts->calculer(contexte);
	
	return condition;
}

TantQue::TantQue(ExpressionPtr exp,std::vector<ExpressionPtr> sts): 
_exp(exp),_statements(sts){COUT("TantQue::");}

double TantQue::calculer(Contexte& contexte){
	COUT("TantQue::calculer");
	double i=0;
	while (_exp->calculer(contexte)){
		i++;
		for(auto sts : _statements)
			sts->calculer(contexte);
	}
	return i; 		//iterations
}

Repeter::Repeter(ExpressionPtr exp,std::vector<ExpressionPtr> sts): 
_exp(exp),_statements(sts){COUT("Repeter::");}

double Repeter::calculer(Contexte& contexte){
	COUT("Repeter::calculer");
	double i=_exp->calculer(contexte);
	while (i--)
		for(auto sts : _statements) 
			sts->calculer(contexte);

	return i;		//iterations restantes
}//J'aurrais bien aime' moins me repeter...