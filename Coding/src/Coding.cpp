
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
#include<stack>

using namespace std;

long long subsequence_total(string str) {

	long long ones = 0;
	long long twos = 0, threes = 0, count = 0, prev_ones, prev_twos, prev_threes, sum = 0;
	long long len = str.length();
	long long MAX = 1000000007;
	for (int  i = 0; i < len; i++) {
		int current = (str[i] - '0') % 3;

		if(current==0)
		{
			prev_threes = (threes + threes) % MAX;
			prev_twos = (twos + twos) % MAX;
			prev_ones = (ones + ones) % MAX;
			sum = threes + 1;
			ones = prev_ones;
			twos = prev_twos;
			threes = prev_threes;
			threes++;
		}

		else if(current==1)
		{
			prev_ones = (ones + threes) % MAX;
			prev_twos = (twos + ones) % MAX;
			prev_threes = (threes + twos) % MAX;
			sum = twos;
			ones = prev_ones;
			twos = prev_twos;
			threes = prev_threes;
			ones++;

		}
		else if(current==2)
		{
			prev_ones = (ones + twos) % MAX;
			prev_twos = (twos + threes) % MAX;
			prev_threes = (threes + ones) % MAX;
			sum = ones;
			ones = prev_ones;
			twos = prev_twos;
			threes = prev_threes;
			twos++;
		}

		if ((str[i] - '0') % 2 == 0)
			count = (count + sum) % MAX;
	}

	return count;
}

int main()
{
	int test =0 ;
	string str;
	ifstream infile("ipCode");

	infile>>test;
	while(test--){
		infile>>str;
		cout<<subsequence_total(str)<<endl;
	}

}


