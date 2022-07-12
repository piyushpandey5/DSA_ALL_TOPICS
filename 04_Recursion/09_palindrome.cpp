#include<iostream>
#include <cmath>
using namespace std;

int sum=0;
int helper(int n,int digits){
    if(n%10==0){
        return n;
    }
    int rem=n%10;
    return rem*pow(10,digits-1)+helper(n/10,digits-1);
}

int rev(int n){
    int digits = int(log10(n)+1);
    return helper(n,digits);
}

bool palin(int n){
    if(n==rev(n)){
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    cout<<palin(n)<<endl;
    // reverse(n);
    // cout<<sum<<endl;
    // cout<<n<<endl;
    return 0;
}