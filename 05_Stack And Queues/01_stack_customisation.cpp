#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// STACK THROW **ARRAY** AND ***LINKEDLIST***

class Stack{
	int top;

public:
	int a[MAX];
	Stack(){top = -1;}
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};

bool Stack:: push(int x){
	if(top>(MAX-1)){
		cout<<"Stack Overflow"<<endl;
		return false;
	}
	else{
		a[++top]=x;
		cout<<"pushed into stack"<<endl;
		return true;
	}

}
int Stack:: pop(){
	if(top<0){
		cout<<"Stack underflown"<<endl;
		return 0;
	}
	else{
		int x = a[top--];
		return x;
	}
}
int Stack::peek(){
	if(top<0){
		cout<<"Stack empty"<<endl;
		return 0;
	}
	else{
		int x = a[top];
		return x;
	}
}
bool Stack::isEmpty(){
	return (top<0);
}


int main(){
	Stack x;
	x.push(3);
	x.push(5);
	x.push(4);
	x.push(8);
	cout<<s.pop();
	while(s.isEmpty()){
		cout<<s.peek()<<endl;
		s.pop();
	}

}