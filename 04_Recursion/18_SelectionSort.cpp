#include<iostream>
using namespace std;

void Selectionsort(int arr[], int r, int c, int max){
	if(r==0){return;}
	if(c<r){
		if(arr[c]>arr[max]){
			Selectionsort(arr,r,c+1,c);
		}
		else{
			Selectionsort(arr,r,c+1,max);
		}
	}
	else{
		int temp = arr[max];
		arr[max] = arr[r-1];
		arr[r-1] = temp;
		Selectionsort(arr,r-1,0,0);
	}
}

int main(){
	int arr[]={2,4,6,23,1,9,4,2};
	Selectionsort(arr,8,0,0);
	for(int i=0;i<8;i++){
		cout<<arr[i]<<" ";
	}
}