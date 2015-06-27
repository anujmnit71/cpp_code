//============================================================================
// Name        : stringgraph.cpp
// Author      : anuj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
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
#include<map>

using namespace std;

//static int count = 0;

struct vertex{
	string name;
	list<pair<string , int> > adjList;
};
class Graph{
	map<string , vertex> mymap;

public :
	void addEdge(const string& src , const string& dest , int wt);
	void addVertex(const string &str);
	void visitBFS();
};

void Graph::addVertex(const string& str){
	struct vertex v;
	v.name = str;
	map<string , vertex>::iterator itr = mymap.begin();
	itr = mymap.find(v.name);
	if(itr == mymap.end())
		mymap[v.name] = v;
	//else
		//cout<<itr->first<<"present"<<endl;
}


void Graph::addEdge(const string &src , const string &dest , int wt){
	std::map<string , vertex>::iterator itrSrc = mymap.begin();
	itrSrc = mymap.find(src);
	itrSrc->second.adjList.push_back(std::make_pair(dest , wt));
}

void Graph::visitBFS(){
	string src = mymap.begin()->first;
	map<string,bool > visited;
	list<string> queue;

	for(map<string , vertex>::iterator itr =mymap.begin() ; itr != mymap.end() ; itr++){
		visited[itr->first] = false;
	}
	queue.push_back(src);
	visited[src] = true;

	while(!queue.empty()){
		std::list<string>::iterator itr = queue.begin();
		queue.pop_front();
		string m = *itr;
		//visited[m] = true;
		cout<<m<<' ';
		std::list<pair<string,int> >::iterator itrList = mymap[m].adjList.begin();
		for( ; itrList!= mymap[m].adjList.end() ; itrList++ ){
			if(!visited[itrList->first]){
				string a = itrList->first;
				queue.push_back(a);
				visited[a] = true;
			}
		}

	}

}


int main() {
	int test;
	ifstream infile("ipGraph");
	infile>>test;

	while(test--){
		Graph g;
		int e,wt;
		string src,dest;
		infile>>e;
		for(int i=0 ; i<e ; i++){
			infile>>src>>dest>>wt;
			cout<<src<<'\t'<<dest<<'\t'<<wt<<endl;
			g.addVertex(src);
			g.addVertex(dest);
			g.addEdge(src , dest , wt);
		}

		g.visitBFS();
		/*g.visitBFS();
		cout<<endl;
		g.visitDFS();
		cout<<endl;
		g.topologicalSort();
		g.AP();
*/
	}
}


