/*
#include <iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>

using namespace std;

class Solution {
public:
    int reverse(int x) {
    	int newN =0, left =0;
    	            while(x != 0)
    	            {
    	                 left = x%10;
    	                 newN = newN*10 + left;
    	                 x = x/10;
    	            }
    	            return newN;
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
		infile>>size;
		cout<<s.reverse(size)<<endl;
	}
	return 0;
}

*/
