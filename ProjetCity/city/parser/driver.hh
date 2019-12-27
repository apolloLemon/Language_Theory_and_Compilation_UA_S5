#ifndef DRIVER_H
#define DRIVER_H

#include <string>

#include "contexte.hh"
#include "expression.hh"
#include "variable.hh"

class Driver {
private:
    Contexte _variables;       

    //Maisons
    //Graphe
public:
    std::vector<ExpressionPtr> ast;//AST?
    Driver() = default;
    ~Driver() = default;
    Driver(const Driver&) = default;

    Contexte& getContexte();
    double  getVariable(const std::string& name) const;
    void    setVariable(const std::string& name, double value);
    void	setAST(std::vector<ExpressionPtr> top);
};

#endif
