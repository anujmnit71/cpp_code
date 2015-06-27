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

int arr[100][100];

class Solution {
public:
    void rotate90(int st , int e) {
    	if(st>= e)
    		return;
    	else{
    		for(int i = 0 ; i<e-st ; i++){
    			int top = arr[st][st + i];
    			arr[st][st + i] = arr[e-i][st];
    			arr[e-i][st] = arr[e][e - i];
    			arr[e][e - i] = arr[st + i][e];
    			arr[st + i][e] = top;
    		}
    		rotate90(st+1 , e -1);
    	}
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
		infile>>size;
		//int arr[size][size];
		for(int i = 0 ; i<size ; i++){
			for(int k = 0 ; k<size ; k++){
				infile>>element;
				arr[i][k] = element;
			}
		}
		s.rotate90(0 , size-1);
		for(int i = 0 ; i<size ; i++){
			for(int k = 0 ; k<size ; k++){
				cout<<arr[i][k]<<'\t';
			}
			cout<<endl;
		}

	}
	return 0;
}
*/
