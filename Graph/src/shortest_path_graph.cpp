/*
//============================================================================
// Name        : graph.cpp
// Author      : anuj
// Version     :
// Copyright   : Your copyright notice
// Description : Dijkstra , Bellman Ford , AP
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
using namespace std;

struct edge{
	int src;
	int dest;
	int weight;
};

class Graph{
	int v;
	list<struct edge>* adjList;


public :

	Graph(int vertex){
		this->v = vertex;
		this->adjList = new list<struct edge>[vertex];
		this->parent = new int[v];
		this->visited = new bool[v];
		this->dist = new int[v];
	}
	int * parent;
	int * dist;
	bool * visited;
	void addEdge(int s , int d , int w);
	void visitBFS();
	void visitDFS();
	void dijkstra(int src);
	void bellmanFord(int src);
};


class CompareEdge{
	public:
	bool operator () (const pair<int , int > & e1 , const pair<int , int > & e2){
		if(e1.second >= e2.second)
			return true;

		return false;
	}
};


void Graph::addEdge(int src ,int dest , int wt){
	struct edge e1,e2;
	e1.src = src;
	e1.dest = dest;
	e1.weight = wt;
	e2.src = dest;
	e2.dest = src;
	e2.weight = wt;
	adjList[src].push_back(e1);
	adjList[dest].push_back(e2);
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
		std::list<struct edge>::iterator itrList = this->adjList[m].begin();
		for( ; itrList!= this->adjList[m].end() ; itrList++ ){
			if(!visited[(*itrList).dest]){
				int a = (*itrList).dest;
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
		std::list<struct edge>::iterator itrList = this->adjList[m].begin();
		for( ; itrList!= this->adjList[m].end() ; itrList++ ){
			if(!visited[(*itrList).dest]){
				int a = (*itrList).dest;
				queue.push_back(a);
				visited[a] = true;
			}
		}

	}

}

void Graph::dijkstra(int src){

	//std::priority_queue<pair<int , int >  , vector<pair<int , int > > , CompareEdge> queue;

	std::set<pair<int , int> > myset;
	this->parent[src] = src;
	this->dist[src] = 0;

	std::pair<int , int> all_pair[v];
	for(int i=0 ; i< v ; i++){
		all_pair[i] = std::make_pair(dist[i] , i);
		myset.insert(all_pair[i]);
		//queue.push(all_pair[i]);
	}


	while(!myset.empty()){
	//for(int i=0 ; i< v ; i++){
		std::set<pair<int , int> >::iterator itr = myset.begin();
		//int d = itr->first;
		int v = itr->second;
		myset.erase(itr);
		std::list<struct edge>::iterator itrList = this->adjList[v].begin();
		for( ; itrList!= this->adjList[v].end() ; itrList++ ){
			int curr_dest = (*itrList).dest;
			int wt = (*itrList).weight;


			if(dist[curr_dest] > dist[v] + wt ){
				myset.erase(myset.find(pair<int , int>(dist[curr_dest]  , curr_dest)));
				dist[curr_dest] = dist[v] + wt;
				parent[curr_dest] = v;
				myset.insert(pair<int , int>(dist[curr_dest] , curr_dest));
			}
		}
	}
}


void Graph::bellmanFord(int src){

	for(int i=0 ; i< v ; i++){
		parent[i] = -1;
		dist[i] = 10000;
	}

	this->dist[src] = 0;
	this->parent[src] = src;

	list<edge> allEdges;
	for(int i=0; i< v ;i++){
		std::list<edge>::iterator itr = this->adjList[i].begin();
		while(itr != this->adjList[i].end()){
			allEdges.push_back(*itr);
			itr++;
		}
	}

	for(int i=0 ; i < v-1 ;i++){
		for(std::list<edge>::iterator itr = allEdges.begin() ; itr != allEdges.end() ; itr++){
				edge curr_edge = *itr;
				int src = curr_edge.src;
				int dest = curr_edge.dest;
				int wt = curr_edge.weight;
				if(dist[src]!= 10000 && dist[src] + wt <= dist[dest]){
					dist[dest] = dist[src] + wt;
					parent[dest] = src;
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
		int src,dest,wt;
		int e;
		infile>>e;
		for(int i=0 ; i<e ; i++){
			infile>>src>>dest>>wt;
			g.addEdge(src , dest , wt);
		}
		for(int i=0 ; i< v ; i++){
			g.visited[i] = false;
			g.parent[i] = -1;
			g.dist[i] = 100000;
		}

		g.visitBFS();
		cout<<endl;
		g.visitDFS();
		cout<<endl;

		g.dijkstra(0);
		cout<<"dijkstra output is "<<endl;
		for(int i=0 ; i< v ; i++){
			cout<<i<<'\t'<<g.parent[i]<<'\t'<<g.dist[i]<<endl;
		}

		g.bellmanFord(0);
		cout<<"bellman ford output is "<<endl;
		for(int i=0 ; i< v ; i++){
			cout<<i<<'\t'<<g.parent[i]<<'\t'<<g.dist[i]<<endl;
		}

	}
}



  incorrect
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
1
13
17
0 1
0 7
1 2
1 7
2 3
2 10
2 4
3 5
3 8
4 6
4 7
5 8
7 9
7 11
8 10
9 11
11 12

===============================

1
5
8
0 1 6
0 2 6
0 3 3
1 3 2
1 4 4
2 3 5
2 4 1
3 4 4

1
5
7
0 1 2
0 3 6
1 2 1
1 3 3
2 3 6
2 4 1
3 4 4

1
9
14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

*/
