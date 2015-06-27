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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0)
            return NULL;

        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1)
            return root;

        vector<int>::iterator itpre = preorder.begin();
        vector<int>::iterator itin =  inorder.begin();

        int count = 0;
        while(itin != inorder.end()){
            if(*itin == preorder[0])
                break;
            itin++;
            count++;
        }

        vector<int> preleft(preorder.begin() +1, itpre + count + 1);
        vector<int> preright(itpre + count + 1 , preorder.end());

        vector<int> inleft(inorder.begin() , itin);
        vector<int> inright(itin+1 , inorder.end());

        root->left = buildTree(preleft , inleft);
        root->right = buildTree(preright , inright);

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

		vector<int> pre;
		vector<int> in;

		for(int i =0 ; i<size ; i++){
			infile>>element;
			pre.push_back(element);
		}

		for(int i =0 ; i<size ; i++){
			infile>>element;
			in.push_back(element);
		}

		TreeNode* t = s.buildTree(pre , in);
		cout<<"Inorder is"<<endl;
		s.inorder(t);
		cout<<"Preoder is "<<endl;
		s.preorder(t);
		cout<<endl;
	}

	return 0;
}

*/
