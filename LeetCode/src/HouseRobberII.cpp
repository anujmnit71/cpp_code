/*
//============================================================================
// Name        : HouseRobber II.cpp
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


class Solution {
public:
    int robutil(vector<int> &num) {
        if(num.size() == 0)
            return 0;
        if(num.size() == 1)
            return num[0];
        if(num.size() == 2)
            return max(num[0] , num[1]);

        int first = num[0];
        int second = max(num[0] , num[1]);
        int result;
        for(int i = 2 ; i < num.size()  ; i++){
            result = max(num[i] + first , second);
            first = second;
            second = result;
        }
        return result;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];

        vector<int> first(nums.begin() , nums.end()-1);
        vector<int> last(nums.begin()+1 , nums.end());

        return max(robutil(first) , robutil(last));
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

		cout<<s.rob()<<endl;
	}
	return 0;
}
*/
