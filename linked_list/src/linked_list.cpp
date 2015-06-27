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
#include<stack>
#include<list>


#define SIZE 100

using namespace std;

stack<int> mystack1;
stack<int> mystack2;

void add(int data){
	mystack1.push(data);
}

int remove(){
	if(mystack2.empty() == true){
		if(mystack1.empty() == true)
			cout<<"Error"<<endl;
		else{
				while(!mystack1.empty()){
					mystack2.push(mystack1.top());
					mystack1.pop();
				}
				int data = mystack2.top();
				mystack2.pop();
				return data;
		}
	}
	else{
		int data = mystack2.top();
		mystack2.pop();
		return data;
	}
}

int main() {

	for(int i=10 ; i < 20 ; i++){
		add(i);
	}

	for(int i=0 ; i<5 ; i++){
			cout<<remove()<<' ';
	}
	return 0;
}
*/
