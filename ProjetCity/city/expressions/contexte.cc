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
    

    /*
        This code is to fill my graphcoords list,
        because we're representing a hexagonal map.. our coord system is fun
        x, y, z, on a 2d plane
        but there are patterns to be found.

        first, the first layer around the central hex has for coordinades 
        all the permutations of {-1,0,1}. 3! permutations, 6 spots on the first layer, pretty coo'
        the the next layers can be build from the lower layers ..could maybe of made this recursive

        So the next layer, is just the coord*layer number for all the hex inline with the x y z axis
        and the sum of the two hexes it "sits in" other wise

        generally, the coord of the new hex, is the sum of the two hexes it touches on the lower layer
    */
    int start_layer=2;
    if(city.vertexCount()==0); //this makes the pattern for the first layer
        graphcoords.push_back({-1,0,1});graphcoords.push_back({-1,1,0});graphcoords.push_back({0,-1,1});graphcoords.push_back({0,1,-1});graphcoords.push_back({1,0,-1});graphcoords.push_back({1,-1,0});
    else start_layer = city.vertexCount();
    for(int l=start_layer;l<=r;l++){ //this starts from first layer pattern to generate the higher layers 
        for(int s=0;s<(l*6);s++){
            if(s%l==0) {
                coord a = graphcoords[s/l];
                coord b = {a.x*l, a.y*l, a.z*l};
                graphcoords.push_back(std::pair<coord,bool>(b,0));    
            }else{
                coord a = graphcoords[s%((l-1)*6)]; //this needs testing;
                coord b = graphcoords[(s+1)%((l-1)*6)];
                coord c = {a.x+b.x, a.y+b.y, a.z+b.z};
                graphcoords.push_back(std::pair<coord,bool>(c,0));
            }
        }
    } //this is not in it's own function because it's only done here

    city.Citinit(r*6);
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