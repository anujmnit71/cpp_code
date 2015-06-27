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

int cutRod(int arr[] , int n){
	if(n == 0)
		return 0;
	int q = 0;
	for(int i=0 ; i<n ; i++){
		q = std::max(q , arr[i] + cutRod(arr , n-i-1));

	}
	return q;
}

int cutRodI(int arr[] , int n , int r[]){
	if(n == 0)
		return 0;
	int q = 0;

	if(r[n - 1] >= 0)
		return r[n - 1];
	else{
		q = 0;
		for(int i=0 ; i<n ; i++){
			q = std::max(q , arr[i] + cutRodI(arr , n-i-1 , r));
		}
	}
	r[n-1] = q;
	return q;

}

int cutRodBU(int arr[] , int n){
	int r[n+1];
	//r[0] = 0; it stores the maximum revenue of length 1 rod so cant be zero
	int q = 0;
	r[0] = 0;

	for(int i = 1 ; i < n + 1; i++){
		q = 0;
		for(int j = 0 ; j < i ; j++){
			q = std::max( q , arr[j] + r[i-j-1]);
		}
		r[i] = q;
	}

	cout<<endl<<"Bottom up"<<endl;
	for(int j = 0 ; j < n+1 ; j++){
		cout<<r[j]<<' ';
	}

	return r[n];

}


int main(){
	int test =0,size;
	ifstream infile("ipDP");

	infile>>test;
	while(test--){
		infile>>size;
		int arr[size];
		int r[size];
		for(int i=0 ; i<size ; i++){
			infile>>arr[i];
			r[i] = -100;
		}
		cout<<"Cost is "<<cutRod(arr , size)<<endl;
		cout<<"Cost is "<<cutRodI(arr , size , r)<<endl;

		cout<<"Top down"<<endl;
		for(int j = 0 ; j < size ; j++){
			cout<<r[j]<<' ';
		}

		cout<<"Cost is "<<cutRodBU(arr , size)<<endl;
	}
	return 0;
}


1
10
1 5 8 9 10 17 17 20 24 30


*/
