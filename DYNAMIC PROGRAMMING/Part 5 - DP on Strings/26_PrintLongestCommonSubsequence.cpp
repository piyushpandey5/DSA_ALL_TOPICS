#include <iostream>
#include<vector>
using namespace std;
// NOTE - SAME AS 25th
//**********************TABULATION SOLLUTION *******************************************
void LCS(int i1,int i2,string str1,string str2,vector<vector<int>>&dp){
	//NOTE - for tabulation base cases are required but here the index is getting negative so we 
	//		 will do the shifting of index watch here if not understood(https://youtube.com/clip/UgkxVCeBhX0ZT0SSwFecxAfkbWmHFzppHBPX)

	for(int i=0;i<=i1;i++){dp[i][0] = 0;}
	for(int i=0;i<=i2;i++){dp[0][i] = 0;}

	for(int i=1;i<=i1;i++){
		for(int j=1;j<=i2;j++){
		if(str1[i-1] == str2[j-1]){dp[i][j] = 1 + dp[i-1][j-1];}
		else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int len = dp[i1][i2];
	int index = len-1;
	int i=i1;
	int j=i2;
	string ans = "";
	for(int i=1;i<=len;i++){
		ans+="*";
	}
	while(i>0 && j>0){
		if(str1[i-1]==str2[j-1]){
			ans[index] =str1[i-1];
			index--;
			i--;
			j--;
		}

		else if(str1[i-1]>str2[j-1]){
			i--;
		}
		else{
			j--;
		}
	}
	cout<<ans<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string str1;
		string str2;
		cin>>str1;
		cin>>str2;
		int i1 = str1.size();
		int i2 = str2.size();

		//****************TABULATION SOLLUTION ************************
		vector<vector<int>>dp(i1+1,vector<int>(i2+1,0));
		LCS(i1,i2,str1,str2,dp);

		for(int i=0;i<=i1;i++){
			for(int j=0;j<=i2;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}