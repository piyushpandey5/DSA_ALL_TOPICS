#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];
    // for(int i:arr){
    //     cin>>i;
    // }
    for(int &i:arr){
        cin>>i;
    }
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}