/*
//============================================================================
// Name        : heap.cpp
// Author      : anuj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<cstdio>
#include <iostream>
using namespace std;

#define N 2
char set[] = {'a','b','c','d'};
int size = 4;


int len = 1;
char arr[1];
int count = 0;


#include <iostream>
#include<cstdlib>
#include<stack>
#include<list>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct heap{
	int arr[100];
	int count; // initially zero

};


int getParent(struct heap * h , int val){
	if(val<= 0 || val>= h->count)
		return -1;
	return (val-1)/2;
}

int lChild(struct heap* h , int index){
	int left = 2*index + 1;
	if(left >= h->count)
		return -1;
	return left;
}


int rChild(struct heap* h , int index){
	int right = 2*index + 2;
	if(right >= h->count)
		return -1;
	return right;
}

int getMin(struct heap * h){
	if(h->count > 0)
		return h->arr[0];
	else
		return -1;
}

void percolateDown(struct heap * h , int i){
	int leftChild = lChild(h , i);
	int rightChild = rChild(h , i);
	int minval = h->arr[i];

	if(leftChild >=0)
		minval = std::min(h->arr[leftChild] , h->arr[i]);
	if(rightChild >= 0)
		minval = std::min(h->arr[rightChild] , minval);

	if(minval == h->arr[leftChild]){
		std::swap(h->arr[leftChild] , h->arr[i]);
		percolateDown(h , leftChild);
	}

	if(minval == h->arr[rightChild]){
		std::swap(h->arr[rightChild] , h->arr[i]);
		percolateDown(h , rightChild);
	}

}


int deleteMin(struct heap * h){
	int minval = getMin(h);
	if(minval == -1 )
		return -1;
	std::swap(h->arr[0] , h->arr[h->count - 1]);
	h->count = h->count -1;
	if(h->count > 0)
		percolateDown( h , 0);
	return minval;
}

void insert(struct heap * h , int val){
	h->arr[h->count] = val;
	h->count++;
	int parent = getParent(h , h->count -1);
	int up = parent ;
	int down = h->count - 1;

	while(up >= 0 && h->arr[up] > h->arr[down]){
		//cout<<"swapped ";
		std::swap(h->arr[up] , h->arr[down]);
		down = up;
		up = getParent(h , up);
	}

}

void display(struct heap * h){
	cout<<"Heap is \n";
	for(int i=0 ; i< h->count ; i++)
		cout<<h->arr[i]<<'\t';
	cout<<endl;

}

// first just copy whole array then start percolating down i.e. O(n) implementation
void buildHeap(struct heap * h , int a[] , int n){
	h->count = n;
	std::memcpy(h->arr , a ,n* sizeof(int));
	int up = getParent(h , h->count-1);
	for(int i = up ; i>=0  ; i--)
		percolateDown(h , i);
}

void heapSort(struct heap* h , int arr[] , int n){
	buildHeap(h , arr , n);
	display(h);
	for(int i =0 ; i< n ; i++){
		int min = deleteMin(h);
		cout<<"min is "<<min<<'\t';
		arr[i] = min;
		//cout<<"count is"<<h2->count<<endl;
		//display(h2);
	}
	cout<<'\n';
}


int main() {
	struct heap * h1 = (struct heap * )malloc(sizeof(heap));
	h1->count = 0;

	//building heap inefficient way inserting each element one by one O(nlogn)
	for(int i = 10; i> 0 ;i--){
		insert(h1 , i);
		//display(h1);
		//cout<<endl;
	}

	int arr[90];// = {10,9,8,7,6,5,4,3,2,1};
	int arr2[90];
	int size = 90;
	for(int i=0 ; i< size ; i++){
		arr[i] = (std::rand()*100)%99;
		arr2[i] = arr[i];
	}

	for(int i= 0 ;i< size ; i++)
			cout<<arr[i]<<'\t';
	cout<<endl;
	struct heap * h2 = (struct heap * )malloc(sizeof(heap));
	heapSort(h2 ,arr , size);
	for(int i= 0 ;i< size ; i++)
		cout<<arr[i]<<'\t';
	cout<<endl;

	// recheck of correct
	sort(arr2 , arr2 + size);
	for(int i= 0 ;i< size ; i++){
			if(arr[i] != arr2[i])
				cout<<"false";
	}



}
*/
