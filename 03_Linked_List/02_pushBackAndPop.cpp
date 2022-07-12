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
        Node *tail;
    public:
        LinkedList():head(nullptr),tail(nullptr){}
        void push_front(T data){
            Node *n=new  Node(data);
            n->next = head;
            head = n;
            if(tail==nullptr){tail=head;}
            
        }

        void push_back(T data){
            Node *n=new Node(data);
            if(head==nullptr){head=tail=n;}
            else{
                tail->next = n;
                tail=n;
            }
            
        }
        void pop_front(){
            if(head!=nullptr){
                if(head->next==nullptr){
                    delete head;
                    head=tail=nullptr;
                }
                else{
                    Node *temp = head;
                    if(head==nullptr){
                        tail=nullptr;
                    }
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
            if(index==0){push_front(data);}
            else{
                while(--index){
                    temp=temp->next;
                    if(temp==nullptr){cout<<"index out of bonds ";
                    return ;}
                }
                Node *n=new Node(data);
                n->next = temp->next;
                temp->next=n;
            }
        }
        void popAt(int index){
            Node *temp=head;
            if(head==nullptr){return;} 
            if(index==0){pop_front();}
            else{
                while(--index){
                    temp=temp->next;
                    if(temp==nullptr){cout<<"index out of bonds "<<endl;
                    }
                }
                Node *d = temp->next;
                temp->next = temp->next->next;
                delete d;

            }
        }
        

        void erase(int startIndex, int endIndex){
            Node *temp1=head;
            // Node *temp2=head;
            Node *temp11;
            Node *temp22;
            int eraseIndex=endIndex-startIndex;
            if(head==nullptr){return;}
            while(--startIndex)
            {
                    temp1=temp1->next;
                    if(temp1==nullptr){
                        cout<<"index out of bonds "<<endl;
                    }
                }
            // while(--endIndex)
            // {
            //         temp2=temp2->next;
            //         if(temp2==nullptr){cout<<"index out of bonds "<<endl;
            //         }
            // }
            temp11=temp1->next;
            temp22=temp1->next;
            while(--eraseIndex){
                temp11=temp11->next;
                delete temp22;
                temp22=temp11;
                
            }
            temp1->next = temp11->next;
            delete temp11;
            delete temp22;


        }
        
        void display(){
            Node *temp=head;
            cout<<"head -->";
            while(temp!=nullptr){
                cout<<temp->data<<"-> ";
                temp=temp->next;
            }
            cout<<"<-- Pointer "<<endl;
        }
        
        
};

int main()
{
    LinkedList<int> r;
    LinkedList<int> r1;
    // r.push_front(4);
    // r.push_front(5);
    // r.push_front(6);
    // r.push_front(7);
    // r.push_front(8);
    // r.push_front(6);
    r.push_back(0);
    r.push_back(1);
    r.push_back(2);
    r.push_back(3);
    r.push_back(4);
    r.push_back(5);
    r.push_back(6);
    r.push_back(7);

    r1.push_back(0);
    r1.push_back(1);
    r1.push_back(2);
    r1.push_back(3);
    r1.push_back(4);
    r1.push_back(5);
    r1.push_back(6);
    r1.push_back(7);
    r1.pop_back();
    // r.push_front(10);
    // r.pushAt(4,4);
    // r.erase(2,5);
    // r.popAt(4);
    // r.pop_back();
    r.display();
    r1.display();
    return 0;
}