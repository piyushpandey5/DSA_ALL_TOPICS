#include<iostream>
using namespace std;

void subsequence(string p, string up){
	if(up.empty()){
		cout<<p<<" ";
		return;
	}
	char ch = up[0];
	subsequence(p+ch,up.substr(1));
	subsequence(p,up.substr(1));
}


int main(){
	string str = "abc";
	subsequence("",str);
}