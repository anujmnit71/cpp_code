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


void inorder(struct node* head){
	if(head == NULL){
		return;
	}
	inorder(head->left);
	cout<<head->data<<'\t';
	inorder(head->right);

}




void kSmall(struct node* head , int k );

int kSmallUtil(struct node* head , int k  , int * count ){
	if(head == NULL){
		return -1;
	}

	int val = kSmallUtil(head->left , k , count );
	if(val>0)
		return val;
	(*count)++;
	if(*count == k){
		return head->data;
	}
	return kSmallUtil(head->right , k , count );

}

void kSmall(struct node* head , int k ){
	int count = 0;
	int *p = &count;
	*p = 0;
	cout<<kSmallUtil(head , k , &count )<<'\t';
	return;
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
		inorder(root);
		cout<<"Kth smallest elements is \n";
		kSmall(root, 1);
		kSmall(root, 2);
		kSmall(root, 3);
		kSmall(root, 4);
		kSmall(root, 5);
		kSmall(root, 6);
		kSmall(root, 7);
		kSmall(root, 22);
		kSmall(root, 9);
		kSmall(root, 10);
		kSmall(root, 11);
		kSmall(root, 12);
		kSmall(root, 13);
		kSmall(root, 20);
	}
	return 0;
}

*/
