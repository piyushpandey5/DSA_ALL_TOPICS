#include<iostream>
#include<vector>
using namespace std;

// ***** Recursion Sollution *****
// int minPathSum(int n,int m, vector<vector<int>>&grid){
// 	if(n==0 && m==0){return grid[0][0];}
// 	int up = INT_MAX;
// 	int left= INT_MAX;
// 	if(n>0)up = grid[n][m] + minPathSum(n-1,m,grid);
// 	if(m>0)left = grid[n][m] + minPathSum(n,m-1,grid);
// 	return min(up,left);
// }


// ***** Memoization Sollution *****
// int minPathSum(int n,int m, vector<vector<int>>&grid,vector<vector<int>>&dp){
// 	if(n==0 && m==0){return grid[0][0];}
// 	if(dp[n][m]!=-1){return dp[n][m];}
// 	int up = INT_MAX;
// 	int left= INT_MAX;
// 	if(n>0)up = grid[n][m] + minPathSum(n-1,m,grid,dp);
// 	if(m>0)left = grid[n][m] + minPathSum(n,m-1,grid,dp);
// 	return dp[n][m] = min(up,left);
// }

// ***** Tabulation Sollution *****
// int minPathSum(int n,int m, vector<vector<int>>&grid,vector<vector<int>>&dp){
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<m;j++){
// 			if(i==0 && j==0){dp[i][j] = grid[0][0];}
// 			else{
// 				int up = INT_MAX;
// 				int left= INT_MAX;
// 				if(i>0)up = grid[i][j] + dp[i-1][j];
// 				if(j>0)left = grid[i][j] + dp[i][j-1];
// 				dp[i][j] = min(up,left);
// 			}
// 		}
// 	}
// 	return dp[n-1][m-1];
// }

// ***** Space Optimised Sollution *****
int minPathSum(int n,int m, vector<vector<int>>&grid,vector<vector<int>>&dp){
	vector<int>prev(m,0);
	for(int i=0;i<n;i++){
		vector<int>temp(m,0);
		for(int j=0;j<m;j++){
			if(i==0 && j==0){temp[j] = grid[0][0];}
			else{
				int up = INT_MAX;
				int left= INT_MAX;
				if(i>0)up = grid[i][j] + prev[j];
				if(j>0)left = grid[i][j] + temp[j-1];
				temp[j] = min(up,left);
			}
		}
		prev = temp;
	}
	return prev[m-1];
}

int main(){
	vector<vector<int>>grid{
		{1,3,1},{1,5,1},{4,2,1}
	};
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>>dp(n,vector<int>(m,-1));
	// cout<<minPathSum(n-1,m-1,grid,dp);
	cout<<minPathSum(n,m,grid,dp);

}