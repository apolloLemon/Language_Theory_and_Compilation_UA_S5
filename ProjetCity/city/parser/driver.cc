#include "driver.hh"
#include <iostream>


Contexte& Driver::getContexte() {
    return _variables;
}

double Driver::getVariable(const std::string & name) const {
    return _variables.get(name);
}

void Driver::setVariable(const std::string & name, double value) {
    _variables[name] = value;
}

void Driver::setAST(std::vector<ExpressionPtr> top) {
	std::cout<<"Driver::setAST\n";
    ast = top;
}