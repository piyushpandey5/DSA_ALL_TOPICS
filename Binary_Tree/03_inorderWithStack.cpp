#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void inOrder(Node *root){
    stack<Node *>s;
    Node *curr = root;
    while(curr!=NULL || s.empty()==false)
    {
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr = curr->right;

    }
}

int main(){
    struct Node * root = new Node(7);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(10);
    root->left->right = new Node(11);
    root->right->left = new Node(12);
    root->right->right = new Node(13);
    inOrder(root);
    return 0;
}