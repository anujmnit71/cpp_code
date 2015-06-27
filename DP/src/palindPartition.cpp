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
#include<climits>

#define re(i, l, r) for (int i=l; i<r; i++)

using namespace std;



#include <iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>

typedef long long int lld;

#define re(i, l, r) for (int i=l; i<r; i++)


int isPalind(char str[] , int m , int n){
	if(m == n)
		return 1;
	if(str[m] == str[n])
		return isPalind(str , m+1 , n-1);
	else
		return 0;
}


int palind(char str[] , int m , int n){

	if( isPalind(str , m , n))
		return 0;

	int c = 0 , min =1000;
	for(int k=m ; k < n; k++){
		c = 1 + palind(str , m , k) // string of index [m,k]
				+ palind( str , k+1  , n); // string of index [k+1,n]
		if(c < min)
			min = c;

	}
	return min;
}


int palindDP(char str[] , int m , int n){ //n is 4 for "abcd"

	int tableDP[n][n];
	re(i , 0 , n)
		re(j , 0 , n)
			tableDP[i][j] = 10000;// strings of length 1 are palindrome

	re(i , 0 , n) // strings of length 1 are palindrome
		tableDP[i][i] = 0;

	re(L , 2 , n+1){
		re( i , 0 , n - L + 1){
			int j = i + L -1;
			if(isPalind(str ,i,j))
				tableDP[i][j] = 0;
			else{
				tableDP[i][j] = INT_MAX;
				int c = 0;
				re(k , i , j){
					c = 1 + tableDP[i][k] + tableDP[k+1][j];
					if(c < tableDP[i][j])
						tableDP[i][j] = c;
				}
			}


		}
	}

	re(i , 0 , n){
		re(j , 0 , n){
			cout<<tableDP[i][j]<<'\t'<<'\t';
		}
		cout<<endl;
	}
	return tableDP[m][n-1];
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

		//re(i , 0 , size1)
			//cout<<arr1[i]<<'\t';
		cout<<"Count is "<<palind(arr1 ,  0 , size1-1)<<endl;
		cout<<"CountDP is "<<palindDP(arr1 ,  0 , size1)<<endl;
		//cout<<"Count is "<<LPSDP(arr1 ,  0 , size1-1)<<endl;
	}
	return 0;
}


*/
