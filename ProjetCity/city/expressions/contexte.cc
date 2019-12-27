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

int radius2hexcount(int r) {
    if(r==0) return 0;
    return 6*r + radius2hexcount(r-1);
}

void Contexte::Citinit(double r) {
    if(r==0)return;
    int v = radius2hexcount(r);

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
    if(city.VertexCount()==0){ //this makes the pattern for the first layer
            graphcoords.push_back(std::make_pair(coord {1,-1,0},-1));graphcoords.push_back(std::make_pair(coord {1,0,-1},-1));graphcoords.push_back(std::make_pair(coord {0,1,-1},-1));graphcoords.push_back(std::make_pair(coord {-1,1,0},-1));graphcoords.push_back(std::make_pair(coord {-1,0,1},-1));graphcoords.push_back(std::make_pair(coord {0,-1,1},-1));
    }else start_layer = city.VertexCount();

    if(start_layer<r){
        for(int l=start_layer;l<=r;l++){ //this starts from first layer pattern to generate the higher layers 
            int lli0 = graphcoords.size()-((l-1)*6); //lower level index, starts at "0" of previous layer;
            int lli=lli0;
            for(int s=0;s<(l*6);s++){
                if(s%l==0) {
                    coord a = graphcoords[s/l].first;
                    coord b = {a.x*l, a.y*l, a.z*l};
                    graphcoords.push_back(std::pair<coord,double>(b,-1));    
                }else{
                    coord a = graphcoords[lli].first; //this needs testing;
                    coord b = graphcoords[(lli+1)%(lli0+((l-1)*6))].first;
                    coord c = {a.x+b.x, a.y+b.y, a.z+b.z};
                    graphcoords.push_back(std::pair<coord,double>(c,-1));
                    lli++;
                }
            }
        } //this is not in it's own function because it's only done here
    } else {
        auto b = graphcoords.begin();
        auto e = graphcoords.begin()+v;
        std::vector<std::pair<coord,double>> nv(b,e);
        graphcoords = nv;
    }
    city.Citinit((unsigned int)v);
}

double Contexte::Occupied(double x,double y,double z) const {
    for(auto pair : graphcoords)
        if(pair.first == coord {x,y,z})
            return pair.second;
    throw ExceptionContexte("Contexte::Occupied, Non existant Coord");
    //at first I used the solution below, but I now generate a vector
    /*
    for(double i=0; i<Houses().size();i++)
        if(Houses()[i].at(_x,_y,_z))
            return i;
    return -1;
    */
}

std::vector<int> Contexte::UnOccupied() { //returns vector of unoccupied verticies
    std::vector<int> out;
    for (int i = 0; i < (int)graphcoords.size(); ++i)
        if (graphcoords[i].second == -1)
            out.push_back(i);
    return out;
}

std::vector<int> Contexte::UnOccupied(int r,coord c) { //returns vector of unoccupied verticies
    std::vector<int> out;
    for (int i = 0; i < (int)graphcoords.size(); ++i)
        if ((graphcoords[i].second == -1)
            && (graphcoords[i].first.distance(c)<=r)) 
            out.push_back(i);
    return out;
}

void Contexte::UpdateRoads(int n){
    for(int i=0;i<city.VertexCount();i++){
        if(city.hasArc(i,n)){
            double distance=houses[i].pos.distance(houses[n].pos);
            city.Arc(i,n,distance);
        }
        if(city.hasArc(n,i)){
            double distance=houses[i].pos.distance(houses[n].pos);
            city.Arc(n,i,distance);
        }
    }
}

ExceptionContexte::ExceptionContexte(std::string errmsg) :
	_errmsg(errmsg) {}

const char * ExceptionContexte::what() const noexcept {
	return _errmsg.c_str();
}