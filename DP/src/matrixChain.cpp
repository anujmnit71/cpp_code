/*
//============================================================================
// Name        : Matrix Chain.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>

#define re(i, l, r) for (int i=l; i<r; i++)
using namespace std;


int count(int S[],int i , int j){
	if(i == j)
		return 0;

	int c=0 , min =1000000;
	re(k , i , j){
		c = count(S, i , k) + count(S , k+1 ,j) + S[i-1]*S[k]*S[j];
		if(c<min)
			min = c;
	}

	return min;
}


int countDP(int S[],int n){
	int table[n][n]; // n is one more than no of matrices since {a,b,c} means matrices are aXb and bXc
	//cout<<"size of table is"<<sizeof(table)<<endl;
	re(i , 0 , n){
		re(j , 0 , n){
			table[i][j] = 0;
		}
	}


	re(i , 1 , n)
		table[i][i] = 0;

	re(L , 2 , n){
		re(i , 1 , n+1 -L+1){
			int j = i + L - 1;
			table[i][j] = 100000;
			re(k , i , j){
				int c  = table[i][k] + table[k+1][j] + S[i-1]*S[k]*S[j];
				if(c<table[i][j])
					table[i][j] = c;
			}
		}
	}

	re(i , 1 , n){
		re(j , 1 , n){
			cout<<table[i][j]<<'\t';
		}
		cout<<endl;
	}
}

int main(){
	int test =0;
	ifstream infile("ipDP");

	infile>>test;
	while(test--){
		int N; // N means there are N-1 matrices
		infile>>N;

		int matrix[N];

		re(i , 0 , N){
			infile>>matrix[i];
		}

		cout<<"Count is "<<count(matrix , 1 , N-1)<<endl;
		cout<<"Cost is "<<countDP(matrix , N)<<endl;
	}
	return 0;
}


5
5
10 20 30 40 30
3
10 20 30
5
40 20 30 10 30
2
10 20
7
30 35 15 5 10 20 25


*/
