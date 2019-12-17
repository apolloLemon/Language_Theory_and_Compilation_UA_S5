#include "myexpressions.hh"


/*NODE::NODE(ExpressionPtr x):
_x(x){}

double NODE::calculer(const Contexte& contexte){
	return 0; 
	/*
		This returns 	the index of the node
}
	*/


COORD::COORD(ExpressionPtr x,ExpressionPtr y,ExpressionPtr z):
_x(x),_y(y),_z(z){}

double COORD::calculer(const Contexte& contexte){
	return 0; 
	/*
		This returns 	1 if the coord is occupied
						0 else
	*/
}

NODE::NODE(ExpressionPtr iMaison):
_iMaison(iMaison){}

double NODE::calculer(const Contexte& contexte){
	return 0; 
	/*
		This returns 	the index of the node
	*/
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
	return 0; 
	/*
		This returns 	the index of the node
	*/
}

Route::Route(ExpressionPtr x, ExpressionPtr y):
_src(x),_dst(y){}

double Route::calculer(const Contexte& contexte){
	return 0; 
	/*
		Adds an arc to the graph in Context

		This returns 	1 if the road was made
						0 if not
	*/
}

Tourner::Tourner(ExpressionPtr x, double y):
_iMaison(x),_dir(y){}

double Tourner::calculer(const Contexte& contexte){
	return 0; 
	/*
		Turns a house in Context

		This returns 	success ?
	*/
}

Tourner::Tourner(ExpressionPtr x, ExpressionPtr y):
_iMaison(x),deg(y){}

double Tourner::calculer(const Contexte& contexte){
	return 0; 
	/*
		Turns a house in Context

		This returns 	success ?
	*/
}