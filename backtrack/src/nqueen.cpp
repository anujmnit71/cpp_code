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
#define N 20

int count = 0;

void construct_candidate(int a[] , int k , int input , int c[] , int *pnc){
	for(int i=0 ; i< input ; i++){
		c[i] = i;
	}

	*pnc = 0;

	for(int i=0 ; i<input  ; i++){
		bool legal = true;
		for(int m=0 ; m<k ; m++){
			if(a[m] == i)
				legal = false;
			if(abs(a[m] - i) == abs(k - m))// check for diagonal collision abs( row_curr(k) - row_prev(m) ) == abs(col_curr(i) - col_prev( a[row_prev i.e. m] ) )
				legal = false;
		}
		if(legal == true){
			c[*pnc] = i;
			*pnc = *pnc + 1;
		}
	}
}

bool is_solution(int a[] , int k , int input){
	if( k == input)
		return true;
	else
		return false;
}

void process_solution(int a[] , int k){
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
	//int n = 8;
	for(int i = 1 ; i< 20 ; i++){
		count = 0;
		int a[i];// = {-1,-1,-1,-1,-1,-1,-1,-1};  // Each entry of a[i]  denotes the column of queen in ith row

		backtrack(a , 0 , i);
		cout<<i<<'\t';
		cout<<count<<endl;
	}
	return 0;
}
*/
