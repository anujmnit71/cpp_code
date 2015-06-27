/*
// partially paranthesized infix to postfix

#include<cstdio>
#include<stack>
#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

int main()
{
	int test ;
	//cin>>test;
	ifstream infile("ipLeetCode");
	if(infile)
		cout<<"success"<<endl;
	infile>>test;

	while(test--){
		int n , s;
		//scanf("%d %d" , &n , &s);
		infile>>n>>s;
		int result = -1;
		for(int i = n ; i > 0 ; i--){
			int sum = (i*(i+1))/2 + (n - i);
			if(sum == s){
				result = n - i;
				break;
			}

		}
		cout<<result<<endl;
	}

	return 0;
}

//2^31 = 2147483648
*/
