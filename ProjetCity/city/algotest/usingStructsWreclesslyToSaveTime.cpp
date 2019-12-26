#include <iostream>
#include <sstream>
#include <vector>
#define LOG(x) std::cout << x << std::endl // uses << to concat

struct coord {
    double x,y,z;

    bool operator==(const coord & o){
        return (x==o.x)
            && (y==o.y)
            && (z==o.z);
    }
};

std::vector<std::pair<coord,double>> graphcoords;

//function for test output
std::string addspacetopos(double x){
    std::stringstream s;
    if(x>=0) s << " ";
    s<<x;
    return s.str();
}

std::string coord2str(coord xyz){
    std::stringstream s;
    s                              <<  "("     << 
            addspacetopos(xyz.x)   <<  ","     << 
            addspacetopos(xyz.y)   <<  ","     <<
            addspacetopos(xyz.z)   <<  ")";
    return s.str();
}

int main() {
	graphcoords.push_back(std::make_pair(coord {1,-1,0},-1));graphcoords.push_back(std::make_pair(coord {1,0,-1},-1));graphcoords.push_back(std::make_pair(coord {0,1,-1},-1));graphcoords.push_back(std::make_pair(coord {-1,1,0},-1));graphcoords.push_back(std::make_pair(coord {-1,0,1},-1));graphcoords.push_back(std::make_pair(coord {0,-1,1},-1));

	for(auto i : graphcoords)
		if(i.first == coord {1,-1,0})
			LOG("wow");
}
/*
*/