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
#include<cstdlib>
#include<cstring>

typedef long long int lld;

#define re(i, l, r) for (int i=l; i<r; i++)
using namespace std;


lld incSeq[100];
lld decSeq[100];


lld LDS(lld arr[] , lld n){

	lld LDSarr[n];
	lld parent[n];

	for(lld i=0 ; i<n ; i++){
		LDSarr[i] = 1;
		decSeq[i] = 1;
		parent[i] = -1;
	}
	lld maxval = 1;
	int index =0;
	for(lld i=n-2 ; i>= 0 ;i--){
		for(lld j=n-1 ; j >i ; j--){
			if(arr[i] > arr[j] && LDSarr[i] < LDSarr[j] + 1){
				LDSarr[i] = LDSarr[j] + 1;
				decSeq[i] = decSeq[i] + 1;
				parent[i] = j;
				maxval = std::max(maxval , LDSarr[i]);
				if(maxval == LDSarr[i])
					index = i;
			}
		}

	}
	int curr = index;
	int p = parent[curr];

	//cout<<"LIS is"<<endl;
	while(p != -1){
		cout<<arr[curr]<<' ';
		curr = p;
		p = parent[curr];
	}
	cout<<arr[curr]<<' ';
	cout<<endl;
	return maxval;
}




lld LIS(lld arr[] , lld n){

	lld LISarr[n];
	lld parent[n];

	for(lld i=0 ; i<n ; i++){
		LISarr[i] = 1;
		incSeq[i] = 1;
		parent[i] = -1;
	}
	lld maxval = 1;
	int index =0;
	for(lld i=0 ; i< n ;i++){
		for(lld j=0 ; j< i ; j++){
			if(arr[i] > arr[j] && LISarr[i] < LISarr[j] + 1){
				LISarr[i] = LISarr[j] + 1;
				incSeq[i] = incSeq[j] + 1;
				parent[i] = j;
				maxval = std::max(maxval , LISarr[i]);
				if(maxval == LISarr[i])
					index = i;
			}
		}

	}
	int curr = index;
	int p = parent[curr];

	//cout<<"LIS is"<<endl;
	while(p != -1){
		//cout<<arr[curr]<<' ';
		curr = p;
		p = parent[curr];
	}
	//cout<<arr[curr]<<' ';
	cout<<endl;
	return maxval;
}

int main(){
	int test =0,size;
	ifstream infile("ipDP");

	infile>>test;
	while(test--){
		infile>>size;
		lld arr[size];
		for(lld i=0 ; i<size ; i++){
			infile>>arr[i];
		}
		cout<<"Length of LIS is "<<LIS(arr , size)<<endl;
		cout<<"Length of LDS is "<<LDS(arr , size)<<endl;

		re(i , 0 , size)
			cout<<incSeq[i]<<'\t';
		cout<<endl;
		re(i , 0 , size)
			cout<<decSeq[i]<<'\t';


	}
	return 0;
}




5
7
1 101 2 3 100 4 5
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
8
1 11 2 10 4 5 2 1
6
12 11 40 5 3 1
6
80 60 30 40 20 10

*/
