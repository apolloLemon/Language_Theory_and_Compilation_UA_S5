#pragma once
#include "expression.hh"


enum class OperateurUnaire {
    neg,
    lneg
};

class ExpressionUnaire : public Expression {
public:
    ExpressionUnaire(const ExpressionUnaire &) = default;
    ExpressionUnaire(ExpressionPtr exp, OperateurUnaire op);
    ~ExpressionUnaire() = default;

    double calculer(Contexte& contexte) override;

private:
    ExpressionPtr _exp;
    OperateurUnaire _op;
};
