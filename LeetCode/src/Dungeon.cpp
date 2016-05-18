/*
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
#include<map>
#include<cstring>
#define SIZE 100

using namespace std;


class Solution {
public:
	// Exponential solution therefore time limit exceeded
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int curr_sum = 0;
        int curr_min = 10000;
        int all_max_of_min = -10000;
        cal(dungeon , 0  , 0 , curr_sum , curr_min , all_max_of_min );
        int ans = all_max_of_min;
        return all_max_of_min + 1;

    }

    void cal(vector<vector<int> > &dungeon , int left , int down , int curr_sum , int curr_min , int &all_max_of_min ){
    	if(all_max_of_min > curr_min)
    		return;

        if(left == dungeon[0].size() -1 ){
        	for(int i = down ; i < dungeon.size() ; i++){
        		curr_sum = curr_sum + dungeon[i][left];
        		if(curr_min > curr_sum)
        			curr_min = curr_sum;
        	}
            if(all_max_of_min < curr_min)
                all_max_of_min = curr_min;
            //cout<<"left\t"<<curr_sum<<endl;
            return;
        }

        if(down == dungeon.size() -1 ){
			for(int i = left ; i < dungeon[0].size() ; i++){
				curr_sum = curr_sum + dungeon[down][i];
				if(curr_min > curr_sum)
					curr_min = curr_sum;
			}
			if(all_max_of_min < curr_min)
				all_max_of_min = curr_min;
			//cout<<"down\t"<<curr_sum<<endl;
			return;
		}

        curr_sum = curr_sum + dungeon[down][left];
        if(curr_min > curr_sum)
        	curr_min = curr_sum;

        cal(dungeon , left+1 , down , curr_sum , curr_min , all_max_of_min );
        cal(dungeon , left , down+1 , curr_sum , curr_min , all_max_of_min );

    }
};


int main(){
	int test,size,element;
	ifstream infile("ipLeetCode");
	if(infile)
//		cout<<"success";
	infile>>test;
	while(test--){
		Solution s;
		int row , col;
		infile>>row>>col;
		vector<vector<int> > dungeon;
		int element;
		for(int i =0 ; i< row ; i++){
			vector<int> curr_row;
			for(int j = 0 ; j< col ; j++){
				infile>>element;
				curr_row.push_back(element);
			}
			dungeon.push_back(curr_row);
		}
		cout<<"dungeon life "<<abs(s.calculateMinimumHP(dungeon)) + 1;
	}

	return 0;
}

*/
