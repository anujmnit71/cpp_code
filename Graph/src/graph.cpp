/*
//============================================================================
// Name        : graph.cpp
// Author      : anuj
// Version     :
// Copyright   : Your copyright notice
// Description : DFS , BFS , topological sort , articulation point
//============================================================================


// NOTE : GRAPH IS UNDIRECTED
#include <iostream>
#include<cstdlib>
#include<stack>
#include<list>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

//static int count = 0;

class Graph{
	int v;
	list<int>* adjList;


public :
	static int count;
	Graph(int vertex){
		this->v = vertex;
		this->adjList = new list<int>[vertex];
	}
	bool visited[100];
	void addEdge(int v , int w);
	void visitBFS();
	void visitDFS();
	void topologicalSortHelp(int src);
	void topologicalSort();
	void AP();
	void APutil(int src , int p  , int low[] , int parent[]);
};

int Graph::count = 1;

void Graph::addEdge(int src , int dest){
	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}

void Graph::topologicalSort(){
	for(int i=0 ; i< v ; i++){
		if(!this->visited[i])
			this->topologicalSortHelp(i);
	}

}

void Graph::topologicalSortHelp(int src){
	stack<int> st;
	this->visited[src] = true;

	std::list<int>::iterator itrList = this->adjList[src].begin();
	for( ; itrList!= this->adjList[src].end() ; itrList++ ){
		if(!this->visited[*itrList]){
			int a = *itrList;
			st.push(a);
			topologicalSortHelp(a);
		}
	}

}


void Graph::AP(){
//	bool visit[v];
	int low[v];
	int dfsno[v];


	for(int i=0 ; i< v ; i++)
		visit[i] = false;


	for(int i=0 ; i< v ; i++)
		low[i] = 100;

	for(int i=0 ; i< v ; i++)
		dfsno[i] = -1;

	this->APutil(0 , 0 , low , dfsno) ;

	for(int i=0 ; i< v ; i++)
		cout<<low[i]<<' ';
	cout<<endl;
	for(int i=0 ; i< v ; i++)
		cout<<dfsno[i]<<' ';
}



void Graph::APutil(int src ,int p  , int low[] , int dfsno[]){

	dfsno[src] = Graph::count;
	count++;
	low[src] = dfsno[src];

	std::list<int>::iterator itrList = this->adjList[src].begin();
	for( ; itrList!= this->adjList[src].end() ; itrList++ ){
		if(dfsno[*itrList] == -1){
			this->APutil(*itrList ,src , low , dfsno);
			low[src] = std::min(low[src] , low[*itrList]);
			if( low[*itrList] >= dfsno[src])
				cout<<src<<"is AP"<<endl;
		}
		else if(*itrList != p)
			low[src] = std::min(low[src] , dfsno[*itrList]);
	}

}



void Graph::visitDFS(){
	int src = 0;
	int v = this->v;
	bool visited[v];
	stack<int> st;

	for(int i=0 ; i< v ; i++){
		visited[i] = false;
	}
	st.push(src);
	visited[src] = true;

	while(!st.empty()){
		int m = st.top();
		st.pop();
		//visited[m] = true;
		cout<<m<<' ';
		std::list<int>::iterator itrList = this->adjList[m].begin();
		for( ; itrList!= this->adjList[m].end() ; itrList++ ){
			if(!visited[*itrList]){
				int a = *itrList;
				st.push(a);
				visited[a] = true;
			}
		}

	}

}

void Graph::visitBFS(){
	int src = 0;
		int v = this->v;
		bool visited[v];
		list<int> queue;

		for(int i=0 ; i< v ; i++){
			visited[i] = false;
		}
		queue.push_back(src);
		visited[src] = true;

		while(!queue.empty()){
			std::list<int>::iterator itr = queue.begin();
			queue.pop_front();
			int m = *itr;
			//visited[m] = true;
			cout<<m<<' ';
			std::list<int>::iterator itrList = this->adjList[m].begin();
			for( ; itrList!= this->adjList[m].end() ; itrList++ ){
				if(!visited[*itrList]){
					int a = *itrList;
					queue.push_back(a);
					visited[a] = true;
				}
			}

		}

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


		g.visitBFS();
		cout<<endl;
		g.visitDFS();
		cout<<endl;
		g.topologicalSort();
		g.AP();

	}
}




 /* incorrect
void Graph::AP(){
	bool visit[v];
	int low[v];
	int parent[v];

	for(int i=0 ; i< v ; i++)
		visit[i] = false;

	for(int i=0 ; i< v ; i++)
		low[i] = 100;

	for(int i=0 ; i< v ; i++)
			parent[i] = -1;

	this->APutil(0 , 0 ,0, visit , low , parent) ;

	for(int i=0 ; i< v ; i++)
			cout<<low[i]<<' ';
	cout<<endl;

	for(int i=0 ; i< v ; i++){
		bool isAP = false;
		std::list<int>::iterator itrList = this->adjList[i].begin();
		for( ; itrList!= this->adjList[i].end() ; itrList++ ){
			if( *itrList != parent[i] && low[*itrList] > low[i] ){
				isAP = true;
				break;
			}
		}

		if(isAP)
			cout<<i<<"is AP"<<endl;
	}

}



void Graph::APutil(int src ,int p , int count , bool visit[] , int low[] , int parent[]){
	visit[src] = true;
	low[src] = count++;
	parent[src] = p;
	std::list<int>::iterator itrList = this->adjList[src].begin();
	for( ; itrList!= this->adjList[src].end() ; itrList++ ){
		if(!visit[*itrList]){
			this->APutil(*itrList ,src , count , visit , low , parent);
		}
		else if(*itrList != p)
			low[src] = std::min(low[src] , low[*itrList]);
	}

}


*/
