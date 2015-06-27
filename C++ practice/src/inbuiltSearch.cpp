/*

// using inbuilt search in c++


===============================================================================================
//using binary_search
returns only whether an element is present or not , not its position

// in an array
#include <iostream>     // std::cout
#include <algorithm>    // std::binary_search, std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

int main () {
  int myints[] = {1,2,3,4,5,4,3,2,1};

  // using default comparison:
  std::sort (myints , myints+9);


  std::cout << "looking for a 3... ";
  if (std::binary_search (myints,myints+9, 3))
    std::cout << "found!\n"; else std::cout << "not found.\n";

  // using myfunction as comp:
  std::sort (myints,myints+9, myfunction);

  std::cout << "looking for a 6... ";
  if (std::binary_search (myints,myints+9, 6, myfunction))
    std::cout << "found!\n"; else std::cout << "not found.\n";

  return 0;
}

// searching in a vector
#include <iostream>     // std::cout
#include <algorithm>    // std::binary_search, std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

int main () {
  int myints[] = {1,2,3,4,5,4,3,2,1};
  std::vector<int> v(myints,myints+9);                         // 1 2 3 4 5 4 3 2 1

  // using default comparison:
  std::sort (v.begin(), v.end());

  std::cout << "looking for a 3... ";
  if (std::binary_search (v.begin(), v.end(), 3))
    std::cout << "found!\n"; else std::cout << "not found.\n";

  // using myfunction as comp:
  std::sort (v.begin(), v.end(), myfunction);

  std::cout << "looking for a 6... ";
  if (std::binary_search (v.begin(), v.end(), 6, myfunction))
    std::cout << "found!\n"; else std::cout << "not found.\n";

  return 0;
}

================================================================================================
// finding element position using find
// find example
there are more find variations
find
find_end
find_first_of
find_if
find_if_not

#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector

int main () {
  // using std::find with array and pointer:
  int myints[] = { 10, 20, 30, 40 };
  int * p;

  p = std::find (myints, myints+4, 30);
  if (p != myints+4)
    std::cout << "Element found in myints: " << *p << '\n';
  else
    std::cout << "Element not found in myints\n";

  // using std::find with vector and iterator:
  std::vector<int> myvector (myints,myints+4);
  std::vector<int>::iterator it;

  it = find (myvector.begin(), myvector.end(), 30);
  if (it != myvector.end())
    std::cout << "Element found in myvector: " << *it << '\n';
  else
    std::cout << "Element not found in myints\n";

  return 0;
}


=========================================================================================================

// for searching for a subsequence
 *
// search algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::search
#include <vector>       // std::vector

bool mypredicate (int i, int j) {
  return (i==j);
}

int main () {
  std::vector<int> haystack;

  // set some values:        haystack: 10 20 30 40 50 60 70 80 90
  for (int i=1; i<10; i++) haystack.push_back(i*10);

  // using default comparison:
  int needle1[] = {40,50,60,70};
  std::vector<int>::iterator it;
  it = std::search (haystack.begin(), haystack.end(), needle1, needle1+4);

  if (it!=haystack.end())
    std::cout << "needle1 found at position " << (it-haystack.begin()) << '\n';
  else
    std::cout << "needle1 not found\n";

  // using predicate comparison:
  int needle2[] = {20,30,50};
  it = std::search (haystack.begin(), haystack.end(), needle2, needle2+3, mypredicate);

  if (it!=haystack.end())
    std::cout << "needle2 found at position " << (it-haystack.begin()) << '\n';
  else
    std::cout << "needle2 not found\n";

  return 0;
}

=========================================================================
//using bsearch


#include <iostream>
#include <cstdlib>

#define SIZE 10

int compare (const void *elem1, const void *elem2){
    return *(int*)elem1 - *(int*)elem2;
}

int main(){
    int i,x;
    int array[SIZE] = {9,1,3,7,0,5,2,6,8,4};

    qsort(array, SIZE, sizeof(int), compare);

    for (i=0;i<SIZE;i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    x = 25;
    std::cout << bsearch(&x,array,SIZE,sizeof(int),compare) << std::endl;
    x = 9;
    std::cout << bsearch(&x,array,SIZE,sizeof(int),compare) << std::endl;

    return 0;

}



*/
