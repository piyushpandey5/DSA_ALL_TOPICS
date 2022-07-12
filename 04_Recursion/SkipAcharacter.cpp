#include <iostream>
#include<string>
using namespace std;

string skipChar(string str){
	if(str.empty()){return "";}
	if(str[0]=='a'){
		return (""+skipChar(str.substr(1)));
	}
	else{
		return (str[0]+skipChar(str.substr(1)));
	}
}

// string skipfWord(string str2,string word){
// 	if (str2.find(word,0)==1){
// 		return str2.substr(9);
// 	}
// 	else{return str2;}
// }

int main(){
	string str="aaaaaaab";
	string str2 = "dangerousThisiswhatwecalldangerous";
	cout<<skipfWord(str2,"dangerous")<<endl;
	// cout<<skipChar(str)<<endl;
}