#include<iostream>
using namespace std;

void phone(string p, string up){
	if(up.empty()){
		cout<<p<<endl;
		return;
	}
	int digits = (int)(up[0]-'0');
	for(int i=(digits-1)*3;i<digits*3;i++){
		char ch = (char)('a'+i);
		phone(p+ch,up.substr(1));
	}
}

int main(){
	phone("","12");
}