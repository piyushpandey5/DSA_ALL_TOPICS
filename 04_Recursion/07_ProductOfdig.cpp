#include<iostream>
using namespace std;

int prodofDig(int n){
    if(n==0){
        return 1;
    }
    return n%10*prodofDig(n/10); 
}

int main()
{
    int n;
    cin>>n;
    cout<<prodofDig(n)<<endl;
    return 0;
}

// ********Concept********
// ***********************
//          n--
//          --n