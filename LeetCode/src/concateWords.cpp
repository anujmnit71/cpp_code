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
#include<bitset>
#include<cstring>
#define SIZE 100

using namespace std;


class Solution {
public:
    vector<int> findSubstring(string str, vector<string>& words) {
        for(int i = 0 ; i < words.size() ; i++){
            int next = 0;
            while(str.find(words[i],next) != string::npos){
                int index = str.find(words[i],next);
                char s[100];
                sprintf(s,"%d",i);
                str.replace(index , words[i].length() ,s);
                next = index + 1;
            }
        }

        vector<int> result;
        unsigned long totalwords = words.size();
        for(int i = 0 ; i < str.size() ; i++){
            std::vector<bool> check(totalwords);
            int j = 0;
            if(str[i] <= '9' && str[i] >= '0'){
                j = i;

                while(str[i] <= '9' && str[i] >= '0'){
                    if(check[str[i] - '0'] == 0)
                        check[str[i] - '0'] = 1;
                    else{
                        check[str[i] - '0'] = 0;
                        break;
                    }
                    i++;
                }
                if(std::find(check.begin(), check.end(), 0) ==check.end()){
                	cout<<"j == "<<j<<endl;
                    result.push_back(j);
                }

            }

        }
        return result;
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
		vector<string > v(size);
		for(int i = 0 ; i < size ; i++){
			infile>>v[i];
		}
		string str;
		infile>>str;
		vector<int> ans = s.findSubstring(str,v);
		cout<<ans[0];
	}

	return 0;
}
*/
