#include<iostream>
#include <vector>
#include <string.h>
using namespace std;

//**********************RECURSIVE SOLLUTION *******************************************

// int LCS(int i1,int i2,string str1,string str2){
// 	if(i1<0 || i2<0){return 0;}
// 	if(str1[i1] == str2[i2]){return  1 + LCS(i1-1, i2-1, str1,str2);}
// 	return  max(LCS(i1-1, i2, str1,str2), LCS(i1, i2-1, str1,str2));
// }

//**********************DP MEMOIZATION SOLLUTION *******************************************

// int LCS(int i1,int i2,string str1,string str2,vector<vector<int>>&dp){
// 	if(i1<0 || i2<0){return 0;}
// 	if(dp[i1][i2]!=-1){return dp[i1][i2];}
// 	if(str1[i1] == str2[i2]){return dp[i1][i2] = 1 + LCS(i1-1, i2-1, str1,str2,dp);}
// 	return dp[i1][i2] = max(LCS(i1-1, i2, str1,str2,dp), LCS(i1, i2-1, str1,str2,dp));
// }

//**********************TABULATION SOLLUTION *******************************************

// int LCS(int i1,int i2,string str1,string str2,vector<vector<int>>&dp){
// 	//NOTE - for tabulation base cases are required but here the index is getting negative so we 
// 	//		 will do the shifting of index watch here if not understood(https://youtube.com/clip/UgkxVCeBhX0ZT0SSwFecxAfkbWmHFzppHBPX)

// 	for(int i=0;i<=i1;i++){dp[i][0] = 0;}
// 	for(int i=0;i<=i2;i++){dp[0][i] = 0;}

// 	for(int i=1;i<=i1;i++){
// 		for(int j=1;j<=i2;j++){
// 		if(str1[i-1] == str2[j-1]){dp[i][j] = 1 + dp[i-1][j-1];}
// 		else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
// 		}
// 	}
// 	return dp[i1][i2];
// }

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
		string str2;
		cin>>str1;
		cin>>str2;
		int i1 = str1.size();
		int i2 = str2.size();
		//****************RECURSIVE SOLLUTION**************************
		// cout<<LCS(i1,i2,str1,str2)<<endl;


		//****************DP MEMOIZATION SOLLUTION ********************
		// vector<vector<int>>dp(i1,vector<int>(i2,-1));
		// cout<<LCS(i1-1,i2-1,str1,str2,dp)<<endl;


		//****************TABULATION SOLLUTION ************************
		// vector<vector<int>>dp(i1+1,vector<int>(i2+1,0));
		// cout<<LCS(i1,i2,str1,str2,dp)<<endl;


		//****************SPACE OPTMISED SOLLUTION ************************
		cout<<LCS(i1,i2,str1,str2)<<endl;
	}
}