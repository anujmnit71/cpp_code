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

#define N 2
char set[] = { 'a', 'b', 'c', 'd' };
int size = 4;

int len = 1;
char arr[1];
int count = 0;

void generate(int n) {
	if (n <= 0) {
		for (int i = 0; i < len; i++) {
			cout << arr[i] << '\t';
		}
		count++;
		cout << endl;
		return;
	}
	for (int i = 0; i < size; i++) {
		arr[n - 1] = set[i];
		generate(n - 1);
	}
	return;
}

int main() {
	int n = len;
	generate(n);
	cout << count;
	return 0;
}
*/
