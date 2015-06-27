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
    void reverseWords(string &s) {
        int st = 0 ;
        int end = 0;

        trim(s);
        cout<<"after trim\n"<<s<<"z"<<endl;
        while(end != s.length()){
            end++;
            if(s[end] == ' '){
                reverse1(s , st , end - 1);
                st = end+1;
                end++;
            }
            if(s[end] == '\0'){
            	reverse1(s , st , end - 1);
            	break;
            }
        }

        reverse1(s , 0 , s.length() - 1);

    }

    void trim(string &s){
        int st = 0;
        int end = 0;
        while(s[end] == ' ')
            end++;
        if(s[end] == '\0')
            s = "";
        s = s.substr(end);
    }

    void reverse1(string &s , int st , int end){
        while(st < end){
            swap(s[st] , s[end]);
            st++;
            end--;
        }
    }
};


class Solution {
public:
    void reverseWords(string &s) {
		int st = s.length() - 1;
		int end = s.length() - 1;
		ostringstream rev;
		rev<<"";

		while(end >= 0){
			while(s[end] == ' ' && end >= 0){
				end--;
			}
			if(end < 0)
				break;

			st = end;


			while(s[st] != ' ' && st >= 0)
				st--;

			string temp = s.substr(st + 1 , end - st);
			rev<<temp<<" ";

			end = st;
		}

		s = (rev.str()).substr( 0 , (rev.str()).length() - 1);//.substr(0 , rev.str().length - 1);
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
		string str;
		infile>>str;
		str = "this is my name";
		cout<<"string is\n"<<str<<endl;
		s.reverseWords(str);
		cout<<"reverse is\n"<<str<<"xz"<<endl;
	}
	return 0;
}
*/
