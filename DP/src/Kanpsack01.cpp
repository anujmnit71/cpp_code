/*
//============================================================================
// Name        : coinChange.cpp
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



int count(int val[], int wt[] , int N , int W){
	int c = 0;

	if(N == 0 || W == 0)
		return 0;

	if(wt[N-1] >W)
		return count(val , wt , N-1 , W) ;

	c = std::max(count(val , wt , N-1 , W) , //not taking mth coin
			val[N-1] + count(val , wt , N-1 , W - wt[N-1]));//taking mth coin

	return c;
}





int countDP(int val[], int wt[] , int N , int W){
	int table[N+1][W+1]; //N items

	memset(table , 0 , sizeof(table));

	re(i , 0 , N+1)
		table[i][0] = 0;

	re(i , 0 , W+1)
			table[0][i] = 0;

	re(i , 1 , N+1){
		re(j , 1 , W+1){
			if(wt[i-1] > j){
				table[i][j] = table[i-1][j];
				continue;
			}
			table[i][j] = std::max(table[i-1][j-wt[i-1]] + val[i-1] , table[i-1][j]);

		}
	}

	re(i , 0 , N+1){
		re(j , 0 , W+1){
			cout<<table[i][j]<<'\t';
		}
		cout<<endl;
	}
	return table[N][W];
}




int main(){
	int test =0;
	ifstream infile("ipDP");

	infile>>test;
	while(test--){
		int nItems , W;
		infile>>nItems;

		int val[nItems];
		int wt[nItems];

		re(i , 0 , nItems){
			infile>>val[i];
		}
		re(i , 0 , nItems){
			infile>>wt[i];
		}

		infile>>W;

		cout<<"Count is "<<count(val , wt , nItems , W)<<endl;
		cout<<"Cost is "<<countDP(val , wt , nItems , W)<<endl;
	}
	return 0;
}


2
4
3 4 5 8
2 3 4 5
20
5
3 4 5 8 10
2 3 4 5 9
20



*/
