/*
#include<stdio.h>
#include<iostream>
#include<deque>

using namespace std;

int slidingWin(int arr[] , int size , int k ){
	deque<int> q;
	for(int i = 0 ; i < k ; i++){
		while(!q.empty() && arr[i] >= arr[q.back()] )
			q.pop_back();
		q.push_back(i);
	}

	for(int i = k ; i< size ; i++){
		cout<<arr[q.front()]<<'\t';
		while(!q.empty() && q.front() <= i-k ){
			q.pop_front();
		}
		while(!q.empty() && arr[i] >= arr[q.back()] )
			q.pop_back();
		q.push_back(i);
	}

	cout<<arr[q.front()];
}


int main()
{
    int arr[] = {12, 1, 7, 9, 57, 8, 56 , 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    slidingWin(arr, n, k);
    return 0;
}
*/
