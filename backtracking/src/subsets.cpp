/*
//============================================================================
// Name        : backtrack.cpp
// Author      : anuj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<cstdio>
#include <iostream>
using namespace std;
#define MAXCANDIDATE 2

void construct_candidate(int a[] , int k , int input , int c[] , int *pnc){
	c[0] = 1;
	c[1] = 0;
	*pnc = 2;
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
		if(a[i] == 1)
			printf("%d,", i+1);
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
