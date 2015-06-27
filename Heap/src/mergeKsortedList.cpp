/*
//============================================================================
// Name        : recursion.cpp
// Author      : anuj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>

#define K 3

using namespace std;

class Node{

public:
	int val;
	Node* next;
};

class CompareNode{
	public:
	bool operator () (const Node& t1 , const Node& t2){
		if(t1.val >= t2.val)
			return true;

		return false;
	}
};


int main() {
	int test,size,element;
	vector<Node> klists[K];

	ifstream infile("ip");
	if(infile)
		cout<<"success";
	infile>>test;
	infile>>size;
	Node nodes[K*size];


	int m=0;

	while(test--){
		// read all the lists in klists vector
		for(int i=0 ; i<K ; i++){
			for(int j=0 ; j<size ; j++){
				infile>>element;
				nodes[m].val = element;
				nodes[m].next = &nodes[m+1];
				klists[i].push_back(nodes[m]);
				m++;
			}
			nodes[m-1].next = NULL;
		}

		//sort using heap

		std::priority_queue<Node , vector<Node> , CompareNode> queue;
		for(int i =0 ; i< K ; i++){
			queue.push(klists[i].at(0));
		}

		while(!queue.empty()){
			Node temp =queue.top();
			cout<<temp.val<<'\t';
			queue.pop();
			if(temp.next != NULL)
				queue.push(*(temp.next));
		}

	}
	return 0;
}
*/
