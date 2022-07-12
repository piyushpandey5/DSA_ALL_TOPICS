#include<iostream>
using namespace std;

void sumTriangle(int arr[],int n){
    if(n<1){return;}
    int temp[n-1];
    for(int i=0;i<n-1;i++){
        temp[i]=arr[i]+arr[i+1];
    }
    sumTriangle(temp,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={2,4,6,8,10};
    sumTriangle(arr,5);
}