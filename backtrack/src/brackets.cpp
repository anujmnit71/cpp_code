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
#include<cmath>
using namespace std;
#define N 6

int count = 0;

void construct_candidate(int a[] , int k , int input , int c[] , int *pnc){
	*pnc = 0;
	int lcount = 0;
	int rcount = 0;

	for(int i=0 ; i<k  ; i++){
			if(a[i] == 0)
				lcount++;
			if(a[i] == 1)
				rcount++;
	}
	if( lcount < input/2 ){
		c[*pnc] = 0;
		*pnc = *pnc + 1;
	}
	if(rcount < lcount){
		c[*pnc] = 1;
		*pnc = *pnc + 1;
	}

}

bool is_solution(int a[] , int k , int input){
	return ( k == input);
}

void process_solution(int a[] , int k){
	for(int i=0 ; i<k ; i++){
		if(a[i] == 0)
			printf("(");
		else
			printf(")");
	}
	printf("\n");
	count++;
}

void backtrack(int a[] , int k , int input){
	int c[input];
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
	count = 0;
	int a[N];
	backtrack(a , 0 , N);
	cout<<count<<endl;
	return 0;
}

*/
