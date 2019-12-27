#include "variable.hh"

Variable::Variable(const std::string& nom) : _nom(nom) {}

double Variable::calculer(Contexte & contexte) {
    return contexte[_nom];
}