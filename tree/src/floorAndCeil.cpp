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




//void floorCeil(struct node* head , int k );


int  floorCeilUtil(struct node* head , int k, struct node * prev){
	if(head == NULL){
		return 0;
	}

	int result = (floorCeilUtil(head->left , k , prev ));
	if(result > 0)
		return 0;
	prev = head;

	if(head->data >= k){
		int res = (prev)->data;
		//cout<<res<<'\t';
		return res;
	}

	return floorCeilUtil(head->right , k , prev);

}

void floorCeil(struct node* head , int k ){
	struct node  *p = NULL;

	int res = floorCeilUtil(head , k , p);
	cout<<res;
	return;
}


// for finding upper bound
int Ceil(struct node * root , float k){
	if(!root)
		return -1;
	if(root->data == k)
		return k;
	if(root->data > k){
		int ans = root->data;
		int ans2 = Ceil(root->left , k);
		if(ans2 > 0)
			return ans2;
		else
			return ans;
	}
	else{
		return Ceil(root->right , k);
	}
}

//lower bound
int floor(struct node * root , float k){
	if(!root)
		return -1;
	if(root->data == k)
		return k;
	if(root->data < k){
		int ans = root->data;
		int ans2 = floor(root->right , k);
		if(ans2 > 0)
			return ans2;
		else
			return ans;
	}
	else{
		return floor(root->left , k);
	}
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


		cout<<floor(root, 1)<<'\t'<<Ceil(root, 1)<<'\n';
		cout<<floor(root, 2)<<'\t'<<Ceil(root, 2)<<'\n';
		cout<<floor(root, 3)<<'\t'<<Ceil(root, 3)<<'\n';
		cout<<floor(root, 4)<<'\t'<<Ceil(root, 4)<<'\n';
		cout<<floor(root, 5)<<'\t'<<Ceil(root, 5)<<'\n';
		cout<<floor(root, 6)<<'\t'<<Ceil(root, 6)<<'\n';
		cout<<floor(root, 7)<<'\t'<<Ceil(root, 7)<<'\n';
		cout<<floor(root, 8)<<'\t'<<Ceil(root, 8)<<'\n';
		cout<<floor(root, 9)<<'\t'<<Ceil(root, 9)<<'\n';
		cout<<floor(root, 10)<<'\t'<<Ceil(root, 10.1)<<'\n';
		cout<<floor(root, 11)<<'\t'<<Ceil(root, 11.1)<<'\n';
		cout<<floor(root, 14)<<'\t'<<Ceil(root, 14)<<'\n';
	}
	return 0;
}



*/
