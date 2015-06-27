/*
//============================================================================
// Name        : graph.cpp
// Author      : anuj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


// NOTE : GRAPH IS UNDIRECTED
#include <iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<list>
#include<stack>
#include<map>
using namespace std;

#define re(i, l, r) for (int i=l; i<r; i++)

class Graph{
	int v;
	list<int>* adjList;

public :
	Graph(int vertex){
		this->v = vertex;
		this->adjList = new list<int>[vertex];
		this->visited = new bool[v];
	}
	bool * visited;
	void addEdge(int s , int d);
	void vertexCover();
};



void Graph::addEdge(int src ,int dest){
	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}

void Graph::vertexCover(){
	for(int i=0 ; i< v ; i++){
		this->visited[i] = false;
	}

	std::map<int , int> myset;

	re(u , 0 , v){
		if(!visited[u]){
			for(std::list<int>::iterator itr = this->adjList[u].begin() ; itr != this->adjList[u].end() ; itr++ ){
				int val = *itr;
				if(!visited[val]){
					myset[u] = val;
					visited[u] = true;
					visited[val] = true;
					break;
				}
			}
		}
	}

	for(std::map<int , int>::iterator itr = myset.begin() ; itr!= myset.end() ; itr++)
			cout<<itr->first<<' '<<itr->second<<endl;

}

int main() {
	int test;
	int v;

	ifstream infile("ip");
	infile>>test;
	while(test--){
		infile>>v;
		Graph g(v);
		int src,dest;
		int e;
		infile>>e;
		for(int i=0 ; i<e ; i++){
			infile>>src>>dest;
			g.addEdge(src , dest);
		}
		for(int i=0 ; i< v ; i++){
			g.visited[i] = false;
		}
		g.vertexCover();

	}
}
*/
