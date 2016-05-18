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
	vector<vector<int> > collectPath(TreeNode *root){
	        vector<vector<int> > collect;
	        vector<int> solution;

	        if(root != NULL)
	            getPath(root ,solution , collect);;

	        return collect ;
	    }


	    void getPath(TreeNode* root ,vector<int>&  solution , vector<vector<int> >& collect){
	    	solution.push_back(root->val);

	    	if(root->left == NULL && root->right == NULL){
	    	    collect.push_back(solution);
	    	}
	    	else{
	            if(root->left)
	                getPath(root->left ,solution , collect);
	            if(root->right)
	                getPath(root->right ,solution , collect);

	    	}
	    	solution.pop_back();
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

		vector<vector<int> > v = s.collectPath(root);

		vector<vector<int> >::iterator it = v.begin();

		while(it!= v.end()){
			vector<int> curr = *it;
			vector<int>::iterator itcurr = curr.begin();
			while(itcurr!= curr.end()){
				cout<<*itcurr<<' ';
				itcurr++;
			}
			cout<<endl;
			it++;
		}


	}
	return 0;
}
*/
