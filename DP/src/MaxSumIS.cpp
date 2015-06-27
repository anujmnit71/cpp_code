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

typedef long long int lld;


lld LIS(lld arr[] , lld n){

	lld LISarr[n];
	lld parent[n];

	for(lld i=0 ; i<n ; i++){
		LISarr[i] = arr[i];
		parent[i] = -1;
	}
	lld maxval = 0;
	int index =0;
	for(lld i=0 ; i< n ;i++){
		for(lld j=0 ; j< i ; j++){
			if(arr[i] > arr[j] && LISarr[i] < LISarr[j] + arr[i]){
				LISarr[i] = LISarr[j] + arr[i];
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
		cout<<arr[curr]<<' ';
		curr = p;
		p = parent[curr];
	}
	cout<<arr[curr]<<' ';
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
		cout<<"Length is "<<LIS(arr , size)<<endl;
	}
	return 0;
}
*/

