/*
#include<cstdio>
#include<iostream>
#include<fstream>

using namespace std;
int main()
{
	int test  ;
	//cin>>test;
	ifstream infile("ipCodeChef.txt");
	if(infile)
		cout<<"success"<<endl;
	infile>>test;

	while(test--){
		long long int N,sum ;
		sum = 0;
		infile>>N;
		long long int a[N+1];
		for(int i = 0 ; i < N ; i++){
			infile>>a[i];
			sum = sum + a[i];
		}
		sum = sum/(N-1);

		for(int i = 0 ; i < N ; i++){
			cout<<sum - a[i]<<' ';
		}
		cout<<endl;
	}

	return 0;
}


*/

#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int test  ;
	cin>>test;
	while(test--){
		long long int N,sum ;
		sum = 0;
		cin>>N;
		unsigned long long int a[N];
		for(int i = 0 ; i < N ; i++){
			cin>>a[i];
			sum = sum + a[i];
		}
		sum = sum/(N-1);

		for(int i = 0 ; i < N ; i++){
			cout<<sum - a[i]<<' ';
		}
		cout<<endl;
	}

	return 0;
}
