/*
#include<stdio.h>
#include<iostream>

using namespace std;

int pivotedBinarySearch(int arr[] , int size , int no ){
	if(size <= 2)
		return std::max(arr[0] , arr[1]);
	int mid = size/2;
	if(arr[mid] > arr[mid + 1] && arr[mid] >= arr[mid-1]){
		return arr[mid];
	}

	if(arr[mid] < arr[mid+1]){
		return pivotedBinarySearch(arr + mid + 1 , size - mid - 1, no);
	}
	else{
		return pivotedBinarySearch(arr  , size - mid , no);
	}
}


int main()
{
   // Let us search 3 in below array
   int arr1[] = {5, 6, 7, 8, 9, 10, 3, 2, 1};
   int arr_size = sizeof(arr1)/sizeof(arr1[0]);
   int no = 3;
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr1, arr_size, no));

    // Let us search 3 in below array
   int arr2[] = {3, 4, 5, 2, 1};
   arr_size = sizeof(arr2)/sizeof(arr2[0]);
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr2, arr_size, no));

   // Let us search 0 in below array
   int arr3[] = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0};
   no = 0;
   arr_size = sizeof(arr3)/sizeof(arr3[0]);
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr3, arr_size, no));

   // Let us search 3 in below array
   int arr4[] = {2, 3, 2, 2, 2, 2, 2, 2, 2, 2};
   no = 3;
   arr_size = sizeof(arr4)/sizeof(arr4[0]);
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr4, arr_size, no));


   // Let us search 3 in below array
   int arr5[] = {1, 2, 3, 2};
   no = 3;
   arr_size = sizeof(arr5)/sizeof(arr5[0]);
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr5, arr_size, no));
   return 0;
}
*/
