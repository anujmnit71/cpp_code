/*

//============================================================================
// Name        : LIS.cpp
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



 *
 *
int LPS(char str[] , int m , int n){

	if( m == n)
		return 1;
	if( n == m+1 && str[m] == str[n])
		return 2;

	if(str[m] == str[n]){
		return 2 + LPS(str , m+1 , n-1);
	}
	else
		return std::max(LPS(str , m+1 , n) , LPS(str , m , n-1));
}

int table[100][100];

int LPSDPMemo(char str[] , int m , int n){

	if(table[m][n] >=0)
		return table[m][n];

	int c = -1;
	if(str[m] == str[n] ){
		if(n == m+1)
			c = 2;
		else
			c = 2 + LPS(str , m+1 , n-1);
	}
	else
		c = std::max(LPS(str , m+1 , n) , LPS(str , m , n-1));

	table[m][n] = c;
	return c;
}

int LPSDP(char str[] , int m , int n){

	int tableDP[n+1][n+1];

	re(i , 0 , n+1)
		tableDP[i][i] = 1;

	re(L , 2 , n+2){
		re( i , 0 , n - L + 2){
			int j = i + L -1;
			if(str[i] == str[j]){
				if(L == 2){
					tableDP[i][j] = 2;
				}
				else
					tableDP[i][j] = 2 + tableDP[i+1][j-1];
			}
			else{
				tableDP[i][j] = std::max(tableDP[i+1][j] , tableDP[i][j-1]);
			}
		}
	}
	return tableDP[m][n];
}

int main(){
	int test =0,size1 ;
	ifstream infile("ipDP");

	infile>>test;
	while(test--){
		infile>>size1;
		char arr1[size1] ;
		for(int i=0 ; i<size1 ; i++){
			infile>>arr1[i];
		}

		re(i , 0 , size1)
			re(j , 0 , size1)
				table[i][j] = -1;

		re(i , 0 , size1)
			table[i][i] = 1;


		cout<<"Count of LPS is "<<LPS(arr1 ,  0 , size1-1)<<endl;
		cout<<"Count of LPSMemo is "<<LPSDPMemo(arr1 ,  0 , size1-1)<<endl;
		cout<<"Count of LPSDP is "<<LPSDP(arr1 ,  0 , size1-1)<<endl;
	}
	return 0;
}



4
4
abba
2
ab
2
aa
13
GEEKSFORGEEKS
 *




*/
