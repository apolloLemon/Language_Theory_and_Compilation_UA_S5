#ifndef context_h
#define context_h

#include <string>
#include <map>
#include <exception>

#include "graph.hh"

class ExceptionContexte : public std::exception {
	public:
	ExceptionContexte(std::string);

	const char * what() const noexcept override;
private:
	std::string _errmsg;
};

struct House {
    std::string identifier;
    double x, y, z, orientation;
    int r,g,b;

    bool at(double _x,double _y,double _z)const{return (x==_x)&&(y==_y)&&(z==_z);}
    bool id(std::string id)const{return (identifier==id);}

    void orient(){orientation=orientation%360;}
    void orient(double o){orientation=o%360;}
}

class Contexte {
private:
    std::map<std::string, double> variables;
    std::vector<House> houses;
    Graph city;
public:


    Contexte() = default;
    Contexte(const Contexte & autre) = default;

    Graph& City() {return city;}
    std::vector<House>& Houses(){return houses;}
    double Occupied(double x,double y,double z) const;

    double& get(const std::string & nom);
    const double& get(const std::string & nom) const;
    double& operator[](const std::string & nom);
    const double& operator[](const std::string & nom) const;

};


#endif