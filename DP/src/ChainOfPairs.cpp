/*
//============================================================================
// Name        : LIS.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>


using namespace std;


int chainPair(pair<int , int> chain[] , int n){

	int LISarr[n];
	int parent[n];

	for(int i=0 ; i<n ; i++){
		LISarr[i] = 1;
		parent[i] = -1;
	}
	int maxval = 0;
	int index =0;
	for(int i=1 ; i< n ;i++){
		for(int j=0 ; j< i ; j++){
			if(chain[i].first > chain[j].second && LISarr[i] < LISarr[j] + 1){
				LISarr[i] = LISarr[j] + 1;
				parent[i] = j;
				maxval = std::max(maxval , LISarr[i]);
				if(maxval == LISarr[i])
					index = i;
			}
		}

	}
	int curr = index;
	int p = parent[curr];

	cout<<"LIS is"<<endl;
	while(p != -1){
		cout<<"{"<<chain[curr].first<<","<<chain[curr].second<<"}"<<' ';
		curr = p;
		p = parent[curr];
	}
	cout<<"{"<<chain[curr].first<<","<<chain[curr].second<<"}"<<' ';
	cout<<endl;
	return maxval;
}

int main(){
	int test =0,size;
	ifstream infile("ipDP");

	infile>>test;
	while(test--){
		infile>>size;
		pair<int , int> chain[size];
		for(int i=0 ; i<size ; i++){
			int a,b;
			infile>>a>>b;
			chain[i] = std::make_pair(a,b);
		}
		cout<<"Length is "<<chainPair(chain , size)<<endl;
	}
	return 0;
}


1
5
5 24
39 60
15 28
27 40
50 90

*/
