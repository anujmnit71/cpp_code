/*
//============================================================================
// Name        : recursion.cpp
// Author      : anuj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<cstdio>
#include <iostream>
using namespace std;

void tower(int n ,char from , char to , char aux){
	if(n==1){
		printf("Transfer 1 from %c to %c \n", from , to);
		return;
	}
	tower(n-1 , from , aux , to);
	printf("Transfer %d from %c to %c \n", n , from , to);
	tower(n-1 , aux , to , from);
}


int main() {
	int n =3;
	tower(n , 'A' , 'B' , 'C');
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
*/
