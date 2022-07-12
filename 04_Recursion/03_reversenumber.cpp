#include<iostream>
using namespace std;

void reverse(int n){
    if(n==0){
        return;
    }

    cout<<n<<endl;
    reverse(n-1);
}

void prstraight(int n){
    if(n==0){
        return;
    }

    prstraight(n-1);
    cout<<n<<endl;
}
void prboth(int n){
    if(n==0){
        return;
    }

    cout<<n<<endl;
    prboth(n-1);
    cout<<n<<endl;
}

int main()
{
    int n;
    cin>>n;
    // reverse(n);
    prboth(n);
    cout<<endl;

    // prstraight(n);
    return 0;
}