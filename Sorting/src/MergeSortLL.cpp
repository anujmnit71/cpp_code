//============================================================================
// Name        : graph.cpp
// Author      : anuj
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<list>
#include<stack>
#include<map>
#include<cstdio>
using namespace std;

#define re(i, l, r) for (int i=l; i<r; i++)

struct node
{
	int val;
	struct node *next;
};

typedef struct node* nodeptr;

void insert(nodeptr* head,int n);
void display(struct node* head);

void insert(nodeptr* head,int n)
{
	struct node *temp,*p=*head;
	while(p!=NULL)   //to avoid repeation of value
	{
		if(p->val==n)
			return ;
		p=p->next;
	}
	p=*head;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->val=n;
	temp->next=NULL;
	if(*head==NULL)
		*head=temp;
	else
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
	}

}

void display(struct node* head)
{
	struct node* p=head;
	if(head==NULL)
	{
		printf("empty list\n");
		return;
	}
	while(p->next!=NULL)
	{
		printf("%d\t",p->val);
		p=p->next;
	}
	printf("%d\t",p->val);
	cout<<endl;
}

void split(struct node * &first , struct node * &second , struct node * &head){
	struct node *p = head , *q;
	int count=0;

	while(p!= NULL){
		p= p->next;
		count++;
	}

	first = p = head;
	second = NULL;

	if(count < 2){
		return;
	}

	for(int i =0 ; i< (count+1 )/2 ; i++){
		q = p;
		p = p->next;
	}

	second = p ;
	q->next = NULL;
}

void movenode(struct node * &dest , struct node * &src){ // move src node in front of dest node | new src is src->next
														//and new dest is moved node
	struct node * q = src;
	src = src->next;
	q->next = dest ;
	dest = q;


}

/*

struct node* merge(struct node* first , struct node* second){

	if(first == NULL)
		return second;
	if(second == NULL)
		return first;

	struct node *temp = first;
	struct node* prev = NULL;

	while(first!= NULL && second!= NULL){
		if(first->val <= second->val){
			prev = first;
			first = first->next;
		}
		else{
			movenode(first , second);
			if(prev == NULL)
				temp = first;
			cout<<"first is ";
			display(first);
			cout<<"second is ";
			display(second);
			if(prev)
				prev->next = first;
		}

	}
	if(first == NULL){
		prev->next = second;
	}

	return temp;
}
*/


struct node* merge(struct node* first , struct node* second){

	if(first == NULL)
		return second;
	if(second == NULL)
		return first;

	struct node dummy;
	struct node * temp = &dummy;
	dummy.next = NULL;


	while(1){
		if(first == NULL){
			temp->next = second;
			break;
		}
		if(second == NULL){
			temp->next = first;
			break;
		}
		if(first->val <= second->val){
			movenode(temp->next , first);
		}
		else{
			movenode(temp->next , second);
		}
		temp = temp->next;
	}


	return dummy.next ;

}

int listLength(struct node * head){
	int count = 0;
	while(head!= NULL){
		head = head->next;
		count++;
	}

	return count;
}


struct node*  mergeSort(struct node * list){

	if(listLength(list) <= 1)
			return list;

	struct node *list1=NULL , *list2=NULL;
	split(list1 , list2 , list);


	cout<<"before"<<endl;
	display(list1);
	display(list2);


	list1 = mergeSort(list1);
	list2 = mergeSort(list2);


	cout<<"after"<<endl;
	display(list1);
	display(list2);


	cout<<endl;
	list1 = merge(list1 , list2);

	cout<<"after merge"<<endl;
	display(list1);


	return list1;
}


int main()
{
	nodeptr head1=NULL ,head2 = NULL ;
	int test;
	int n , element;
	ifstream infile("ipSorting");
	infile>>test;

	while(test--){
		infile>>n;
		for(int i=0 ; i<n ; i++){
			infile>>element;
			insert(&head1,element);
		}
		display(head1);
		/*infile>>n;
		for(int i=0 ; i<n ; i++){
			infile>>element;
			insert(&head2,element);
		}
		display(head2);*/
		struct node *first1 , *first2 , *second1 , *second2;

		//split(first1 , first2 , head1);
		//split(second1 , second2 , head2);

		cout<<"sorted list"<<endl;
		//head1 = merge(head1 , head2);
		head1 = mergeSort(head1);
		display(head1);
	}

}

