#include<iostream>
#include<vector>
using namespace std;


// **** Recursion Sollution *****
// int triangle(int i, int j, vector<vector<int>>&v){
// 	if(i==v.size()-1)return v[i][j];
// 	int down = v[i][j] + triangle(i+1,j,v);
// 	int diag = v[i][j] + triangle(i+1,j+1,v);
// 	return min(down,diag);
// }


// **** DP memoization Sollution *****
int triangle(int i, int j, vector<vector<int>>&v, vector<vector<int>>&dp){
	if(i==v.size()-1)return v[i][j];
	if(dp[i][j]!=-1){return dp[i][j];}
	int down = v[i][j] + triangle(i+1,j,v,dp);
	int diag = v[i][j] + triangle(i+1,j+1,v,dp);
	return dp[i][j] = min(down,diag);
}


// **** Memoization to Tabulation Sollution *****
// int triangle(int i, int j, vector<vector<int>>&v, vector<vector<int>>&dp){
// 	int n = v.size();
// 	for(int j=0;j<n;j++){
// 		dp[n-1][j] = v[n-1][j];
// 	}
// 	for(int i=n-2;i>=0;i--){
// 		for(int j=i;j>=0;j--){
// 			int down = v[i][j] + dp[i+1][j];
// 			int diag = v[i][j] + dp[i+1][j+1];
// 			dp[i][j] = min(down,diag);
// 		}
// 	}
// 	return dp[0][0];
// }

// ***** Space Optimised Sollution(Most Optimised Sollution) *****
int triangle(int i, int j, vector<vector<int>>&v){
        int n = v.size();
        vector<int>prev(n,0);
        for(int j=0;j<n;j++){
            prev[j] = v[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int>temp(n,0);
            for(int j=i;j>=0;j--){
                int down = v[i][j] + prev[j];
                int diag = v[i][j] + prev[j+1];
                temp[j] = min(down,diag);
            }
            prev = temp;
        }
        return prev[0];
    }
int main(){
	vector<vector<int>>v{
		{2},{3,4},{6,5,7},{4,1,8,3}
	};
	int n = v.size();
	int m = v[0].size();
	vector<vector<int>>dp(n,vector<int>(n,-1));
	// cout<<triangle(0,0,v)<<endl;
	// cout<<triangle(0,0,v,dp)<<endl;
	cout<<triangle(0,0,v)<<endl;
}