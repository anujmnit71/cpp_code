/*


//============================================================================
// Name        : linked_list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#define SIZE 100

using namespace std;



class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num , int &count) {
        vector<vector<int> > all;
        sort(num.begin() , num.end());
        permuteUtil(num , 0 , all , count);
        return all;
    }

    void permuteUtil(vector<int> &num , int st , vector<vector<int> > &all , int &count){
        if(st == num.size()){
            all.push_back(num);
            count++;
        }
        else{
            for(int i = st ; i < num.size() ; i++){
                if(num[st] == num[i] && i != st)
                    continue;
                else{
                	for( ; i +1 < num.size() && num[i] == num[i + 1] ; i++);
                    swap(num[st] , num[i]);
                    permuteUtil( num , st + 1 , all , count);
                    swap(num[st] , num[i]);

                }
            }
        }
    }
};



class Solution{

public:
void GeneratePermute(vector<int> & num, int step, vector<int>& visited, vector<int>& solution, vector<vector<int> >& coll , int &count)
{
  if(step == num.size())
  {
	coll.push_back(solution);
	count++;
	return;
  }
  for(int i =0; i< num.size(); i++)
  {
	if(visited[i] == 0)
	{
	  if(i>0 && num[i] == num[i-1] && visited[i-1] ==0)
		continue;
	  visited[i] = 1;
	  solution.push_back(num[i]);
	  GeneratePermute(num, step+1, visited, solution, coll,count);
	  solution.pop_back();
	  visited[i] =0;
	}
  }
}



vector<vector<int> > permuteUnique(vector<int> &num,int &count) {
 // Start typing your C/C++ solution below
 // DO NOT write int main() function
 vector<vector<int> > coll;
 vector<int> solution;
 if(num.size() ==0) return coll;
 vector<int> visited(num.size(), 0);
 sort(num.begin(), num.end());
 GeneratePermute(num, 0, visited, solution, coll,count);
  return coll;
}

};



int main(){
	int test,size,element;

	ifstream infile("ipLeetCode");
	if(infile)
//		cout<<"success";
	infile>>test;
	while(test--){
		Solution s;
		infile>>size;
		vector<int> v;
		for(int i = 0 ; i<size ; i++){
			infile>>element;
			v.push_back(element);
		}
		vector<vector<int> > all;
		int count = 0;
		all = s.permuteUnique(v, count);
		vector<vector<int> >::iterator it;
		cout<<"Total count is "<<count<<endl;
		for(it = all.begin() ; it != all.end() ; it++){
			for(int i = 0 ; i < (*it).size() ; i++){
				cout<<(*it)[i];
			}
			cout<<endl;
		}
	}
	return 0;
}

*/
