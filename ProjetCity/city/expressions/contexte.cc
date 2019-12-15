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

ExceptionContexte::ExceptionContexte(std::string errmsg) :
	_errmsg(errmsg) {}

const char * ExceptionContexte::what() const noexcept {
	return _errmsg.c_str();
}