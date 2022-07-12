#include<iostream>
using namespace std;

int helper(int n,int c){
    if(n==0){
        return c;
    }
    if(n%2==0){
        return helper(n/2,c+1);
    }
    return helper(n-1,c+1);
}
int numberOfSteps(int n) {
        return helper(n,0);
    }



int main()
{
    int n;
    cin>>n;
    cout<<numberOfSteps(n)<<endl;
    return 0;
}