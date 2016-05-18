/*
#include <iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include <sstream>
#include<cstring>

using namespace std;


We track two arrays - local and global. The local array tracks maximum profit of j transactions & the last transaction
is on ith day.
The global array tracks the maximum profit of j transactions until ith day.


class Solution {
public:
    int allProfit(vector<int>& prices){
		int tot = 0;
		for(int i = 1; i < prices.size(); ++i){
			tot += max(0, prices[i] - prices[i-1]);
		}
		return tot;
    }

	int maxProfit(int k, vector<int> prices){
		int n = prices.size();
		// this case is added for efficiency
		if(k * 2 >= n) return allProfit(prices);

        int local[n+1][k+1];
        memset(local , 0 , sizeof(int)*(n+1)*(k+1) );

        int global[n+1][k+1];
        memset(global , 0 , sizeof(int)*(n+1)*(k+1) );

        for(int col = 0; col < k+1 ; col++){
        	local[0][col] = 0;
        	global[0][col] = 0;
        	local[1][col] = 0;
        	global[1][col] = 0;
        }

        for(int row = 0; row < n+1 ; row++){
			local[row][0] = 0;
			global[row][0] = 0;
		}

        for(int d = 2 ; d <= n ; d++){
        	for(int t = 1 ; t <= k ; t++){
        		local[d][t] = max(local[d-1][t] +prices[d-1] - prices[d-2] ,
        							global[d-1][t-1] + max(prices[d-1] - prices[d-2] , 0));
        		global[d][t] = max(global[d-1][t] , local[d][t] );
        	}
        }

        return global[n][k];
    }

};


int main(){
	int test,element;
	ifstream infile("ipLeetCode");
	if(infile)
//		cout<<"success";
	infile>>test;
	while(test--){

		int k  ;
		infile>>k;
		vector<int> prices;

		std::string input_str;

		std::getline( infile, input_str );
		std::getline( infile, input_str );

		std::stringstream ss(input_str);

		int i;

		while (ss >> i)
		{
		  prices.push_back(i);
		  if (ss.peek() == ',')
		    ss.ignore();
		 }

		int arr[prices.size()];
		i = 0;
		for(i = 0 ; i < prices.size() ; i++){
			arr[i] = prices[i];
		}
		cout<<"total elements "<<i<<endl;
		for(int i = 0 ; i < prices.size() ; i++){
			infile>>element;
			arr[i] = element;
			prices[i] = element;
		}
		Solution s;
		cout<<s.maxProfit(k , prices)<<endl;

	}
	return 0;
}
*/
