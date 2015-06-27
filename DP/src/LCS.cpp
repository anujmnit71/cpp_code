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


using namespace std;

int LCS(char arr1[] , char arr2[] , int m , int n){
	if(n == 0 || m==0)
		return 0;
	int common = 0;

	if(arr1[m-1] == arr2[n-1])
		return 1 + LCS(arr1 , arr2 , m-1 , n-1);
	common = std::max(std::max(LCS(arr1 , arr2 , m-1 , n) , LCS(arr1 , arr2 , m , n-1)), LCS(arr1 , arr2 , m-1 , n-1));

	return common;
}

int LCSI(char arr1[] , char arr2[] , int m , int n){

	int L[m+1][n+1];

	for(int i =0 ; i<= m ; i++)
		L[i][0] = 0;

	for(int i =0 ; i<= n ; i++)
		L[0][i] = 0;

	for(int i =1 ; i<= m ; i++){
		for(int j =1 ; j<= n ; j++){
			if(arr1[i] == arr2[j])
				L[i][j] = 1 + L[i-1][j-1];
			else{
				L[i][j] = std::max(L[i-1][j] , L[i][j-1]);
			}
		}

	}
	return L[m][n];
}

int main(){
	int test =0,size1 , size2;
	ifstream infile("ipDP");

	infile>>test;
	while(test--){
		infile>>size1>>size2;
		char arr1[size1] , arr2[size2];
		for(int i=0 ; i<size1 ; i++){
			infile>>arr1[i];
		}

		for(int i=0 ; i<size2 ; i++){
			infile>>arr2[i];
		}

		cout<<"Cost is "<<LCS(arr1 , arr2 , size1 , size2)<<endl;
		cout<<"Cost is "<<LCSI(arr1 , arr2 , size1 , size2)<<endl;
	}
	return 0;
}


1
6 7
a g g t a b
g x t x a y b

*/
