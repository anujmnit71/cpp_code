
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
    void numDistinctUtil(string s, string t , int& count) {
        if(  ((s.size() == 0) && (t.size() != 0) ) )
            return ;
        if(  t.size() == 0 ){
            count++;
            return ;
        }

        if(s[0] == t[0]){
            numDistinctUtil(s.substr(1) , t.substr(1) , count);
            numDistinctUtil(s.substr(1) , t , count);

        }
        else
        	numDistinctUtil(s.substr(1) , t , count);
        return;
    }

    int numDistinct(string s, string t) {
        int count = 0;
        numDistinctUtil(s , t , count);
        return count;
    }

    int numDistinctDP(string s , string t){
    	int table[s.size() + 1][t.size()+1];
    	memset(table , 0 , (s.size() + 1)*(t.size() + 1)* sizeof(int));

    	for(int i = 0 ; i < s.size() + 1 ; i++){
    		table[i][0] = 1;
    	}

    	for(int i = 1 ; i < s.size() + 1 ; i++){
    		for(int j = 1 ; j <= t.size() ; j++){
    			if(s[i-1] == t[j-1])
    				table[i][j] = table[i-1][j-1] ;
    			table[i][j] += table[i-1][j];
    		}
    	}
    	return table[s.size()][t.size()];
    }


    int numDistinct(string S, string T , int k) {
          // Start typing your C/C++ solution below
          // DO NOT write int main() function
          int match[S.size()];
          if(S.size() < T.size()) return 0;
          match[0] = 1;
          for(int i=1; i <= T.size(); i++)
            match[i] = 0;
          for(int i=1; i<= S.size(); i ++)
            for(int j =T.size(); j>=1; j--)
              if(S[i-1] == T[j-1])
                match[j]+= match[j-1];


          return match[T.size()];
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
		string str,temp;
		Solution s;
		infile>>str;
		infile>>temp;
		cout<<s.numDistinctDP(str,temp)<<endl;
		cout<<s.numDistinct(str,temp,0)<<endl;
	}
	return 0;
}

