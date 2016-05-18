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
        string addBinary(string a, string b) {
        int carry = 0;

        if(a.length() < b.length()){
            swap(a,b);
        }

        int aend = a.length() - 1;
        int bend = b.length() - 1;



        if(aend < 0)
            return b;
        if(bend < 0)
            return a;
        int end = aend ;

        string res(end + 1,0);

        while(aend >= 0 && bend >= 0 ){
            int num1 = a[aend] - '0' ;
            int num2 = b[bend]  - '0';

            int ans = (num1 + num2 + carry)%2;
            carry = (num1 + num2 + carry)/2;

            res[end] = ans + '0' ;
            end--;
            aend--;
            bend--;
        }

        while(aend >= 0){
            int num1 = a[aend] - '0';

            int ans = (num1 + carry)%2;
            carry = (num1 + carry)/2;

            res[end] = ans + '0' ;
            end--;
            aend--;
        }

        if(carry == 1){
            res.insert(res.begin(),'1');
        }

        return res;
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
		string a , b;
		infile>>a>>b;
		cout<<"ans "<<s.addBinary(a,b)<<endl;
	}
	return 0;
}
*/
