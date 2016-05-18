/*
see leetcode for solution


//============================================================================
// Name        : linked_list.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include <sstream>

#define SIZE 100

using namespace std;

public class Solution {

    void dfs(char[][] grid , int row , int col , int M , int N){

            grid[row][col] = '0';

            //up
            if(row > 0 && grid[row - 1][col] == '1'){
                dfs(grid , row - 1 , col , M , N);
            }

            //right
            if(col + 1 < N && grid[row][col+1] == '1'){
                dfs(grid , row  , col + 1 , M , N);
            }

            //down
            if(row + 1 < M && grid[row + 1][col] == '1'){
                dfs(grid , row + 1 , col , M , N);
            }

            //left
            if(col > 0 && grid[row][col - 1] == '1'){
                dfs(grid , row  , col - 1 , M , N);
            }

    }

    public int numIslands(char[][] grid) {
        if (grid==null || grid.length==0 || grid[0].length==0)
            return 0;

        int count = 0;

        for(int i = 0 ; i < grid.length ; i++){
            for(int k = 0 ; k < grid[0].length ; k++){
                if(grid[i][k] == '0')
                    continue;

                dfs(grid , i , k , grid.length , grid[0].length);
                count++;
            }
        }
        return count;
    }
}
int main(){
	int test,size,element;
	ifstream infile("ipLeetCode");
	if(infile)
//		cout<<"success";
	infile>>test;

	while(test--){
		Solution s;
		vector<vector<int> > grid;
		int a , b , element;

		infile>>a>>b;
		for(int i = 0 ; i < a ; i++){
			vector<int> rowVec;
			for(int j = 0 ; j < b ; j++){
				infile>>element;
				rowVec.push_back(element);
			}
			grid.push_back(rowVec);
		}

		for(int i = 0 ; i < a ; i++){
			for(int j = 0 ; j < b ; j++){
				cout<<grid[i][j]<<'\t';
			}
			cout<<endl;
		}

		cout<<s.numIslands(grid)<<endl;
	}
	return 0;
}
*/
