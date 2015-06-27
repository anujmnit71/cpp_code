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

list<int> mylist1;
list<int> mylist2;

void push(int data){
	if(mylist1.empty())
		mylist1.push_back(data);
	else
		mylist2.push_back(data);// always use list 2 for insert
}

int pop(){

	if(mylist1.empty() && mylist2.empty()){
		cout<<"Error \n";
		return -1;
	}
	if(!mylist2.empty()){ // first see into list 2 since this is the one used for insertion therefore last inserted item is always in list 2
		while(!mylist2.empty()){

			int data = (mylist2.front());
			mylist2.pop_front();
			if(!mylist2.empty())
				mylist1.push_back(data);
			else
				return data;
		}
	}

	if(!mylist1.empty()){
		while(!mylist1.empty()){ 			// if list 2 is empty that means last operation was pop and there was no push after that so all elements are in list 1 again
			int data = (mylist1.front()); 	// switch forth between list 2 and list 1 to get last inserted element
			mylist1.pop_front();
			if(!mylist1.empty())
				mylist2.push_back(data);
			else
				return data;
		}
	}
}

int main(){
	push(1);
	push(2);
	push(3);
	push(4);
	cout<<pop()<<' ';
	cout<<pop()<<' ';
	push(6);
	push(7);
	cout<<pop()<<' ';
	//cout<<pop()<<' ';
//	cout<<pop()<<' ';
//	cout<<pop()<<' ';
//	cout<<pop()<<' ';
//	cout<<pop()<<' ';
//	cout<<pop()<<' ';
	push(10);
		push(12);
		push(13);
		push(14);
		cout<<pop()<<' ';
		cout<<pop()<<' ';
		cout<<pop()<<' ';
		cout<<pop()<<' ';
		cout<<pop()<<' ';
		cout<<pop()<<' ';
		cout<<pop()<<' ';
	return 0;
}
*/
