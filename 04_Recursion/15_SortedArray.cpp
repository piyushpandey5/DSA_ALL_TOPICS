#include<iostream>
using namespace std;

bool issorted(int arr[],int index){
	if(index== 5){return true;}	//resolve size problem in place of 5
	return arr[index]<arr[index+1] && issorted(arr,index+1);
}


int main(){
	int arr[]={2,4,6,8,45,63};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<issorted(arr,0);
}