/*
//============================================================================
// Name        : linked_list.cpp
// Author      : 
// Version     :
// Copyprev   : Your copyprev notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstdlib>
#include<stack>
#include<list>


#define SIZE 100

using namespace std;

struct node{
	int data;
	struct node * next;
	struct node * prev;
};

struct node* buildLL(struct node* head , int data){
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;

	if(head == NULL){
		head = temp;
	}
	while(head->next != NULL){
		head = head->next;
	}
	head->next = temp;
	temp->prev = head;

	return head;
}


void buildBST(struct node * root , struct node** head , struct node ** tail){
	struct node * headnext = NULL;
	struct node * headprev= NULL;
	struct node * tailnext= NULL;
	struct node * tailprev= NULL;

	if(root->next == NULL && root->prev == NULL)
		*head = *tail = root;
	if(root->next!= NULL){
		buildLL(root->next , head , tail);
		root->next = *tail;
		(*tail)->prev = root;
		headnext = *head;
		tailnext = *tail;
	}
	if(root->prev != NULL){
		buildLL(root->prev , head , tail);
		root->prev = *head;
		(*head)->next = root;
		headprev = *head;
		tailprev = *tail;
	}

	if( headnext!= NULL)
		*head = headnext;
	if(tailprev != NULL)
		*tail = tailprev;

}

void display(struct node* head){
	if(head == NULL){
		return;
	}
	cout<<head->data;
	display(head->next);

}

void inorder(struct node* head){
	if(head == NULL){
		return;
	}
	inorder(head->prev);
	cout<<head->data;
	inorder(head->next);

}


int main(){
	struct node* head = NULL;

	head = buildLL(head , 4);
	head = buildLL(head , 2);
	head = buildLL(head , 1);
	head = buildLL(head , 3);
	head = buildLL(head , 6);
	head = buildLL(head , 5);
	head = buildLL(head , 7);

	cout<<"List is \n";
	display(head);

	struct node * root = NULL ;

	buildBST(head , &root);

	cout<<"Tree traversal is \n";

	inorder(root);


	return 0;
}

*/
