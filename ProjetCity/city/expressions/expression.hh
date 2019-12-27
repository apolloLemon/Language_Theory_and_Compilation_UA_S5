#pragma once
#include <memory>
#include "contexte.hh"


class Expression {
public:
    virtual double calculer(Contexte & contexte) = 0;
};

using ExpressionPtr = std::shared_ptr<Expression>;

