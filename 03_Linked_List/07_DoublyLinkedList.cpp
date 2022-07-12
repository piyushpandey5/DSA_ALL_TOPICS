#include<iostream>
using namespace std;

template <class T>
class doublyLinkedList{
    class node{
        public:
            node *prev;
            T data;
            node *next;
            node(T data):prev(nullptr),data(data),next(nullptr){}
    };
    node *head; 
    node *tail;
    public:
        doublyLinkedList():head(nullptr),tail(nullptr){}

        void push_back(T data){
            node *n = new node (data);
            if(head!=nullptr){
                // n->next==nullptr;
                tail->next = n;
                n->prev=tail;
            }
            else{
                head=n;
            }
            tail=n;
        }
        void push_front(T data){
            node *n = new node (data);
            if(head!=nullptr){
                // n->next==nullptr;
                head->prev = n;
                n->next=head;
            }
            else{
                head=n;
            }
            head=n;
        }
        void pop_back(){
            if(tail!=nullptr){
                if(tail!=head){
                    node *temp=tail;
                    tail=tail->prev;
                    delete temp;
                    tail->next=nullptr;
                }
                else{
                    head=tail=nullptr;
                }
            }
            else{
                cout<<"there is no node "<<endl;
            }
            
        }
        void pop_front(){
            if(head!=nullptr){
                if(tail!=head){
                    node *temp=head;
                    head=head->next;
                    delete temp;
                    head->prev=nullptr;
                }
                else{
                    head=tail=nullptr;
                }
            }
            else{
                cout<<"there is no node "<<endl;
            }
        }
        void display(){
            node *temp=head;
            cout<<"head ";
            while(temp!=nullptr){
                cout<<" -> "<<temp->data;
                temp=temp->next;
            }
            cout<<" <- tail";
        }
};

int main()
{
    doublyLinkedList<int> d;
    // d.push_back(5);
    // d.push_back(8);
    // d.push_back(9);
    // d.push_back(10);
    // d.push_back(11);
    // d.pop_back();
    // d.pop_back();
    // d.pop_back();
    // d.pop_back();
    // d.pop_back();
    // d.pop_front();
    // d.pop_front();
    // d.pop_front();
    // d.pop_front();

    d.push_front(7);
    d.push_front(7);
    d.push_front(7);
    d.push_front(7);
    d.push_front(7);
    d.display();

    return 0;
}