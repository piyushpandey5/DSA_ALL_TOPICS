#include<iostream>
#include<string>
using namespace std;

string reverseString(string s){
    if(s.length()==1){return s;}
    string x;
    x = s[s.length()-1];
    s.resize(s.length()-1);
    
    return x+reverseString(s);
}

int main()
{
    string s;
    cin>>s;
    cout<<reverseString(s)<<endl;
    return 0;
}