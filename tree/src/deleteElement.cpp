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

void findParent(struct node * root, struct node** parent , int data){
	if(!root)
		return ;
	if(root->left!= NULL && root->left->data == data || root->right!= NULL && root->right->data == data ){
		*parent = root;
		return;
	}

	findParent(root->left , parent , data);
	findParent(root->right , parent , data);

}

struct node * findMax(struct node * root){
	while(root->right != NULL)
		root = root->right;
	return root;
}

struct node * deleteElement(struct node * root , int val){
	if(!root)
		return NULL;
	if(val > root->data)
		root->right = deleteElement(root->right , val);
	else if(val < root->data)
		root->left = deleteElement(root->left , val);
	else if(val == root->data){

		if(root->left && root->right){
			struct node * max = findMax(root->left);
			root->data = max->data;
			max->data = val;
			root->left = deleteElement(root->left , val);
		}
		else{
			struct node * temp = root;
			if(root->left)
				root = root->left;
			else if(root->right)
				root = root->right;
			else
				root = NULL;
			temp->left = NULL;
			temp->right = NULL;
			delete temp;
		}
	}
	return root;
}


void inorder(struct node* head){
	if(head == NULL){
		return;
	}
	cout<<head->data<<'\t';
	inorder(head->left);

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
		inorder(root);
		struct node *parent = NULL;
		root = deleteElement(root ,  10);
		cout<<endl;
				inorder(root);

		root = deleteElement(root ,  8);
		cout<<endl;
				inorder(root);

		root = deleteElement(root ,  11);
		cout<<endl;
				inorder(root);

		root = deleteElement(root ,  6);
		cout<<endl;
				inorder(root);


		root = deleteElement(root ,  6);
		cout<<endl;
			inorder(root);

		root = deleteElement(root ,  6);
		cout<<endl;
			inorder(root);

		root = deleteElement(root ,  6);
		cout<<endl;
			inorder(root);

		cout<<endl;
			inorder(root);
	}
	return 0;
}

*/
