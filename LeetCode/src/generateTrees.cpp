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

char strArray[1000][1000];

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTreesUtil(1,n);

    }

    vector<TreeNode *> generateTreesUtil(int l , int h) {
        vector<TreeNode*> treeList;
        vector<TreeNode*> treeListLeft;
        vector<TreeNode*> treeListRight;
        if(h < l ){
        	treeList.push_back(NULL);
            return treeList;
        }
        else{
            for(int k = l ; k <=h ; k++){
                treeListLeft = generateTreesUtil(l,k-1);
                treeListRight = generateTreesUtil(k+1 , h);
                for(vector<TreeNode*>::iterator itleft = treeListLeft.begin() ; itleft != treeListLeft.end() ;itleft++ ){
                    for(vector<TreeNode*>::iterator itright = treeListRight.begin() ; itright != treeListRight.end() ;itright++ ){


                        TreeNode node(k); //this gives error

                        //this won't give error
                         //TreeNode *node = new TreeNode(k);
	                        //TreeNode* nodeptr = &node;

                        node.val = k;
                        TreeNode* nodeptr = &node;
                        node.left = *itleft;
                        node.right = *itright;
                        treeList.push_back(nodeptr);
                    }
                }
            }
        }
        return treeList;
    }



	vector<TreeNode *> generateTrees(int n) {
	        return generateTreesUtil(1,n);

	    }

	    vector<TreeNode *> generateTreesUtil(int l , int h) {
	        vector<TreeNode*> treeList;
	        vector<TreeNode*> treeListLeft;
	        vector<TreeNode*> treeListRight;
	        if(h < l ){
	        	treeList.push_back(NULL);
	            return treeList;
	        }
	        else{
	            for(int k = l ; k <=h ; k++){
	                treeListLeft = generateTreesUtil(l,k-1);
	                treeListRight = generateTreesUtil(k+1 , h);
	                for(vector<TreeNode*>::iterator itleft = treeListLeft.begin() ; itleft != treeListLeft.end() ;itleft++ ){
	                    for(vector<TreeNode*>::iterator itright = treeListRight.begin() ; itright != treeListRight.end() ;itright++ ){
	                        //TreeNode *node = new TreeNode(k);
	                        //TreeNode* nodeptr = &node;

	                    	TreeNode node(k);

	                    	node.left = *itleft;
	                        node.right = *itright;
	                        treeList.push_back(&node);
	                    }
	                }
	            }
	        }
	        return treeList;
	    }
	void inorder(TreeNode * root){
    	if(root == NULL)
    		return;
    	inorder(root->left);
    	printf("%d\t", root->val);
    	inorder(root->right);
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
		vector<TreeNode*> v = s.generateTrees(size);

		for(vector<TreeNode*>::iterator it = v.begin() ; it!= v.end();it++){
			//TreeNode* node = *it;
			s.inorder(*it);
			cout<<endl;
		}
	}
	return 0;
}

*/
