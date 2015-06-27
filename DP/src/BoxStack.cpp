/*
//============================================================================
// Name        : BoxStack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<algorithms>

#define re(i, l, r) for (int i=l; i<r; i++)
using namespace std;


struct box{
	int l;
	int w;
	int h;
};

int stackBox(struct box arr[] , int n){
	int LISarr[n];
	int parent[n];

	for(int i=0 ; i<n ; i++){
		cout<<"{"<<arr[i].l<<","<<arr[i].w<<","<<arr[i].h<<"}"<<' ';
	}

	sort()
	for(int i=0 ; i<n ; i++){
		LISarr[i] = arr[i].h;
		parent[i] = -1;
	}

	int maxval = 0;
	int index =0;
	for(int i=1 ; i< n ;i++){
		for(int j=0 ; j< i ; j++){
			if(arr[i].l > arr[j].l && arr[i].w > arr[j].w && LISarr[i] < LISarr[j] + arr[i].h){
				LISarr[i] = LISarr[j] + arr[i].h;
				parent[i] = j;
				maxval = std::max(maxval , LISarr[i]);
				if(maxval == LISarr[i])
					index = i;
			}
		}

	}
	int curr = index;
	int p = parent[curr];

	cout<<"LIS is"<<endl;
	while(p != -1){
		cout<<"{"<<arr[curr].l<<","<<arr[curr].w<<","<<arr[curr].h<<"}"<<' ';
		curr = p;
		p = parent[curr];
	}
	cout<<"{"<<arr[curr].l<<","<<arr[curr].w<<","<<arr[curr].h<<"}"<<' ';
	cout<<endl;
	return maxval;
}

int main(){
	int test =0,size;
	ifstream infile("ipDP");

	infile>>test;
	while(test--){
		infile>>size;
		struct box arr[size];
		for(int i=0 ; i<size ; i++){
			int a,b,c;
			infile>>a>>b>>c;
			arr[i].l = a;
			arr[i].w = b;
			arr[i].h = c;
		}
		struct box arrRot[3*size];
		for(int i=0,j=0; i<3*size ;i = i+3,j++){
			struct box b1,b2,b3;

			arrRot[i] = arr[j];


			// make length as height
			b2.h = arr[j].l;
			b2.l = std::max(arr[j].h , arr[j].w);
			b2.w = std::min(arr[j].h , arr[j].w);


			// make width as height
			b3.h = arr[j].w;
			b3.l = std::max(arr[j].h , arr[j].l);
			b3.w = std::min(arr[j].h , arr[j].l);

			arrRot[i+1] = b2;
			arrRot[i+2] = b3;
		}

		cout<<"Length is "<<stackBox(arrRot , 3*size)<<endl;
	}
	return 0;
}

// {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}
*/
