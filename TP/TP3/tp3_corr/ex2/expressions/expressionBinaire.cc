#include "expressionBinaire.hh"
#include <stdexcept>


ExpressionBinaire::ExpressionBinaire(ExpressionPtr gauche, ExpressionPtr droite, OperateurBinaire op):
    _gauche(gauche), _droite(droite), _op(op) {

}

double ExpressionBinaire::calculer(const Contexte& contexte) const {
    double gauche = _gauche->calculer(contexte), droite = _droite->calculer(contexte);
    switch (_op) {
        case OperateurBinaire::plus: return gauche + droite;
        case OperateurBinaire::moins: return gauche - droite;
        case OperateurBinaire::divise: {
            if (droite == 0) throw std::domain_error("division par 0");
            return gauche / droite;
        }
        case OperateurBinaire::multiplie: return gauche * droite;
        default: return 0;
    }
}