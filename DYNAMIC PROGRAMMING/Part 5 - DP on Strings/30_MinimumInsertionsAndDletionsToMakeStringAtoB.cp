#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


//**********************SPACE OPTIMISED SOLLUTION *******************************************
int LCS(int i1,int i2,string str1,string str2){
	//NOTE - for tabulation base cases are required but here the index is getting negative so we 
	//		 will do the shifting of index watch here if not understood(https://youtube.com/clip/UgkxVCeBhX0ZT0SSwFecxAfkbWmHFzppHBPX)

	vector<int>prev(i2+1,0);
	vector<int>temp(i2+1,0);	
	for(int i=1;i<=i1;i++){
		for(int j=1;j<=i2;j++){
		if(str1[i-1] == str2[j-1]){temp[j] = 1 + prev[j-1];}
		else temp[j] = max(prev[j], temp[j-1]);
		}
		prev=temp;
	}
	return prev[i2];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string str1;
		cin>>str1;
		string str2;
		cin>>str2;
		int i1 = str1.size();
		int i2 = str2.size(); 
		//****************SPACE OPTMISED SOLLUTION ************************
		int palans = LCS(i1,i2,str1,str2);

//   *********Approach -  Simply add the differnece between the size of the two strings with there common subsequence
		cout<<(str1.size() - palans) + (str2.size() - palans)<<endl;
	}
}