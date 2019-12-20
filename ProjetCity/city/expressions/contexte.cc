#include "contexte.hh"

double& Contexte::get(const std::string & nom) {
	return variables[nom];
}

const double& Contexte::get(const std::string & nom) const {
    auto it = variables.find(nom);
    if(it==variables.end()) throw ExceptionContexte(nom +": Identifiant Inconnu");
    return variables.at(nom);
}

double& Contexte::operator[](const std::string & nom) {
    return variables[nom];
}

const double& Contexte::operator[](const std::string & nom) const {
    auto it = variables.find(nom);
    if(it==variables.end()) throw ExceptionContexte(nom +": Identifiant Inconnu");
    return variables.at(nom);
}

bool Contexte::Occupied(double x,double y,double z) const {
    for(double i=0; i<Houses().size();i++)
        if(Houses()[i].at(_x,_y,_z))
            return i;
    return -1;
}

ExceptionContexte::ExceptionContexte(std::string errmsg) :
	_errmsg(errmsg) {}

const char * ExceptionContexte::what() const noexcept {
	return _errmsg.c_str();
}