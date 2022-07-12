#include<iostream>
#include<vector>
using namespace std;


// ********************* Recursion Sollution ********************************************

// int uniquePaths(int n,int m){
// 	if(n==0 && m==0){return 1;}
// 	if(n<0 || m<0){return 0;}
// 	int up = uniquePaths(n-1,m);
// 	int left = uniquePaths(n,m-1);
// 	return up+left;
// }

// ******************** Memoization DP Sollution ********************************************

	// int uniquePaths(int n,int m,vector<vector<int>>&dp){
	// 	if(n==0 && m==0){return 1;}
	// 	if(n<0 || m<0){return 0;}
	// 	if(dp[n][m] != -1)return dp[n][m];
	// 	int up = uniquePaths(n-1,m,dp);
	// 	int left = uniquePaths(n,m-1,dp);
	// 	return dp[n][m] = up+left;
	// }

// ******************* Tabulation Sollution **************************************************

// int uniquePaths(int n,int m,vector<vector<int>>&dp){
// 		for(int i=0;i<n;i++){
// 			for(int j=0;j<m;j++){
// 				if(i==0 && j==0){dp[i][j]=1;}
// 				else{
// 					int up=0,left=0;
// 					if(i>0){up = dp[i-1][j];}
// 					if(j>0){left = dp[i][j-1];}
// 					dp[i][j] = up+left;
// 				}
// 			}
// 		}
// 		return dp[n-1][m-1];
// 	}

// ****************** Space Optimised Sollution ********************************************

int uniquePaths(int n,int m,vector<vector<int>>&dp){
		vector<int>prev(m,0);
		for(int i=0;i<n;i++){
			vector<int>temp(m,0);
			for(int j=0;j<m;j++){
				if(i==0 && j==0){temp[j]=1;}

				else{
					int up=0;
					int left = 0;
					if(i>0) up = prev[j];
					if(j>0) left = temp[j-1];
					temp[j] = up+left;
				}
			}
			prev = temp;
		}
		return prev[m-1];
	}



int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>dp(n,vector<int>(m,-1));
	// cout<<uniquePaths(n-1,m-1,dp)<<endl;
	cout<<uniquePaths(n,m,dp)<<endl;
}