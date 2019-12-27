#ifndef context_h
#define context_h

#include <string>
#include <map>
#include <exception>
#include <vector>

#include "graph.hh"

class ExceptionContexte : public std::exception {
	public:
	ExceptionContexte(std::string);

	const char * what() const noexcept override;
private:
	std::string _errmsg;
};

struct coord {
    double x,y,z;

    bool operator==(const coord & o){
        return (x==o.x)
            && (y==o.y)
            && (z==o.z);
    }
    double distance(const coord & o){
        return (
            o.x-x
        +   o.y-y
        +   o.z-z
            )/2;
    }
};

int radius2hexcount(int);


struct House {
    std::string identifier;
    double orientation;
    int r,g,b;
    coord pos,col;

    bool at(double _x,double _y,double _z)const{return (pos.x==_x)&&(pos.y==_y)&&(pos.z==_z);}
    bool at(coord o){return pos==o;}

    bool id(std::string id)const{return (identifier==id);}

    void place(coord c){pos=c;}
    void orient(){orientation=(int)orientation%360;}
    void orient(double o){orientation=(int)o%360;}
};

class Contexte {
private:
    std::map<std::string, double> variables;
    std::vector<std::pair<coord,double>> graphcoords;
    std::vector<House> houses;
    Graph city;
public:


    Contexte() = default;
    Contexte(const Contexte & autre) = default;

    Graph& City() {return city;}
    void Citinit(double r);
   
    std::vector<House>& Houses(){return houses;}
   
    std::vector<std::pair<coord,double>> & GraphCoords() {return graphcoords;}
    double Occupied(double x,double y,double z) const;
    std::vector<int> UnOccupied(); //returns vector of unoccupied verticies
    std::vector<int> UnOccupied(int,coord);

    double& get(const std::string & nom);
    const double& get(const std::string & nom) const;
    double& operator[](const std::string & nom);
    const double& operator[](const std::string & nom) const;

    void UpdateRoads(int);

};


#endif