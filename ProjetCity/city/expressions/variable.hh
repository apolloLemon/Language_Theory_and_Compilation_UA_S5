#pragma once
#include <string>
#include "expression.hh"



class Variable : public Expression {
public:
    Variable() = delete;
    Variable(const Variable &) = default;
    Variable(const std::string & nom);
    
    double calculer(Contexte& contexte) override;
    std::string str() const {return _nom;}

private:
    std::string _nom;
};
