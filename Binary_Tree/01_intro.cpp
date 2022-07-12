#include<bits/stdc++.h>
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

int main()
{
	// create root
	Node *root = new Node(5);

	//following is the tree after above statement
	    // 	   5
	  //	 /   \
	// 	   NULL  NULL	

	root->left = new Node(4);
	root->right = new Node(6);

	/* 4 becomes left child of 5 and 6 become right
               5
            /     \
           4       6
          / \     / \
      NULL NULL NULL NULL
    */
    root->left->left = new Node(3);

    /* 3 becomes left child of 4
               5
            /     \
           4       6
          / \     / \
         3  NULL NULL NULL
        / \
     NULL NULL
    */
	return 0;
}