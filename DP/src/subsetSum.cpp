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

bool subsetSum(int arr[] , int n , int sum){
	if(sum == 0)
		return true;

	if(n == 0 && sum!=0)
		return false;

	if(arr[n-1] > sum)
		return subsetSum(arr , n-1 , sum);

	return subsetSum(arr , n-1 , sum)||subsetSum(arr , n-1 , sum - arr[n-1]);
}



int subsetSumDP(int arr[] , int n , int sum){

	bool tableDP[n+1][sum+1];
	re(i , 0 , n+1)
		re(j , 0 , sum+1)
			tableDP[i][j] = false;

	re(i , 0 , sum+1)
		tableDP[0][i] = false;

	re(i , 0 , n+1)
			tableDP[i][0] = true;

	re(i , 1 , n+1){
		re(j , 1 , sum+1){
			if(arr[i-1] > j)
				tableDP[i][j] = tableDP[i-1][j];
			else{
				tableDP[i][j] = tableDP[i-1][j] || tableDP[i-1][j-arr[i-1]];
			}

		}
	}

	return tableDP[n][sum];
}




int main(){
	int test =0,size;
	ifstream infile("ipDP");

	infile>>test;
	while(test--){
		infile>>size;
		int arr[size] ;
		for(int i=0 ; i<size ; i++){
			infile>>arr[i];
		}
		int sum = 0;
		re(i , 0 , size)
			sum+= arr[i];
		if(sum%2 == 0){
			cout<<"Count is "<<subsetSum(arr , size , sum/2)<<endl;
			cout<<"CountDP is "<<subsetSumDP(arr ,  size , sum/2)<<endl;
		}
		else
			cout<<"Not possible"<<endl;
		//cout<<"CountDP is "<<palindDP(arr1 ,  0 , size1)<<endl;
		//cout<<"Count is "<<LPSDP(arr1 ,  0 , size1-1)<<endl;
	}
	return 0;
}


*/
