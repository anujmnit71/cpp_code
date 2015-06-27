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


void buildLL(struct node * root , struct node** head , struct node ** tail){
	struct node * headLeft = NULL;
	struct node * headRight= NULL;
	struct node * tailLeft= NULL;
	struct node * tailRight= NULL;

	if(root->left == NULL && root->right == NULL)
		*head = *tail = root;
	if(root->left!= NULL){
		buildLL(root->left , head , tail);
		root->left = *tail;
		(*tail)->right = root;
		headLeft = *head;
		tailLeft = *tail;
	}
	if(root->right != NULL){
		buildLL(root->right , head , tail);
		root->right = *head;
		(*head)->left = root;
		headRight = *head;
		tailRight = *tail;
	}

	if( headLeft!= NULL)
		*head = headLeft;
	else
		*head = root;
	if(tailRight != NULL)
		*tail = tailRight;
	else
		*tail = root;

}

void inorder(struct node* head){
	if(head == NULL){
		return;
	}
	inorder(head->left);
	cout<<head->data;
	inorder(head->right);

}


int main(){
	struct node* root = NULL;
	int test =0,size,element;
	ifstream infile("iptree");
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
		struct node * head = NULL ;
		struct node * tail = NULL;
		buildLL(root , &head , &tail);
		cout<<"List traversal is \n";

		while(head != NULL ){
			cout<<head->data<<'\t';
			head = head->right;
		}
		cout<<"List traversal is \n";
		while(tail != NULL ){
			cout<<tail->data<<'\t';
			tail = tail->left;
		}

	}
	return 0;
}

*/
