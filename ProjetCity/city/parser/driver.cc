#include "driver.hh"
#include <iostream>


const Contexte& Driver::getContexte() const {
    return _variables;
}

double Driver::getVariable(const std::string & name) const {
    return _variables.get(name);
}

void Driver::setVariable(const std::string & name, double value) {
    _variables[name] = value;
}