#include <iostream>
using namespace std;

bool find(int arr[],int size,int target){
	if(size==0){
		return false;
	}
	if(arr[size-1]==target){
		return true;
	}
	else{
		return find(arr,size-1,target);
	}
}

int main()
{
	int arr1[]={2,5,7,4,3,2};
	cout<<find(arr1,5,0)<<endl;
	return 0;
}