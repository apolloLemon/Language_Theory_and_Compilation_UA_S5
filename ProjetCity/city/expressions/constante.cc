#include "constante.hh"

Constante::Constante(double valeur) : _valeur(valeur) {}

double Constante::calculer(Contexte & contexte) {
    return _valeur;
}
