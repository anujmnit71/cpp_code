/*

//============================================================================
// Name        : recursion.cpp
// Author      : anuj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Time{

	public :
	int h;
	int m;
	int s;
	Time(int a , int b , int c){
		h = a;
		m = b;
		s = c;
	}

};


class CompareTime{
	public:
	bool operator () (const Time& t1 , const Time& t2){
		if(t1.h <= t2.h)// max heap
			return true;
		if(t1.h == t2.h && t1.m <= t2.m)
			return true;
		if(t1.h == t2.h && t1.m == t2.m && t1.s <= t2.s)
			return true;

		return false;
	}
};


int main() {

	std::priority_queue<Time , vector<Time> , CompareTime> queue;
	Time t1(11,15,0) , t2(12,20,0);

	queue.push(t1);
	queue.push(t2);

	while(!queue.empty()){
		Time t = queue.top();
		queue.pop();
		cout<<t.h<<":"<<t.m<<":"<<t.s<<endl;
	}
	return 0;

}

// O/p
//12:20:0
//11:15:0
*/
