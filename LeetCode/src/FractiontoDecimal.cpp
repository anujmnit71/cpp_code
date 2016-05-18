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
#include <sstream>

#define SIZE 100

using namespace std;

class Solution {
public:
    string fractionToDecimal(int num, int dino) {
    	ostringstream res,ans;
		if((num < 0) ^ (dino < 0))
            res<<"-";

        num = abs(num);
        dino = abs(dino);

		res<<num/dino;


		int rem = num%dino;
		if(rem != 0)
			res<<".";
		rem = (num%dino)*10;
		map<int , int> mymap;

		while(rem != 0 ){
			if(mymap.find(rem) != mymap.end()){
				int begin = mymap[rem];
				string part1 = (res.str()).substr(0,begin);
				string part2 = (res.str()).substr(begin);
				ans<<part1<<"("<<part2<<")";
				break;
			}

			mymap[rem] = (res.str()).length();

			res<<rem/dino;
			rem = (rem%dino)*10;
		}

		return ans.str();
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
		int a , b;
		infile>>a>>b;
		cout<<"ans "<<s.fractionToDecimal(a,b)<<endl;
	}
	return 0;
}
*/
