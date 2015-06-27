/*
#include<cstdio>
#include<iostream>
#include<fstream>

using namespace std;

int add(int a , int b){
	while(b){
		int temp = a^b;
		b = (a&b);
		b = b<<1;
		a = temp;
	}
	return a;
}


int main()
{
	int test ;
	//cin>>test;
	ifstream infile("ip");
	if(infile)
		cout<<"success"<<endl;
	infile>>test;

	while(test--){
		int n, element;
		int arr[n];
		for(int i = 0 ; i < n ; i++){
			infile>>element;
			arr[i] = element;
		}
		cout<<stairCase(arr , n);
	}

	return 0;
}



*/
