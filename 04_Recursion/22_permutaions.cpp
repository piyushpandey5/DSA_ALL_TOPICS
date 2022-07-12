#include<iostream>
// #include<string>
// #include<cstring>
using namespace std;

void permutaions(string p,string up){
	if(up.empty()){
		cout<<p<<endl;
		return;
	}
	char ch = up[0];
	for(int i=0;i<p.length();i++){
		string f = p.substr(0,i);
		string s = p.substr(i,p.length());
		permutaions(f + ch + s, up.substr(1)); 
	}
}

int main(){
	// string str="abc";
	permutaions("","abc");
	// cout<<"a"+1<<endl;
}