#include<stack>
#include<queue>
#include<map>
#include "graph_class.hpp"

#define FOR(i,n) for(i=0;i<n;i++)
#define DIRECTED true
#define UNDIRECTED false


//PRIVATE MEMBERS DEFINITION
template<class T> bool Graph<T>::isUnexplored(T t,vector<T>* explored){
    int i;
    FOR(i,explored->size()){
        if((*explored)[i]==t)
            return false;
    }
    return true;
}
//PUBLIC MEMBERS DEFINITION
/*
Constructor assigning the type of the graph by using UNDIRECTED and DIRECTED.
Third Constructor says whether graph is weighted or not.
*/
template<class T> Graph<T>::Graph(){
    graphType=false;
}
template<class T> Graph<T>::Graph(bool a){
    graphType=a;
}

/*
Function to add nodes to the graph.
*/
template<class T> void Graph<T>::addNode(T t){
    nodes.push_back(t);
}

/*
Function to add edges to the graph. In a directed graph, t1 is the tail and t2 is the head
t1 ------------> t2
*/
template<class T> void Graph<T>::addEdge(T t1,T t2){
    edges.push_back(make_pair(t1,t2));
}

/*
Function to print all the nodes of the Graph
*/
template<class T> void Graph<T>::printNodes(){
    int i;
    FOR(i,nodes.size())
        cout<<nodes[i]<<endl;
}

    /*
    Function to return all the neighbours of given node.
    */

template<class T> vector<T> Graph<T>::neighbours(T t){
    vector<T> nbs;
    /*
    DIRECTED GRAPH
    */
    if(graphType==true){
        int i;
        FOR(i,edges.size()){
            if(edges[i].first==t)
                nbs.push_back(edges[i].second);
        }
    }

    /*
    UNDIRECTED GRAPH
    */
    else{
        int i;
        FOR(i,edges.size()){
            if(edges[i].first==t)
                nbs.push_back(edges[i].second);
                else if(edges[i].second==t)
                nbs.push_back(edges[i].first);
            }
        }
    return nbs;
}

/*
Function to print all the edges from the graph
*/
template<class T> void Graph<T>::printEdges(){
    for(int i=0;i<edges.size();i++){
        cout<<edges[i].first<<","<<edges[i].second<<endl;
    }
}

/*
Function to perform BFS on the graph.
*/
template<class T> vector<T> Graph<T>::breadthFirstSearch(T t){
    vector<T> Explored,Neighbours;
    int i;
    Explored.push_back(t);
    queue<T> Q;
    Q.push(t);
    T V;
    while(Q.size()!=0){
        V=Q.front();
        Q.pop();
        Neighbours=neighbours(V);
        FOR(i,Neighbours.size()){
            if (isUnexplored(Neighbours[i],&Explored)){
                Explored.push_back(Neighbours[i]);
                Q.push(Neighbours[i]);
            }
        }
    }
    return Explored;
}

/*
Function to perform DFS on the graph.
*/
template<class T> vector<T> Graph<T>::depthFirstSearch(T t){
    vector<T> Explored,Neighbours;
    int i;
    Explored.push_back(t);
    stack<T> S;
    S.push(t);
    T V;
    while(S.empty()!=1){
        V=S.top();
        S.pop();
        Neighbours=neighbours(V);
        FOR(i,Neighbours.size()){
            if (isUnexplored(Neighbours[i],&Explored)){
                Explored.push_back(Neighbours[i]);
                S.push(Neighbours[i]);
            }
        }
    }
    return Explored;
}

/*
    Function to find the shortest distance to a element.
*/
template<class T> int Graph<T>::shortestPathDistanceBFS(T t1,T t2){
    vector<T> Explored,Neighbours;
    int i,d=1;
    T V;
    map<T,int> Dist;    //Works like a python dict

    Explored.push_back(t1);
    queue<T> Q;
    Q.push(t1);
    Dist[t1]=0;
    while(Q.size()!=0){
        V=Q.front();
        Q.pop();
        Neighbours=neighbours(V);
        FOR(i,Neighbours.size()){
            if (isUnexplored(Neighbours[i],&Explored)){
                Explored.push_back(Neighbours[i]);
                Dist[Neighbours[i]]=Dist[V]+1;
                Q.push(Neighbours[i]);
            }
            if(Neighbours[i]==t2){
                return Dist[Neighbours[i]];
            }
        }
    }
    return -1;
}
