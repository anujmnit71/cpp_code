/*
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include <sstream>
#define FROM_FILE true

using namespace std;


class Solution {
public:
    int func(vector<int>& prices){}
};


int main(){
	int test,element;
	ifstream ptrfile("ipLeetCode");
	istream& infile = FROM_FILE ? ptrfile:cin;

	infile>>test;
	while(test--){
		int k  ;
		infile>>k;
		vector<int> prices;
		std::string input_str;
		std::getline( infile, input_str );//to read the '\n' character at end of line
		std::getline( infile, input_str );

		std::stringstream ss(input_str);
		int i;
		while (ss >> i){
		  prices.push_back(i);
		  if (ss.peek() == ',')
		    ss.ignore();
		 }
		cout<<"total elements "<<i<<endl;
		for(int i = 0 ; i < prices.size() ; i++){
			cout<<prices[i]<<'\t';
		}

	}
	return 0;
}


2
3
1,2,3
4
1,2,3,4

*/
