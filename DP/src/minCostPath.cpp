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


int minCost(int** path,int pos1 , int pos2){

	if(pos1 < 0 || pos2 < 0){
		//cout<<"No path possible"<<endl;
		return 1000000;
	}
	if(pos1==0 && pos2 ==0)
		return path[pos1][pos2];

	else{
		return path[pos1][pos2] + std::min(std::min(minCost(path ,pos1-1 , pos2) , minCost(path ,pos1 , pos2-1))
				, minCost(path , pos1-1 , pos2-1) );

	}
}

int minCostDP(int** path, int m , int n){

	int cost[m][n];
	memset(cost , 0 , sizeof(int)*m*n);

	cost[0][0] = path[0][0];

	re(i,1,n){ // for columns
		cost[0][i] = path[0][i] + cost[0][i-1];
	}

	re(i,1,m){
			cost[i][0] = path[i][0] + cost[i-1][0];
	}

	re(i , 1 , m){
		re(j , 1 , n){
			cost[i][j] = path[i][j] + std::min(std::min(cost[i-1][j] , cost[i][j-1]) , cost[i-1][j-1]);
		}
	}

	re(i , 0 , m){
		re(j , 0 , n){
			cout<<cost[i][j]<<'\t';
		}
		cout<<endl;
	}
}

int main(){
	int test =0,size1 , size2 , m , n;
	ifstream infile("ipDP");

	infile>>test;
	while(test--){
		infile>>size1>>size2;
		int** path;
		path = (int** )malloc(sizeof(int*)*size1);//[size1][size2];// = (int **)malloc(sizeof(int)* size1 * size2);

		re(i , 0 , size1){
			path[i] = (int*)malloc(sizeof(int)*size2);
		}

		re(i , 0 , size1){
			re(j , 0 , size2){
				infile>>path[i][j];
			}
		}

		infile>>m>>n;
		re(i , 0 , size1){
			re(j , 0 , size2){
				cout<<path[i][j]<<'\t';
			}
			cout<<endl;
		}
		cout<<"Cost is "<<minCost(path , m , n )<<endl;
		minCostDP(path , size1 , size2 );
		//cout<<"Cost is "<<editDistanceDP(arr1 , arr2 , size1 , size2)<<endl;
	}
	return 0;
}


1
3 3
1 2 3
4 8 2
1 5 3
2 2

*/
