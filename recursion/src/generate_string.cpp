/*
//============================================================================
// Name        : recursion.cpp
// Author      : anuj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<cstdio>
#include <iostream>
using namespace std;

#define N 2
int a[N];
int k = 4;
int count = 0;

void generate(int n){
	if(n<=0){
		for(int i=0 ; i< N ; i++){
			cout<<a[i]<<'\t';
		}
		count++;
		cout<<endl;
		return;
	}
	for(int i=0 ; i<k ; i++){
		a[n-1] = i;
		generate(n-1);
	}
	return;
}


int main() {
	int n =N;
	generate(n);
	cout<<count;
	return 0;
}
*/
