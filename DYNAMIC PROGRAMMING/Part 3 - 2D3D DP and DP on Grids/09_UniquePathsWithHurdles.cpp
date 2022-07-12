#include<iostream>
#include<vector>
using namespace std;

// ***** Recursion Sollution *****
// int uniquePathsWithObstacles(int n, int m, vector<vector<int>>& obstacleGrid){
// 	if(n<0 || m<0){return 0;}
// 	if(obstacleGrid[n][m]==1){return 0;}
// 	if(n==0 && m==0){return 1;}
// 	int up = uniquePathsWithObstacles(n-1,m,obstacleGrid);
// 	int left = uniquePathsWithObstacles(n,m-1,obstacleGrid);
// 	return up+left;
// }

// ***** Memoization Sollution *****
// int uniquePathsWithObstacles(int n, int m, vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
// 	if(n<0 || m<0){return 0;}
// 	if(obstacleGrid[n][m]==1){return 0;}
// 	if(n==0 && m==0){return 1;}
// 	if(dp[n][m]!=-1){return dp[n][m];}
// 	int up = uniquePathsWithObstacles(n-1,m,obstacleGrid,dp);
// 	int left = uniquePathsWithObstacles(n,m-1,obstacleGrid,dp);
// 	return dp[n][m] = up+left;
// }

// ***** Tabulation Sollution *****
// int uniquePathsWithObstacles(int n, int m, vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<m;j++){
// 			if(obstacleGrid[i][j]==1){dp[i][j]=0;}
// 			else if(i==0 && j==0){dp[i][j]=1;}
// 			else{
// 				int up = 0;
// 				int left = 0;
// 				if(i>0)up = dp[i-1][j];
// 				if(j>0)left = dp[i][j-1];
// 				dp[i][j] = up+left;
// 			}
// 		}
// 	}
// 	return dp[n-1][m-1];
// }


// ***** Space Optimisation (Most Optimised Sollution)*****
int uniquePathsWithObstacles(int n, int m, vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
	vector<int>prev(m,0);
	for(int i=0;i<n;i++){
		vector<int>temp(m,0);
		for(int j=0;j<m;j++){
			if(obstacleGrid[i][j]==1){temp[j]=0;}
			else if(i==0 && j==0){temp[j]=1;}
			else{
				int up = 0;
				int left = 0;
				if(i>0)up = prev[j];
				if(j>0)left = temp[j-1];
				temp[j] = up+left;
			}
		}
		prev = temp;
	}
	return prev[m-1];
}

int main(){
	vector<vector<int>>obstacleGrid{
		{0,0,0},
		{0,1,0},
		{0,0,0}
	};
	int n = obstacleGrid.size();
	int m = obstacleGrid[0].size();

	vector<vector<int>>dp(n,vector<int>(m,-1));
	cout<<uniquePathsWithObstacles(n,m,obstacleGrid,dp);
}