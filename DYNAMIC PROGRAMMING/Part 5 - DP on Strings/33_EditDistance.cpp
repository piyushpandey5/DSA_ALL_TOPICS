#include<iostream>
#include<vector>
using namespace std;

//**************************RECURSION*********************************************************

// int minOperations(int m, int n, string str1,string str2){
// 	if(m<0){
// 		return n+1;
// 	}
// 	if(n<0){
// 		return m+1;
// 	}

// 	if(str1[m] == str2[n]){return minOperations(m-1,n-1,str1,str2);}
// 	else {
// 		int insert = 1 + minOperations(m,n-1,str1,str2);
// 		int del = 1 +  minOperations(m-1,n,str1,str2);
// 		int replace = 1 +  minOperations(m-1,n-1,str1,str2);
// 		return min(insert, min(del,replace));
// 	}

// }

//************************ DP MEMOIZATION ****************************************************

// int minOperations(int m, int n, string str1,string str2, vector<vector<int>>&dp){
// 	if(m<0){
// 		return n+1;
// 	}
// 	if(n<0){
// 		return m+1;
// 	}
// 	if(dp[m][n]!=-1){return dp[m][n];}

// 	if(str1[m] == str2[n]){return minOperations(m-1,n-1,str1,str2,dp);}
// 	else {
// 		int insert = 1 + minOperations(m,n-1,str1,str2,dp);
// 		int del = 1 +  minOperations(m-1,n,str1,str2,dp);
// 		int replace = 1 +  minOperations(m-1,n-1,str1,str2,dp);
// 		return dp[m][n] = min(insert, min(del,replace));
// 	}

// }

//************************ TABULATION ****************************************************

// int minOperations(int m, int n, string str1,string str2, vector<vector<int>>&dp){
// 	for(int j=0;j<=n;j++){dp[0][j] = j;}
// 	for(int i=0;i<=m;i++){dp[i][0] = i;}

// 	for(int i=1;i<=m;i++){
// 		for(int j=1;j<=n;j++){
// 			if(str1[i-1] == str2[j-1]){dp[i][j] = dp[i-1][j-1];}
// 			else {
// 				int insert = 1 + dp[i][j-1];
// 				int del = 1 +  dp[i-1][j];
// 				int replace = 1 +  dp[i-1][j-1];
// 				dp[i][j] = min(insert, min(del,replace));
// 			}
// 		}
// 	}
// 	return dp[m][n];


// }


//************************ SPACE OPTIMISED SOLLUTION ****************************************************

int minOperations(int m, int n, string str1,string str2){
	vector<int>prev(n+1,0);
	for(int j=0;j<=n;j++){prev[j] = j;}
	// for(int i=0;i<=m;i++){dp[i][0] = i;}

	for(int i=1;i<=m;i++){
		vector<int>curr(n+1,0);
		curr[0] = i;
		for(int j=1;j<=n;j++){
			if(str1[i-1] == str2[j-1]){curr[j] = prev[j-1];}
			else {
				int insert = 1 + curr[j-1];
				int del = 1 +  prev[j];
				int replace = 1 +  prev[j-1];
				curr[j] = min(insert, min(del,replace));
			}
		}
		prev = curr;
	}
	return prev[n];
}




int main(){
	int t;
	cin>>t;
	while(t--){
		string str1;
		string str2;

		cin>>str1;
		cin>>str2;
		int m = str1.size();
		int n = str2.size();

		// RECUSRION
		// cout<<minOperations(m-1,n-1,str1,str2);	

		// DP MEMOIZATION
		// vector<vector<int>>dp(m,vector<int>(n,-1));
		// cout<<minOperations(m-1,n-1,str1,str2,dp);


		// TABULATION
		// vector<vector<int>>dp(m+1,vector<int>(n+1,0));
		// cout<<minOperations(m,n,str1,str2,dp);

		// SPACE OPTIMISED
		vector<vector<int>>dp(m+1,vector<int>(n+1,0));
		cout<<minOperations(m,n,str1,str2);
	}
}