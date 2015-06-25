#include<iostream>
#include<vector>
#include<stdbool.h>
#include "graph.hpp"

#define FOR(i,n) for(i=0;i<n;i++)
#define DIRECTED true
#define UNDIRECTED false

using namespace std;

template<class T> void tester(Graph<T>* G){
	int i;
	G->addNode(1);
	G->addNode(2);
	G->addNode(3);
	G->addNode(4);
	G->addNode(5);
	G->addNode(6);
	G->addNode(7);
	G->addNode(8);
	G->addEdge(1,2);
	G->addEdge(1,3);
	G->addEdge(1,7);
	G->addEdge(2,4);
	G->addEdge(2,5);
	G->addEdge(3,5);
	G->addEdge(5,6);
	G->addEdge(2,8);
	G->addEdge(5,1);
	G->addEdge(8,6);
	G->addEdge(2,4);
	G->addEdge(5,3);
	G->addEdge(3,2);
	cout<<G->shortestPathDistanceBFS(1,8)<<endl;
	// G->printNodes();
	// G->printEdges();
	// vector<int> a = G->breadthFirstSearch(1);
	// FOR(i,a.size())
	// 	cout<<a[i]<<endl;
	// cout<<endl;
	// vector<int> b = G->depthFirstSearch(1);
	// FOR(i,b.size())
	// 	cout<<b[i]<<endl;
}

int main(){
    Graph<int> G(UNDIRECTED);		//Graph type to be initialized here itself.
    tester(&G);
    return 0;
}
