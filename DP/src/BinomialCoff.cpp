/*
//============================================================================
// Name        : Binomial Cofficient.cpp
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


int count(int n , int r){
	if(r==0 || r==n)
		return 1;

	if(r>n){
		cout<<"Error";
		return -1;
	}

	int result = count(n-1 , r) + count(n -1 , r-1);

	return result;
}


int countDP(int n , int r){

	int table[n+1][r+1];

	n = n +1;
	r = r+1;

	cout<<"n is"<<n<<'\t'<<"r is"<<r<<endl;
	re(i , 0 , n){
			re(j , 0 , r){
				table[i][j] = 0;
		}
	}

	re(i , 0 , n){
		table[i][0] = 1;
	}

	re(i , 1 , n){
		re(j , 1 , r){
			if(j<=i)
				table[i][j] = table[i-1][j] + table[i-1][j-1];
		}
	}

	re(i , 0 , n){
			re(j , 0 , r){
				cout<<table[i][j]<<'\t';
		}
		cout<<endl;
	}

	return table[n-1][r-1];
}


int main(){
	int test =0;
	ifstream infile("ipDP");

	infile>>test;
	while(test--){
		int n,r;
		infile>>n>>r;

		cout<<"Count is				"<<count(n,r)<<endl;
		cout<<"Cost is					"<<countDP(n , r)<<endl;
	}
	return 0;
}


5
6 2
4 4
4 3
2 1
2 0

*/
