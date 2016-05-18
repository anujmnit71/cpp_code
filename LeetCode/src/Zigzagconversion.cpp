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
#define SIZE 100

using namespace std;

char strArray[1000][1000];


class Solution {
public:
    string convert(string s, int nRows) {

    	if(nRows == 1)
    		return s;

        int len = s.length();
        int nCol = len/nRows + (nRows-2)*(len/nRows);

       // memset(strArray , 0 , nRows*nCol);
        int i = 0 , j = 0;
        int index = 0;
        while(s[index]){
            while(i<nRows && s[index]){
                strArray[i][j] = s[index++];
                i++;
            }
            i--;
            while(i && s[index]){
                i--;
                j++;
                strArray[i][j] = s[index++];
            }
            //i--;
            j++;
        }
        string ans;
        for(int i =0 ; i< nRows ; i++){
            for(int j = 0 ; j< nCol ; j++){
                if(strArray[i][j] != 0)
                    ans.push_back(strArray[i][j]);
            }
        }
        ans.push_back('\0');
        return ans;

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
		int row;
		infile>>str;
		infile>>row;
		cout<<str<<row<<'\n';
		cout<<"original"<<'\n';
		for(int i =0 ; i< 13 ; i++){
		            for(int j = 0 ; j< 13 ; j++){
		            	cout<<strArray[i][j]<<'\t';

		            }
		            cout<<'\n';
		        }
		memset(strArray , 0 , sizeof(char)*1000*1000);
		cout<<"After memset"<<'\n';
		for(int i =0 ; i< 13 ; i++){
		            for(int j = 0 ; j< 13 ; j++){
		            	cout<<strArray[i][j]<<'\t';

		            }
		            cout<<'\n';
		        }
		cout<<"After conversion"<<'\n';
		cout<<s.convert(str, row);

	}
	return 0;
}

*/
