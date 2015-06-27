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


void inorder(struct node* head){
	if(head == NULL){
		return;
	}
	cout<<head->data<<'\t';
	inorder(head->left);
	inorder(head->right);

}

void leftview(struct node* root , int level , int * maxlevel){
	if(root == NULL){
		return;
	}

	if(level > *maxlevel){
		cout<<root->data<<'\t';
		*maxlevel = level;
	}

	leftview(root->left , level + 1 , maxlevel);
	leftview(root->right , level + 1 , maxlevel);

}


void rightview(struct node* root , int level , int * maxlevel){
	if(root == NULL){
		return;
	}

	if(level > *maxlevel){
		cout<<root->data<<'\t';
		*maxlevel = level;
	}

	rightview(root->right , level + 1 , maxlevel);
	rightview(root->left , level + 1 , maxlevel);

}


void topview(struct node* root , int vlevel , map<int , int>* maplevel){
	if(root == NULL){
		return;
	}

	list<pair<struct node* , int > > nodelist;
	nodelist.push_back(make_pair(root,0));

	//map<int , int> nodemap;
	(*maplevel)[0] = root->data;
	cout<<root->data<<'\t';

	while(!nodelist.empty()){
		pair<struct node* , int> temp = nodelist.front();
		nodelist.pop_front();

		struct node * tempnode = temp.first;
		int hd = temp.second;

		if(maplevel->find(hd) == maplevel->end()){
			(*maplevel)[hd] = tempnode->data;
			cout<<tempnode->data<<'\t';
		}

		if(tempnode->left)
			nodelist.push_back(make_pair(tempnode->left , hd -1));
		if(tempnode->right)
			nodelist.push_back(make_pair(tempnode->right , hd +1));

	}

}

int main(){

	int test =0,size,element;
	ifstream infile("iptree");
	if(infile)
		cout<<"success";
	else
		cout<<"File missing";
	infile>>test;
	while(test--){
		infile>>size;
		struct node* root = NULL;
		for(int i=0 ; i<size ; i++){
			infile>>element;
			root = buildTree(root , element);
		}

		cout<<"\nInorder traversal is \n";
		inorder(root);

		cout<<"\nLeft view is \n";
		int maxlevel = -1;
		leftview(root , 0 , &maxlevel);

		cout<<"\nRight view is \n";
		maxlevel = -1;
		rightview(root , 0 , &maxlevel);

		cout<<"\nTop view is \n";
		map<int , int> maplevel;
		topview(root , 0 , &maplevel);

		cout<<"\nMap view is \n";
		for(map<int , int >::iterator itmap = maplevel.begin() ; itmap != maplevel.end() ; itmap++){
			cout<<itmap->first<<'\t'<<(*itmap).second<<'\t'<<endl;
		}
	}
	return 0;
}

*/
