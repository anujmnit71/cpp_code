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
#include<map>
#include<list>
#include<fstream>

#define SIZE 100

using namespace std;

struct node{
	int data;
	struct node * left;
	struct node * right;
};

struct node* newNode(int data){
  struct node* node =
      (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

void inorder(struct node* head){
	if(head == NULL){
		return;
	}
	cout<<head->data<<'\t';
	inorder(head->left);
	inorder(head->right);

}

bool childSum(struct node* root ){
	if(root == NULL || (root->left == NULL && root->right == NULL)){
		return true;
	}
	int leftdata = 0;
	int rightdata = 0;
	if(root->left)
		leftdata = root->left->data;

	if(root->right)
		rightdata = root->right->data;

	if(root->data == leftdata + rightdata){
		return (childSum(root->left) && childSum(root->right));
	}
	else
		return false;


}

void increment(struct node* root , int diff){
	root->data += diff;
	if(root->left)
		increment(root->left , diff);
	else if(root->right)
		increment(root->right , diff);
}


void makechildSum(struct node* root ){
	if(root == NULL || (root->left == NULL && root->right == NULL)){
		return;
	}

	if(root->left)
		makechildSum(root->left);

	if(root->right)
		makechildSum(root->right);

	int leftdata = 0;
	int rightdata = 0;
	if(root->left)
		leftdata = root->left->data;

	if(root->right)
		rightdata = root->right->data;

	int diff = root->data - leftdata - rightdata;

	if(diff > 0){
		if(root->left)
			increment(root->left , diff);
		else
			increment(root->right , diff);
	}
	else if(diff < 0){
		diff = -diff;
		root->data += diff;
	}

}

int main(){

	struct node *root = newNode(50);
	  root->left        = newNode(7);
	  root->right       = newNode(2);
	  root->left->left  = newNode(3);
	  root->left->right = newNode(5);
	  root->right->left  = newNode(1);
	  root->right->right = newNode(30);

	  if(childSum(root))
	    printf("The given tree satisfies the children sum property ");
	  else
	    printf("The given tree does not satisfy the children sum property ");
	  makechildSum(root);
	  inorder(root);
	return 0;
}

*/
