#include "graph.hh"
#include <iostream>
double INF = std::numeric_limits<double>::infinity();


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
			adjacencyMatrix[i][j]=INF;
	//std::cout << "Graph::Init of size "<<vertexCount<<" completed\n";
}

void Graph::Citinit(unsigned int nV) {
	if(vertexCount) {
		if (vertexCount<nV) {
			for(unsigned int i=vertexCount;i<nV;i++)
				for(unsigned int j=vertexCount;j<nV;j++)
					adjacencyMatrix[i][j]=INF;
		}else{
			for(unsigned int i=vertexCount-1;i>=nV;i--)
				for(unsigned int j=vertexCount;j>=nV;j--)
					adjacencyMatrix[i][j]=INF;
		}
		vertexCount=nV;
	} else Init(nV);
}

//void Graph::SetOriented(bool o){} //in .h

void Graph::Arc(int src, int dst, double w) {
	if(!oriented) adjacencyMatrix[dst][src]=w;
	adjacencyMatrix[src][dst]=w;
}

void Graph::RemoveArc(int src, int dst) {
	if(!oriented) adjacencyMatrix[dst][src]=INF;;
	adjacencyMatrix[src][dst]=INF;
}

void Graph::RemoveNode(int n){
	for(unsigned int i=0;i<vertexCount;i++){
		if(i==(unsigned int)n)continue;
		adjacencyMatrix[n][i]=INF;
		adjacencyMatrix[i][n]=INF;
	} //remove all roads

	for(unsigned int i=0;i<vertexCount;i++)
		for(unsigned int j=n+1;j<vertexCount;j++) {
			if(adjacencyMatrix[i][j]!=INF){
				adjacencyMatrix[i][j-1]=adjacencyMatrix[i][j];
				adjacencyMatrix[i][j]=INF;
			}
			if(adjacencyMatrix[j][i]!=INF){
				adjacencyMatrix[j-1][i]=adjacencyMatrix[j][i];
				adjacencyMatrix[j][i]=INF;
			}

		} //move roads "down" 
		/*
			This is where an arraymatrix adjacencyMatrix
			shows it's weakness...   buuutt too late now

			ok... that wasn't too bad.. now let's forget optimisation, for very large graphs..
		*/

	for(unsigned int i=0;i<vertexCount;i++){
		adjacencyMatrix[vertexCount-1][i]=INF;
		adjacencyMatrix[i][vertexCount-1]=INF;
	}//clear top layer
}