#include <iostream>
#include<bitset>
#include<fstream>
#include<vector>
#include<cmath>

#define FROM_FILE true

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(int A[], int n, int B[], int m) {
      if((n+m)%2 ==0)
        return (GetKthRank(A, n  , B , m, (m+n)/2+1) + GetKthRank(A, n, B , m , (m+n)/2 ) )/2.0;
      else
        return GetKthRank(A , n , B , m , (m+n)/2 + 1);
    }

    // Kth element(index) in 2 sorted array
    int GetKthRank(int a[], int n, int b[], int m, int k){
       // assert(a && b);
        if (n <= 0) return b[k-1];
        if (m <= 0) return a[k-1];

        if (k == 1) return min(a[0], b[0]);

        if (b[m/2] >= a[n/2]){
             if ((n/2 + 1 + m/2) >= k)
                return GetKthRank(a, n, b, m/2, k);
             else
                return GetKthRank(a + n/2 + 1, n - (n/2 + 1), b, m, k - (n/2 + 1));
        }
        else{
             if ((m/2 + 1 + n/2) >= k)
                return GetKthRank( a, n/2,b, m, k);
            else
                return GetKthRank( a, n, b + m/2 + 1, m - (m/2 + 1),k - (m/2 + 1));
        }
    }
};




int main(){
	int test;
	ifstream ptrfile("ipLeetCode");
	istream& infile = FROM_FILE?ptrfile:cin;

	infile>>test;
	while(test--){
		int k  ;
		infile>>k;
		Solution s;
		int a[] = {1,2};
		int b[] = {1};
		cout<<"total elements "<<s.findMedianSortedArrays(a , 2 , b , 1)<<endl;
	}
	return 0;
}
