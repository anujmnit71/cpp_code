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
#include<climits>

#define re(i, l, r) for (int i=l; i<r; i++)
using namespace std;

int eggtable[100][100] = {-1};

int countDPMemoization(int f , int e){

	if(e==1)
		return f;

	if(f==1 || f==0)
		return f;

	if(eggtable[f][e] >=0)
		return eggtable[f][e];

	int min = INT_MAX;
	int c = 0;
	//test for all possible floors from
	for(int k = 1 ; k<=f ; k++){
		c = 1 + std::max(countDPMemoization(k-1,e-1) , //if egg breaks test remaining k-1 with e-1 eggs
				countDPMemoization( f-k , e ));// if egg doesn't break then test remaining f-k with e eggs
					//c);
		if(c < min )
				min = c;
	}
	eggtable[f][e] = min;
	return min;
}



int eggDropDP(int nFloors , int nEggs){
	int tableDP[nEggs+1][nFloors+1]; //N items

	memset(tableDP , 0 , sizeof(tableDP));

	re(i , 0 , nEggs+1){
		tableDP[i][0] = 0;
		tableDP[i][1] = 1;// if only one floor
	}

	re(i , 0 , nFloors+1){
		tableDP[0][i] = 0;
		tableDP[1][i] = i; // if one egg then linear search
	}

	re(i , 2 , nEggs+1){
		re(j , 2 , nFloors+1){
			tableDP[i][j] = INT_MAX;
			int c;
			re(k , 2 , j+1){
				c = 1 + std::max( tableDP[i-1][k-1] , tableDP[i][j-k]);

				if(tableDP[i][j] > c)
					tableDP[i][j] = c;
			}
			//table[i][j] = std::min(c , table[i][j]);
		}

	}


	return tableDP[nEggs][nFloors];
}


int eggDrop(int n, int k)
{
     A 2D table where entery eggFloor[i][j] will represent minimum
       number of trials needed for i eggs and j floors.
    int eggFloor[n+1][k+1];
    int res;
    int i, j, x;

    // We need one trial for one floor and0 trials for 0 floors
    for (i = 1; i <= n; i++)
    {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }

    // We always need j trials for one egg and j floors.
    for (j = 1; j <= k; j++)
        eggFloor[1][j] = j;

    // Fill rest of the entries in table using optimal substructure
    // property
    for (i = 2; i <= n; i++)
    {
        for (j = 2; j <= k; j++)
        {
            eggFloor[i][j] = INT_MAX;
            for (x = 1; x <= j; x++)
            {
                res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
                if (res < eggFloor[i][j])
                    eggFloor[i][j] = res;
            }
        }
    }

    // eggFloor[n][k] holds the result
    return eggFloor[n][k];
}

int main(){
	int test =0;
	ifstream infile("ipDP");

	infile>>test;
	while(test--){
		int nFloors ,nEggs;
		infile>>nFloors>>nEggs;

		re(i , 0 , nEggs){
			eggtable[0][i] = 0;
			eggtable[1][i] = 1;
		}

		re(i , 0 , nFloors){
			eggtable[i][1] =  i;
		}

		re(a , 0 , nFloors+1){
			re(b , 0 , nEggs+1){
				eggtable[a][b] = -1;
			}
		}

		cout<<"Count using copied version is "<<eggDrop(nEggs ,nFloors)<<endl;
		cout<<"Count using countDPMemoization is "<<countDPMemoization(nFloors , nEggs)<<endl;
		cout<<"Count using countDP is "<<eggDropDP(nFloors , nEggs)<<endl;


	}
	return 0;
}


3
10 2
10 4
36 2

*/
