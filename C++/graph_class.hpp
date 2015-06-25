#include<iostream>

using namespace std;

template<class T> class Graph{
private:
    //Data members
    vector<T> nodes;
    bool graphType;
    vector<pair<T,T> > edges;	//In directed graphs : <T t1,T t2> t1 (tail) -------------> t2 (head)

    //Function Members
    bool isUnexplored(T,vector<T>*);
public:
    //Constructor
    Graph();
    Graph(bool);

    //Add nodes,edges to graph
    void addNode(T);
    void addEdge(T,T);

    //Print the graph
    void printNodes();
    void printEdges();

    //Search the graph
    vector<T> breadthFirstSearch(T);
    vector<T> depthFirstSearch(T);

    //Shortest Paths
    int shortestPathDistanceBFS(T,T);
    //Neighbours
    vector<T> neighbours(T);
};
