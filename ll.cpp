#include<iostream>
using namespace std;

class ll{
	class Node {
	public:
		int data;
		Node *next;
	};

	public:
	Node *head = nullptr;
	Node *tail = nullptr;

	void push_back(int a){
		Node *temp = new Node();
		if(head==nullptr){
			head =tail= temp;
		}
		else{
			tail->next = temp;
			tail=tail->next;
		}
	}

	void display(){
		Node *temp = head;
		while(temp!=nullptr){
			cout<<temp->data<<" ";
		}
	}

};


int main(){
	ll linkl;
	linkl.push_back(2);
	linkl.display();
}