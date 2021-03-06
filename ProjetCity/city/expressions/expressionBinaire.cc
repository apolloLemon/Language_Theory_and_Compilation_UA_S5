#include "expressionBinaire.hh"


ExpressionBinaire::ExpressionBinaire(ExpressionPtr gauche, ExpressionPtr droite, OperateurBinaire op):
    _gauche(gauche), _droite(droite), _op(op) {

}

double ExpressionBinaire::calculer(Contexte& contexte) {
    double gauche = _gauche->calculer(contexte), droite = _droite->calculer(contexte);
    switch (_op) {
        case OperateurBinaire::plus: return gauche + droite;
        case OperateurBinaire::moins: return gauche - droite;
        case OperateurBinaire::divise: return gauche / droite;
        case OperateurBinaire::multiplie: return gauche * droite;
        case OperateurBinaire::egal: return gauche == droite;
        case OperateurBinaire::negal: return gauche != droite;
        case OperateurBinaire::inf: return gauche < droite;
        case OperateurBinaire::sup: return gauche > droite;
        default: return 0;
    }
}