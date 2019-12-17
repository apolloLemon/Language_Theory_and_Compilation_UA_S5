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

		This returns 	new angle
	*/
}

Orienter::Orienter(ExpressionPtr x, ExpressionPtr y):
_iMaison(x),deg(y){}

double Orienter::calculer(const Contexte& contexte){
	return 0; 
	/*
		Turns a house in Context

		This returns 	new angle
	*/
}

Deplacer::Deplacer(ExpressionPtr x, ExpressionPtr y):
_iMaison(x),_coord(y){}

double Deplacer::calculer(const Contexte& contexte){
	return 0; 
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
	return 0; 
	/*
		cout position?

		This returns 	to hell from whence it came
	*/
}

Orientation::Orientation(ExpressionPtr iMaison):
_iMaison(iMaison){}

double Orientation::calculer(const Contexte& contexte){
	return 0; 
	/*
		cout Orientation?

		This returns 	to hell from whence it came
	*/
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

		This return the wave length of light associated for the color.. so you can change the color by step while it's below a threshold
	*/
}

Couleur::Couleur(ExpressionPtr iMaison):
_iMaison(iMaison){}

double Couleur::calculer(const Contexte& contexte){
	return 0; 
	/*
		cout couleur?

		This return the wave length of light associated for the color.. so you can sort houses by color..  i f   I   a d d   a   s o r t   f u n c
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
		You mainly use getters for this

		This returns 	the wave length of light
	*/
}

Si::Si(ExpressionPtr exp,std::vector<ExpressionPtr> sts,std::vector<ExpressionPtr> else_sts): 
_exp(exp),_statements(sts),_else_sts(else_sts),{}

double Si::calculer(const Contexte& contexte){
	return 0;
	/*
		if exp 		for i in sts: i.exec()
		else 		for i in else_sts: i.exec()

		return 		exp.calculer()
	*/
}

TantQue::TantQue(ExpressionPtr exp,std::vector<ExpressionPtr> sts,std::vector<ExpressionPtr> else_sts): 
_exp(exp),_statements(sts),_else_sts(else_sts),{}

double TantQue::calculer(const Contexte& contexte){
	return 0;
	/*
		while exp 	for i in sts: i.exec()
		
		return 		iterations
	*/
}

Repeter::Repeter(ExpressionPtr exp,std::vector<ExpressionPtr> sts,std::vector<ExpressionPtr> else_sts): 
_exp(exp),_statements(sts),_else_sts(else_sts),{}

double Repeter::calculer(const Contexte& contexte){
	return 0;
	/*
		i=fois
		while i 	for i in sts: i.exec()
					--i
					
		return 		iterations
	*/
}