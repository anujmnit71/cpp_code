/*
// Name:Anuj Kumar Verma
// Summary:

#include <iostream>
#include<string>
#include<cstring>
#include<list>
#include<algorithm>
#include <map>
using namespace std;

// Remove additional cin/cout before submission.

#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

typedef unsigned long long int ull;


int mycount(string str)
{
	int count_dash[10] = {6,2,5,5,4,5,6,4,7,6};
	int i = 0;
	int count = 0;
	while(str[i] != '\0'){
		count+= count_dash[str[i] - '0'];
		i++;
	}

	return count ;
}


ull modpow(ull base, ull exp, ull modulus) {
  base %= modulus;
  ull result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result% modulus;
}


long long int mycount(ull N , ull k){
	if(N < k)
			return 0;
	ull modulus = pow(10,9) + 7;
	ull total = modpow(k,N , modulus);

	ull miss1 = (k * mycount(N , k-1))%modulus;
	ull miss2 = ((k*(k-1)/2) *mycount(N , k-2))%modulus;
	long long int result = total - miss1 - miss2;
	return result;
}


// Do not modify main() when submitting.
int main()
{
	ifstream infile("ip");
	if(infile)
		cout<<"success\n";
	int test;
	infile>>test;
	while(test--){
		ull N;
		infile>>N;
		cout<<mycount(N , 3)<<endl;
	}
}
*/
