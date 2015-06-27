


#include<iostream>
#include<fstream>
using namespace std;

int sum(int array[],int size){
	if(size==1)
		return array[0];
	else
		return array[0]+sum(array+1,size-1);
}

int main()
{
	int test = 0;
	ifstream infile("ip");
	infile>>test;

	while(test--){
		int size , element;
		infile>>size;
		int arr[size];
		for(int i=0 ; i<size ; i++){
			infile>>element;
			arr[i] = element;
		}
		int result = sum(arr , size);
		cout<<"sum of array is "<<result<<endl;
	}
}

/*
Sample input copy to file with name ip (dont add .txt at end of filename)
2
5
1 2 3 4 5
6
5 8 92 7 6 3

*/
