
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
#include<string>

using namespace std;

class Solution {
public:
	// recursive solution
    void numDecodings(string s, int& count) {
    	if(s.length() == 1){
			count = count + 1;
			return;
		}
        if(s.length() == 2){
        	if(atoi(s.c_str()) <= 26)
        		count = count + 2;
        	else
        		count = count + 1;
            return;
        }

        numDecodings(s.substr(1) , count);
        if(atoi(s.substr(0,2).c_str()) <= 26)
        	numDecodings(s.substr(2) , count);
        return ;
    }

    bool valid(string s){
		if (s.size()==0){return false;}
		if (s[0]=='0'){return false;}
		if (s.size()==2){
			if (s[0]>'2' || (s[0]=='2'&& s[1]>'6')){return false;}
		}
		return true;
	}
    int numDecodingsDP(string s) {
		if(s.length() == 0)
			return 0;

		int table[s.length()];
		table[0] = 1;
		table[1] = table[0] + (valid(s)?1:0) ;

		for(int i = 2 ; i< s.length() ; i++){
			table[i] = table[i-1] ;
			string lasttwo = s.substr(i-1 , 2);

			if(valid(s))
				table[i] = table[i-1] + table[i-2];
		}

		return table[s.length() - 1];
	}
};

int main(){
	int test,size,element;
	ifstream infile("ipCode");
	if(infile)
		cout<<"success";
	infile>>test;
	while(test--){
		Solution s;
		string str;
		infile>>str;
		int count = 0;
		s.numDecodings(str,count);
		cout<<"rec sol is"<<count<<endl;
		cout<<s.numDecodingsDP(str)<<endl;
	}
	return 0;
}
