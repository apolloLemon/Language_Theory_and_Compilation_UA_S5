#include "graph.h"
#include <iostream>


std::ostream & operator<< (std::ostream & os, Graph & g){
	 g.OutStream(os);
	 return os;
}

std::ostream & Graph::OutStream(std::ostream & os) {
	for(unsigned int i=0;i<vertexCount;i++){
		for(unsigned int j=0;j<vertexCount;j++)
			os << adjacencyMatrix[i][j] << "\t";
		os << "\n";
	}
	return os;
}

/*
General graph methods
init 	adjmtrx=0
Arc 	adjmtrx[s][d]=w
*/

void Graph::Init(unsigned int nV) {
	vertexCount=nV;
	for(unsigned int i=0;i<vertexCount;i++)
		for(unsigned int j=0;j<vertexCount;j++)
			adjacencyMatrix[i][j]=std::numeric_limits<double>::infinity();
	//std::cout << "Graph::Init of size "<<vertexCount<<" completed\n";
}

//void Graph::SetOriented(bool o){} //in .h

void Graph::Arc(int src, int dst, double w) {
	if(!oriented) adjacencyMatrix[dst][src]=w;
	adjacencyMatrix[src][dst]=w;
}