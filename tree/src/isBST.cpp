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
#include<stack>
#include<list>
#include<fstream>

#define SIZE 100

using namespace std;

struct node{
	int data;
	struct node * left;
	struct node * right;
};

struct node* buildTree(struct node* head , int data){
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	if(head == NULL){
		head = temp;
	}
	else{
		if(head->data >= data)
			head->left = buildTree(head->left , data);
		else
			head->right = buildTree(head->right , data);
	}
	return head;
}

// using inorder traversal
bool isBST(struct node * root){
	static struct node * prev ;
	if(!root)
		return true;
	if(isBST(root->left)){
		if(prev != NULL && prev->data > root->data)
			return false;
		prev = root;
		cout<<root->data<<'\t';
		return isBST(root->right);
	}
	else
		return false ;

}


// using min and max values
bool isBST2(struct node * root, int min , int max){
	if(!root)
		return true;
	cout<<min <<'\t';
		cout<<max<<endl;

	if(root->data >max || root->data < min)
		return false;
	if(isBST2(root->left , min , root->data)){
		return isBST2(root->right , root->data , max);
	}
	else
		return false ;

}

void inorder(struct node* head){
	if(head == NULL){
		return;
	}
	inorder(head->left);
	cout<<head->data<<'\t';
	inorder(head->right);

}


int main(){
	struct node* root = NULL;
	int test =0,size,element;
	ifstream infile("ip");
	if(infile)
		cout<<"success";
	infile>>test;
	while(test--){
		infile>>size;
		for(int i=0 ; i<size ; i++){
			infile>>element;
			root = buildTree(root , element);
		}

		cout<<"Inorder traversal is \n";
		root->right->right->data = 44;
		cout<<"List traversal is \n";
		bool res = isBST(root);
		res = isBST2(root, 0 , 10000);
		cout<<"res is "<<res;
	}
	return 0;
}

*/
