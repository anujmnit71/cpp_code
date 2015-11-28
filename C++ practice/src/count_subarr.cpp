#include<iostream>
using namespace std;

unsigned int arr[100001];

int main(){
	int test;
	unsigned int N;
	cin>>test;
	while(test--){
		cin>>N;
		int left , right;
		unsigned int first , second , count;
		count = 0;
		for(int i = 0 ; i < N ; i++){
			cin>>arr[i];
		}
		
		for(int i = 0 ; i < N ; i++){
			left = i;
			right = i;
			first = arr[i];
			i++;
			while( i < N){
				second = arr[i];
				if(first <= second)
					right++;
				else
					break;
				first = second;
				i++;
			}
			i--;
			int width = right +1- left;
			if(width%2 == 0)
				count = count + (width/2)*(width+1);
			else
				count = count + (width)*((width+1)/2);
		}
		cout<<count<<endl;	
	}
}
