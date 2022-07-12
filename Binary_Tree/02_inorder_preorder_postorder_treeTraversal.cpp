#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node * left;
	struct Node * right;

	Node(int val){
		data=val;
		left = NULL;
		right = NULL; 
	}
};

void printInorder(struct Node * root){
	if(root==NULL){
		return;
	}
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

void printPreorder(struct Node * root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}

void printPostorder(struct Node * root){
	if(root==NULL){
		return;
	}
	printPostorder(root->left);
	printPostorder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	// create root
	Node *root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);

    root->left->left = new Node(4);
	root->left->right = new Node(5);
    
    cout<<"Inorder traversal of binary tree is - ";
    printInorder(root);
	cout<<endl;
    printPreorder(root);
	cout<<endl;
    printPostorder(root);
	return 0;
}