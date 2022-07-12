#include<iostream>
using namespace std;

int s=2;
int *arr = new int[s];
int p=0;
void push(int num){

	if(p==s){s*=2;}

	for(int i=0;i<s;i++){
		if(arr[i]==0){
			arr[i]=num;
			p++;
			break;
		}
	}
	for(int i=0;i<s;i++){
		cout<<*arr[i]<<" ";
	}
}


int main(){
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);
}