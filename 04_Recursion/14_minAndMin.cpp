#include<iostream>
using namespace std;
int mini=8784;
int maxi=-4585;
void findMinMax(int arr[],int n){
	if(n-1<0){
		return;
	}
	if(arr[n-1]<mini){mini=arr[n-1];}
	if(arr[n-1]>maxi){maxi=arr[n-1];}
	return findMinMax(arr,n-1);	
}

int main(){
	int arr[]={2,5,2,6,7,4};
	findMinMax(arr,6);
	cout<<"the minimum number is, "<<mini<<endl;
	cout<<"the maximum number is, "<<maxi<<endl;
}