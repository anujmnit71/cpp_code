/*
//============================================================================
// Name        : MAR 15 codechef
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>

#define re(i, l, r) for (int i=l; i<r; i++)
using namespace std;

//typedef long long int ll;


int main(){
	int test =0;
	ifstream infile("ipDP");

	infile>>test;
	//cin>>test;
	while(test--){
		int total , aval , req , budget , nBook , pricei , pagesi ;
		bool done = false;
		infile>>total>>aval>>budget>>nBook;
		//cin>>total>>aval>>budget>>nBook;
		req = total - aval;
		if(req <= 0){
			cout<<"LuckyChef\n";
			done = true;
			for(int i = 0 ; i < nBook ; i++){
					infile>>pagesi>>pricei;
					//cin>>pagesi>>pricei;
			}
		}
		else{
			for(int i = 0 ; i < nBook ; i++){
				infile>>pagesi>>pricei;
				//cin>>pagesi>>pricei;
				if(!done && pricei <= budget && req <= pagesi){
					cout<<"LuckyChef\n";
					done = true;
				}
			}
			if(!done)
				cout<<"UnluckyChef\n";
		}
	}
	return 0;
}

*/
