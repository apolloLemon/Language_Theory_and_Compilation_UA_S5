//#include <string>
//#include <vector>
//#include <set>
//#include <tuple>
#include <array>
#include <limits>
#include <ostream>
#include <iostream>


class Graph {
/*
Types and Constants
Here are defined:
	the Max size of any graph,
and the data structure for the Adjacency Matrix
*/
public:
	static const unsigned int MAX = 1000;
	typedef std::array<std::array<double, MAX>,MAX> Matrix;
//End of Types and Constants


/*
General Graph Properties and Methods

Here are the "basic graph" attributes and methods
*/
private:
	//Adjacency Matrix
	Matrix adjacencyMatrix; //Adjacency Matrix double weight
	unsigned int vertexCount; //number of veticies
	bool oriented;

public:
	//Constructors, initators, setters
	//Graph<T>();
	//~Graph<T>()=default;

	void Init(unsigned int);
	
	void SetOriented(bool o){oriented=o;}
	void Arc(int,int,double);

	/*
	Information (const)
	
	We have << Graph
	and the usual getters
	*/
	std::ostream & OutStream(std::ostream & os);
	friend std::ostream & operator<<(std::ostream &, Graph &);

	//Getters
	int VertexCount() const {return vertexCount;}
	double Arc(int src,int dst) const {return adjacencyMatrix[src][dst];}

	//Algorithms
private:
	std::array<bool, MAX> seen;
public:
	void DepthFirstSearch();
	void BreadthFirstSearch();
	void Explore(int);
//End Of General Graph Stuff
};


/*
class CityGraph : public Graph {
private:

};
*/