/*

//============================================================================
// Name        : linked_list.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include<cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isInterleaveRec(string s1, string s2, string s3) {
        if(s3.size() == 0)
            return !s1.size() && !s2.size();

        if(s3.size() != s1.size() + s2.size())
            return false;
        int s1i = 0;
        int s2i = 0;
        int s3i = 0;
        for(s3i = 0 ; s3i < s3.size() && (s1i < s1.size() || s2i < s2.size()); s3i++){
            if(s3[s3i] == s1[s1i])
                s1i++;
            else if(s3[s3i] == s2[s2i])
                s2i++;
            else
                return false;
        }

        if(s3i == s3.size())
            return true;

        if(s1[0] == s3[0] && s2[0] == s3[0])
            return isInterleaveRec(s1.substr(1) , s2 , s3.substr(1)) || isInterleaveRec(s1 , s2.substr(1) , s3.substr(1));

        if(s1[0] == s3[0] )
            return isInterleaveRec(s1.substr(1) , s2 , s3.substr(1)) ;

        if(s2[0] == s3[0])
            return isInterleaveRec(s1 , s2.substr(1) , s3.substr(1));

    }

    bool isInterleaveDP(string s1, string s2, string s3){
    	if(s3.size() != s1.size() + s2.size())
    		return false;

    	if (s1.empty()&&s2.empty()&&s3.empty()){
        	return true;
        }

    	int table[s1.size() + 1][s2.size() + 1];
    	memset(table , 0 , (s1.size() + 1)*(s2.size() + 1)*sizeof(int));
    	table[0][0] = 1;

    	for(int r = 1 ; r < s1.size() + 1 ; r++){
    		table[r][0] = (s3[r-1] == s1[r-1]) && table[r-1][0];
    	}

    	for(int c = 1 ; c < s2.size() + 1 ; c++){
			table[0][c] = (s3[c-1] == s2[c-1]) && table[0][c-1];
		}

    	for(int r = 1 ; r < s1.size() + 1 ; r++){
    		for(int c = 1 ; c < s2.size() + 1 ; c++){
    			table[r][c] = ( ( (s3[r+c-1] == s1[r-1]) && table[r-1][c] ) ||  ( (s3[r+c-1] == s2[c-1]) && table[r][c-1]  ) );

    		}
    	}

    	return table[s1.size()][s2.size()] ;
    }

};

int main(){
	int test,size,element;
	ifstream infile("ipCode");
	if(infile)
		cout<<"success";
	infile>>test;


	while(test--){

		int size=0;
		Solution s;
		string str1 , str2 , str3;
		infile>>str1;
		infile>>str2;
		infile>>str3;
		cout<<s.isInterleaveRec(str1 , str2 , str3)<<endl;
		cout<<s.isInterleaveDP(str1 , str2 , str3)<<endl;
	}
	return 0;
}

*/
