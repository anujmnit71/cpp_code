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


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    public:
	vector<vector<int> > pathSum(TreeNode *root, int sum){
        vector<vector<int> > sumpaths;
        vector<vector<int> > allPaths = collectNumbers(root);

        for(vector<vector<int> >::iterator itPath = allPaths.begin() ; itPath != allPaths.end() ; itPath++){
        	int curr_sum = findSum(*itPath);
        	if(sum == curr_sum)
        		sumpaths.push_back(*itPath);
         }
        return sumpaths ;
    }

	int findSum(vector<int> v){
		vector<int>::iterator it = v.begin();
		int sum = 0;
		while(it != v.end()){
			sum += *it;
			it++;
		}
		return sum;
	}

    vector<vector<int> > collectNumbers(TreeNode* root){
    	vector<vector<int> > allpaths;
    	vector<vector<int> > leftpaths;
    	vector<vector<int> > rightpaths;

        if(root == NULL)
            return allpaths;

        vector<int> temppath;
        temppath.push_back(root->val);
        vector<int>::iterator ittemp = temppath.begin();

        if(root->left == NULL && root->right == NULL)
        	allpaths.push_back(temppath);

        leftpaths = collectNumbers(root->left);
        rightpaths = collectNumbers(root->right);

        vector<vector<int> >::iterator itleft , itright ;

        temppath.clear();

        for(itleft = leftpaths.begin() ; itleft!= leftpaths.end() ; itleft++ ){
        	ittemp = temppath.begin();
        	temppath.push_back(root->val);
        	temppath.insert(ittemp+1 , (*itleft).begin() , (*itleft).end() );
        	allpaths.push_back(temppath);
        	temppath.clear();
        }


        for(itright = rightpaths.begin() ; itright!= rightpaths.end() ; itright++ ){
        	ittemp = temppath.begin();
        	temppath.push_back(root->val);
			temppath.insert(ittemp+1 , (*itright).begin() , (*itright).end() );
			allpaths.push_back(temppath);
			temppath.clear();
        }

        return allpaths;

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
		TreeNode* root = new TreeNode(0);
		TreeNode* left = new TreeNode(1);
		TreeNode* right = new TreeNode(3);
		root->left = left;
		root->right = right;
		int sum = 3;

		vector<vector<int> > v = s.pathSum(root , sum);

		vector<vector<int> >::iterator it = v.begin();

		while(it!= v.end()){
			vector<int> curr = *it;
			vector<int>::iterator itcurr = curr.begin();
			while(itcurr!= curr.end()){
				cout<<*itcurr<<' ';
				itcurr++;
			}
			it++;
		}


	}
	return 0;
}
*/
