#include<iostream>
#include <cmath>
using namespace std;

int sum=0;
void reverse(int n){
    if(n==0){
        return;
    }
    int rem=n%10;
    sum=sum*10+rem;
    reverse(n/10);
    
}

// sometimes you might need some additional variables in the argument in that case ,make another function 
int helper(int n,int digits){
    if(n%10==0){
        return n;
    }
    int rem=n%10;
    return rem*pow(10,digits-1)+helper(n/10,digits-1);
}

int rev2(int n){
    int digits = int(log10(n)+1);
    return helper(n,digits);
}

int main()
{
    int n;
    cin>>n;
    cout<<rev2(n)<<endl;
    // reverse(n);
    // cout<<sum<<endl;
    // cout<<n<<endl;
    return 0;
}