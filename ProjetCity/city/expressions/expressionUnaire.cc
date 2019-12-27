#include "expressionUnaire.hh"

ExpressionUnaire::ExpressionUnaire(ExpressionPtr exp, OperateurUnaire op):
    _exp(exp), _op(op) {

}

double ExpressionUnaire::calculer(Contexte& contexte) {
    double exp = _exp->calculer(contexte);
    switch (_op) {
        case OperateurUnaire::neg: return -exp;
        case OperateurUnaire::lneg: return not exp;
        default: return 0;
    }
}