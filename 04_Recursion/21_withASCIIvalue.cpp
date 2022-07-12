#include<iostream>
using namespace std;
void ASCIIsequence(string p, string up){
	if(up.empty()){
		cout<<p<<endl;
		return;
	}
	char ch = up[0];
	ASCIIsequence(p+ch,up.substr(1));
	ASCIIsequence(p,up.substr(1));
	ASCIIsequence(p+to_string(ch+0),up.substr(1));
}


int main(){
	string str = "abc";
	ASCIIsequence("",str);
}