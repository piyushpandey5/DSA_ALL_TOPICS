#include<iostream>
using namespace std;

template<class T>
class LinkedList{
    private:
        class Node{
            public:
                T data;
                Node *next;
                Node(T data):data(data),next(nullptr){};
        };
        Node *head;
        Node *Tale;
    public:
        LinkedList():head(nullptr),Tale(nullptr){}
        void push_front(T data){
            Node *n=new  Node(data);
            n->next = head;
            head = n;
            if(Tale==nullptr){Tale=head;}
            
        }
        void display(){
            Node *temp;
            cout<<"head -->";
            while(temp->next!=nullptr){
                cout<<temp->data<<"  ";
                temp=temp->next;
            }
            cout<<"<-- Pointer "<<endl;
        }
        




};

int main()
{
    LinkedList<int> r;
    r.push_front(4);
    r.push_front(5);
    r.push_front(6);
    r.display();
    return 0;
}