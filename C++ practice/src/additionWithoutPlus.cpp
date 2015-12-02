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
		int a,b;
		infile>>a>>b;
		cout<<add(a,b)<<endl;
	}

	return 0;
}
*/
