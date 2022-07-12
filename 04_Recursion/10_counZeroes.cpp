#include<iostream>
using namespace std;

int helper(int n,int c){
    if(n==0){
        return c;          //special values to call the return same value to the above funtion calls
    }
    int rem=n%10;
    if(rem==0){
        return helper(n/10,c+1);
    }
    return helper(n/10,c);
}

int czero(int n){
    return helper(n,0);
}



int main()
{
    int n;
    cin>>n;
    cout<<czero(n)<<endl;
    return 0;
}