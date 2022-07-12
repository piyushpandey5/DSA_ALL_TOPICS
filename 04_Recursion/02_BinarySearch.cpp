#include<iostream>
using namespace std;

int BinarySearch(int arr[],int target, int s, int e){
    if(s > e){
        return -1;
    }
    int m=s + ( e - s ) / 2;
    if(arr[m] == target){
        return m; 
    }
    if(target<arr[m]){
        return BinarySearch(arr,target,s,m-1);
    }
    
    return BinarySearch(arr,target,m+1,e);
    
    
    
}

int main()
{
    int arr[]={-1,0,3};
    int target=-1;
    int len = sizeof(arr)/sizeof(arr[0]); 
    cout<<BinarySearch(arr,target,0,len-1)<<endl;
    return 0;
}