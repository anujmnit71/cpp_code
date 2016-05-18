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
    TreeNode *buildTree(vector<int> &postorder, vector<int> &inorder) {
        if(postorder.size() == 0)
            return NULL;
        int a = postorder.size();
        int b = inorder.size();
        return buildTreeUtil(postorder , inorder , 0 , postorder.size() - 1  , 0 , inorder.size() -1 );
    }

    TreeNode *buildTreeUtil(vector<int> &postorder, vector<int> &inorder , int poststart , int postend , int instart , int inend) {
        if(poststart > postend || instart > inend)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postend]);
        if(poststart == postend)
            return root;

        int i;
        for(i = instart ; i<=inend ; i++){
            if(postorder[postend] == inorder[i])
                break;
        }


        root->left = buildTreeUtil(postorder , inorder , poststart ,  postend - (inend -i ) -1, instart , i - 1);
        root->right = buildTreeUtil(postorder , inorder , postend - (inend -i ), postend - 1 , i+1, inend );

        return root;
    }

    void inorder(TreeNode * root){
   		if(root == NULL)
   			return;
   		inorder(root->left);
   		printf("%d\t", root->val);
   		inorder(root->right);
    }

    void preorder(TreeNode * root){
		if(root == NULL)
			return;
		printf("%d\t", root->val);
		preorder(root->left);
		preorder(root->right);
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

		vector<int> post;
		vector<int> in;

		for(int i =0 ; i<size ; i++){
			infile>>element;
			post.push_back(element);
		}

		for(int i =0 ; i<size ; i++){
			infile>>element;
			in.push_back(element);
		}

		TreeNode* t = s.buildTree(post , in);
		s.inorder(t);
		cout<<endl;
		s.preorder(t);
		cout<<endl;
	}

	return 0;
}
*/
