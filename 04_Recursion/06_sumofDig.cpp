#include<iostream>
using namespace std;

int sumofDig(int n){
    if(n==0){
        return 0;
    }
    return n%10+sumofDig(n/10); 
}

int main()
{
    int n;
    cin>>n;
    cout<<sumofDig(n)<<endl;
    return 0;
}