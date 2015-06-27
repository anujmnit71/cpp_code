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

lld LISRec(lld arr[] , lld n){

	lld maxval = 1;

	for(lld i=1 ; i< n ;i++){
		int res = LISRec(arr , i);
		if(arr[i-1] < arr[n-1] && maxval < res+1){
			maxval = res + 1;
		}
	}
	return maxval;
}


lld LIS(lld arr[] , lld n){

	lld LISarr[n];
	lld parent[n];

	for(lld i=0 ; i<n ; i++){
		LISarr[i] = 1;
		parent[i] = -1;
	}
	lld maxval = 0;
	int maxindex =0;
	for(lld i=1 ; i< n ;i++){
		for(lld j=0 ; j< i ; j++){
			if(arr[i] > arr[j] && LISarr[i] < LISarr[j] + 1){
				LISarr[i] = LISarr[j] + 1;
				parent[i] = j;
				maxval = std::max(maxval , LISarr[i]);
				if(maxval == LISarr[i])
					maxindex = i;
			}
		}

	}
	int curr = maxindex;
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
		cout<<"Length is rec "<<LISRec(arr , size)<<endl;
	}
	return 0;
}

*/
