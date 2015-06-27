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

#define SIZE 100

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<int, int> mapstr;
        int mask = (1<<20) - 1;
        vector<string> result;
        int mapval = 0;

        map<char , int> mapkey;
        mapkey['A'] = 0;
        mapkey['C'] = 1;
        mapkey['G'] = 2;
        mapkey['T'] = 3;

        for(int i = 0 ; i < s.length() ; i++){
            mapval = ((mapval << 2) & mask) | mapkey[s[i]];

            if(i < 9)
                continue;

            mapstr[mapval]++;

            if(mapstr[mapval] == 2)
                result.push_back( s.substr(i-9 , 10));
        }

        return result;
    }
};


int main(){
	int test,size,element;
	ifstream infile("ipLeetCode");
	if(infile)
		cout<<"success";
	infile>>test;
	while(test--){
		Solution s;
		vector<string> v1;
		string str;
		infile>>str;
		v1 = s.findRepeatedDnaSequences(str);
		for(int i = 0 ; i < v1.size() ; i++)
			cout<<"\nElements are \n"<<v1[i];
		cout<<endl;
	}
	return 0;
}

*/
