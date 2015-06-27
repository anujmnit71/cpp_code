//============================================================================
// Name        : path.cpp
// Author      : anuj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include<cstdio>
#include <iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#define N 3
int count = 0;

void construct_candidate(int a[] , int k , int input , int c[] , int *pnc){
	int right = 0;
	int down = 0;
	*pnc = 0;
	for(int i=0 ; i< k ; i++){
		if(a[i] == 0)
			right++;
		if(a[i] == 1)
			down++;
	}

	if(right < input){
		c[*pnc] = 0;
		(*pnc) = *pnc + 1;
	}

	if(down < input){
		c[*pnc] = 1;
		(*pnc) = *pnc + 1;
	}

	return;
}

bool is_solution(int a[] , int k , int input){
	if( k == 2*input)
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
	count++;
}

void backtrack(int a[] , int k , int input){
	int c[2];
	int nc=0;

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

