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
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> vindex ;
		vector<int> vcopy(numbers);
		vector<int>::iterator it = vcopy.begin();

		std::sort(vcopy.begin(), vcopy.end());
		vector<int>::iterator itbegin = vcopy.begin();
		vector<int>::iterator itend = vcopy.end() -1;
		for(; itend != itbegin ;){
			if(*itbegin + *itend < target){
				itbegin++;
			}
			else if(*itbegin + *itend > target){
				itend--;
			}
			else{
				int i =1;
				while(numbers[i-1] != *itbegin)
					i++;
				vindex.push_back(i);
				i++;
				if(*itbegin != *itend)
				    i = 1;
				while(numbers[i-1] != *itend){
					i++;
				}
				vindex.push_back(i);
				break;
			}
		}
		if(vindex[0] > vindex[1])
		    std::swap(vindex[0] , vindex[1]);
		return vindex;
	}
};



class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> vindex ;
		std::map<int , int> smap;

		vector<int>::iterator itbegin = numbers.begin();
		vector<int>::iterator itend = numbers.end();
		for(; itend != itbegin ;itbegin++){
			smap[*itbegin] = itbegin - numbers.begin() + 1;

		}
		itbegin = numbers.begin();
		std::map<int , int >::iterator itmap;
		for(; itend != itbegin ;itbegin++){
			itmap = smap.find(target - *itbegin);
			if(itmap != smap.end() && itmap->second != (itbegin - numbers.begin() + 1)){
				vindex.push_back(itbegin - numbers.begin() + 1);
				vindex.push_back(itmap->second);
				break;
			}
		}
		return vindex;
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
		vector<int> v , v1;
		for(int i=0 ; i<size ; i++){
			infile>>element;
			v.push_back(element);
		}
		int target;
		infile>>target;
		v1 = s.twoSum(v, target);
		cout<<"\nTwo elements are \n"<<v1[0]<<"\t"<<v1[1];
	}
	return 0;
}

*/
