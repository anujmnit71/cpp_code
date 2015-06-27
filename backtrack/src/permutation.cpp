/*
//============================================================================
// Name        : permutation.cpp
// Author      : anuj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<cstdio>
#include <iostream>
using namespace std;
#define MAXCANDIDATE 3

void construct_candidate(int a[] , int k , int input , int c[] , int *pnc){
	*pnc = input - k;
	int iplist[input] ;
	for(int i =0 ; i<input ; i++){
		iplist[i] = 1;
	}

	for(int i=0 ; i< k ; i++){
		iplist[a[i]-1]--;
	}
	int m=0;
	for(int i=0 ; i<input ; i++){
		if(iplist[i] == 1){
			c[m] = i+1;
			m++;
		}
	}
	return;
}

bool is_solution(int a[] , int k , int input){
	if( k == input)
		return true;
	else
		return false;
}

void process_solution(int a[] , int k){
	printf("{");
	for(int i=0 ; i<k ; i++){
			printf("%d,", a[i]);
	}
	printf("}\n");
}

void backtrack(int a[] , int k , int input){
	int c[MAXCANDIDATE];
	int nc;

	if(is_solution(a,k,input)){
		process_solution(a,k);
	}
	else{
		//k = k + 1;
		construct_candidate(a , k , input , c , &nc);
		for(int i=0 ; i < nc ; i++){
			a[k] = c[i];
			backtrack(a,k+1,input);

		}

	}
}


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int n = 3;
	int a[n];

	backtrack(a , 0 , n);
	return 0;
}
*/
