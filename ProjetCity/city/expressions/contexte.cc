#include "contexte.hh"

double& Contexte::get(const std::string & nom) {
	return variables[nom];
}

const double& Contexte::get(const std::string & nom) const {
    auto it = variables.find(nom);
    if(it==variables.end()) throw ExceptionContexte(nom +": Identifiant Inconnu");
    return variables.at(nom);
}

double& Contexte::operator[](const std::string & nom) {
    return variables[nom];
}

const double& Contexte::operator[](const std::string & nom) const {
    auto it = variables.find(nom);
    if(it==variables.end()) throw ExceptionContexte(nom +": Identifiant Inconnu");
    return variables.at(nom);
}

void Citinit(double r) {
    if(r==0)return;
    city.Citinit(r*6);
    
    graphcoords.push_back({-1,0,1});graphcoords.push_back({-1,1,0});graphcoords.push_back({0,-1,1});graphcoords.push_back({0,1,-1});graphcoords.push_back({1,0,-1});graphcoords.push_back({1,-1,0});
    for(int l=2;l<=r;l++){
        for(int s=0;s<(l*6);s++){
            if(s%l==0) {
                coord a = graphcoords[s/l];
                graphcoords.push_back({a.x*l,a.y*l,a.z*l});    
            }else{
                coord a = graphcoords[s];
                coord b = graphcoords[(s+1)%((l-1)*6)]
                graphcoords.push_back({a.x+b.x,a.y+b.y,a.z+b.z})
            }
        }
    }

}

bool Contexte::Occupied(double x,double y,double z) const {
    for(double i=0; i<Houses().size();i++)
        if(Houses()[i].at(_x,_y,_z))
            return i;
    return -1;
}

ExceptionContexte::ExceptionContexte(std::string errmsg) :
	_errmsg(errmsg) {}

const char * ExceptionContexte::what() const noexcept {
	return _errmsg.c_str();
}