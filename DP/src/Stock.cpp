/*
//============================================================================
// Name        : Binomial Cofficient.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<vector>

#define re(i, l, r) for (int i=l; i<r; i++)
using namespace std;



class Solution {

public:
    int maxProfit(int k, vector<int> &prices) {
        if(prices.size() == 0)
            return 0;
        int priceList[prices.size()];
        for(int i = 0 ; i < prices.size() ; i++)
            priceList[i] = prices[i];
        return maxProfitUtil( k , priceList , prices.size());
    }

    int maxProfitForSize1(int prices[]) {
        if(prices.size() == 0)
            return 0;
        int low = prices[0];
        int maxprofit = 0;
        for(int i = 1 ; i < prices.size() ; i++){
            low = min(low , prices[i]);
            maxprofit = max(maxprofit , prices[i] - low);

        }
        return maxprofit;
    }

    int maxProfitUtil(int k , int priceList[] , int days){

        int profit = 0;

        if(k == 1){
            return maxProfitForSize1(priceList);
        }
        if(k > priceList.size() - 1)
            return 0;

        		for(int i = 1 ; i < priceList.size() - 1 ; i++){
            profit = maxProfitUtil(1 , std::vector<int>(priceList.begin() , priceList.begin() + 1 ) ) +
                    maxProfitUtil(k-1 , std::vector<int>(priceList.begin() + 1 , priceList.end() ) );
        }

        return max(maxProfitUtil(priceList , k-1 , days) + maxProfitForSize1(priceList + days - 1 ,  ) ,
                    maxProfitUtil(priceList , k , days-1 ) );
    }
};


int main(){
	int test =0;
	ifstream infile("ipDP");

	infile>>test;
	while(test--){
		int n,r;
		infile>>n>>r;

		cout<<"Count is				"<<count(n,r)<<endl;
		cout<<"Cost is					"<<countDP(n , r)<<endl;
	}
	return 0;
}

*/
