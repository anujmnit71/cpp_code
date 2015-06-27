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


int count(int S[],int m , int N){
	int c = 0;
	if(N == 0)
		return 1;
	if(N < 0)
		return 0;
	if(m<= 0 && N >0)
		return 0;


	c = count(S , m-1 , N) + //not taking mth coin
		count(S , m ,N - S[m-1]);//taking mth coin
	return c;
}


int countDP(int S[],int m , int N){
	int table[N+1][m]; //m coins

	memset(table , 0 , sizeof(table));

	re(i , 0 , m)
		table[0][i] = 1;

	re(i , 1 , N+1){
		re(j , 0 , m){
			int x = 0 , y=0;
			//taking jth coin
			if(i - S[j] >= 0)
				x = table[i - S[j]][j];
			//not taking jth coin
			if(j >= 1)
				y = table[i][j-1];

			table[i][j] = x + y;

		}
	}

	re(i , 0 , N+1){
		re(j , 0 , m){
			cout<<table[i][j]<<'\t';
		}
		cout<<endl;
	}
	return table[N][m-1];
}

int main(){
	int test =0;
	ifstream infile("ipDP");

	infile>>test;
	while(test--){
		int ncoins , N;
		infile>>ncoins;

		int coins[ncoins];

		re(i , 0 , ncoins){
			infile>>coins[i];
		}

		infile>>N;

		cout<<"Count is "<<count(coins , ncoins , N)<<endl;
		cout<<"Cost is "<<countDP(coins , ncoins , N)<<endl;
	}
	return 0;
}


3
3
1 2 3
4
4
2 5 3 6
10
1
1
1

*/
