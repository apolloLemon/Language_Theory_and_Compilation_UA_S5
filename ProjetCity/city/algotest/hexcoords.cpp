#include <iostream>
#include <sstream>
#include <vector>
#define LOG(x) std::cout << x << std::endl

struct coord {
    double x,y,z;
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
    int r = 3;

    int start_layer=2;
    //if(city.vertexCount()==0); //this makes the pattern for the first layer
        graphcoords.push_back(std::make_pair(coord {1,-1,0},-1));graphcoords.push_back(std::make_pair(coord {1,0,-1},-1));graphcoords.push_back(std::make_pair(coord {0,1,-1},-1));graphcoords.push_back(std::make_pair(coord {-1,1,0},-1));graphcoords.push_back(std::make_pair(coord {-1,0,1},-1));graphcoords.push_back(std::make_pair(coord {0,-1,1},-1));
    //else start_layer = city.vertexCount();

    if(start_layer<r){
        for(int l=start_layer;l<=r;l++){ //this starts from first layer pattern to generate the higher layers 
            int lli0 = graphcoords.size()-((l-1)*6); //lower level index, starts at "0" of previous layer;
            int lli=lli0;
            LOG(l<<" "<<lli);
            for(int s=0;s<(l*6);s++){
                if(s%l==0) {
                    coord a = graphcoords[s/l].first;
                    coord b = {a.x*l, a.y*l, a.z*l};
                    graphcoords.push_back(std::pair<coord,double>(b,-1));    
                }else{
                    LOG(lli<<" "<<lli+1);
                    coord a = graphcoords[lli].first; //this needs testing;
                    coord b = graphcoords[(lli+1)%(lli0+((l-1)*6))].first;
                    coord c = {a.x+b.x, a.y+b.y, a.z+b.z};
                    LOG(coord2str(a));
                    LOG(coord2str(b));
                    LOG(coord2str(c));
                    graphcoords.push_back(std::pair<coord,double>(c,-1));
                    lli++;
                }
            }
        } //this is not in it's own function because it's only done here
    }
    LOG("");
    int i=0;
    for(auto c : graphcoords){ ++i;
        LOG(coord2str(c.first)<<"   \t"<< c.second);
    }
    LOG(i);
/*
*/
}