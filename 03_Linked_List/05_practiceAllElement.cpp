#include<iostream>
using namespace std;

template<class T>
class LinkedList{
    class Node{
        public:
        T data;
        Node* next;
        Node(T data):data(data),next(nullptr){}
    };
    Node *head;
    Node *tail;
    public:
        LinkedList():head(nullptr),tail(nullptr){}

        void push_front(T data){
            Node *n = new Node(data);
            n->next = head;
            head = n;
            if(tail==nullptr){tail=head;}
        }

        void push_back(T data){
            Node *n= new Node (data);
            if(head==nullptr){
                head=tail=n; 
            }
            else{
                tail->next = n;
                tail=n;
            }
        }
        void pop_front(){
            Node *temp=head;
            if(head!=nullptr){
                
                if(head->next==nullptr){head=tail=nullptr;
                delete temp;}
                else{
                    head=head->next;
                    delete temp;
                }
            }
        }
        void pop_back(){
            if(head!=nullptr){
                if(head->next==nullptr){
                    delete head;
                    head=tail=nullptr;
                }
                else{
                    Node *temp = head;
                    while(temp->next->next!=nullptr){temp=temp->next;}
                    delete temp->next;
                    tail=temp;
                    temp->next=nullptr;
                }
            }
        }


        void pushAt(T data ,int index){
            Node *temp=head;
            Node *n=new Node(data);
            if(index==0){
                push_front(data);
            }
            else{
                while(--index){temp=temp->next;}
                n->next=temp->next;
                temp->next=n;
            }
                
        }
        void popAt(int index){
            
            if(head==nullptr){return ;}
            if(index==0){pop_back();}
            else{
                Node *temp=head;
                while(--index){temp=temp->next;if(temp==nullptr){cout<<"index out of bonds "<<endl;}}
                Node *d=temp->next;
                if(temp->next->next==nullptr){tail=temp;}      //not sure
                temp->next=temp->next->next;
                delete d;
                }
            
        }

        //copy constructor - this is wrong
        LinkedList(const LinkedList &obj){
            // this->head=obj.head;
            head=tail=nullptr;
            Node *n=obj.head;
            while(n!=nullptr){
                push_back(n->data);
                n=n->next;
            }
        }
        //copy assignment - this is wrong
        LinkedList &operator=(const LinkedList &obj){
            // this->head=obj.head;
            head=tail=nullptr;
            Node *n=obj.head;
            while(n!=nullptr){
                push_back(n->data);
                n=n->next;
            }
            return *this;
        }

        

                   

        void display(){
            Node *temp=head;
            cout<<" head ";
            while(temp!=nullptr){
                cout<<"-> "<<temp->data;
                temp=temp->next;
            }
            cout<<" <-tail"<<endl;
        }
};

int main()
{
    LinkedList<int> l1;
    // l1.push_front(4);
    // l1.push_front(3);
    l1.push_front(5);
    l1.push_front(5);
    l1.push_front(5);
    l1.push_back(6);
    l1.push_back(7);
    l1.push_back(9);
    // l1.pushAt(9,3);
    // l1.pushAt(9,0);
    // l1.pop_back();
    // l1.popAt(7);
    // l1.popAt(1);
    // l1.popAt(2);
    LinkedList<int>l2(l1);
    LinkedList<int>l3;
    l3=l1;
    
    // l1.pop_front();
    // l1.pop_front();
    // l1.pop_front();
    l1.display();
    l2.display();
    l3.display();
    return 0;
}