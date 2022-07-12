#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node (int data):data(data),next(nullptr){}
    };


    Node *head=nullptr;
    void push_front(int data){
        Node *n = new Node(data); 
        n->next=head;
        head=n;
    }

    bool find(int ele){
        Node *temp=head;
        while(temp!=nullptr){
            if(temp->data==ele){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    void display(){
        Node *temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

int main()
{
    int N,ele;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>ele;
        push_front(ele);
    }   
    find(4);
    return 0;
}