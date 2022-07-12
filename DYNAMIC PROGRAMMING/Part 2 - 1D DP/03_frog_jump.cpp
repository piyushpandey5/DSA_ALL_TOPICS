#include<iostream>
#include<vector>
using namespace std;


// ******Simple Recursion Sollution *****
// int frogJump(int ind, vector<int>heights){
// 	if(ind == 0){return 0;}
// 	int left = frogJump(ind-1,heights) + abs(heights[ind]-heights[ind-1]);
// 	int right = INT_MAX;
// 	if(ind>1)right = frogJump(ind-2,heights) + abs(heights[ind]-heights[ind-2]);
// 	return min(left,right);
// }


// ******** Recursion ---> DP MEMOIZATION ********
// int frogJump(int ind, vector<int>heights,vector<int>&dp){
// 	if(ind == 0){return 0;}
// 	if(dp[ind] != -1){return dp[ind];}
// 	int left = frogJump(ind-1,heights,dp) + abs(heights[ind]-heights[ind-1]);
// 	int right = INT_MAX;
// 	if(ind>1)right = frogJump(ind-2,heights,dp) + abs(heights[ind]-heights[ind-2]);
// 	return dp[ind] = min(left,right);
// }


// ******* DP with Tabulation *******
// int frogJump(int ind, vector<int>heights,vector<int>&dp){
// 	dp[0] = 0;
// 	for(int i=1;i<ind;i++){
// 		int left = dp[i-1] + abs(heights[i]-heights[i-1]);
// 		int right = INT_MAX;
// 		if(ind>1)right = dp[i-2] + abs(heights[i]-heights[i-2]);
// 		dp[i] = min(left,right);
// 	}
// 	return dp[ind-1];
// }

// ******* Space Otimization *******
int frogJump(int ind, vector<int>heights,vector<int>&dp){
	int jumpOne = 0;
	int jumpTwo;
	for(int i=1;i<ind;i++){
		int left = jumpOne + abs(heights[i]-heights[i-1]);
		int right = INT_MAX;
		if(ind>1)right = jumpTwo + abs(heights[i]-heights[i-2]);
		int curr = min(left,right);
		jumpTwo = jumpOne;
		jumpOne = curr;
	}
	return jumpOne;
}


int main(){
	vector<int>heights{30, 10, 60 , 10 , 60 , 50};
	int n = heights.size();
	vector<int>dp(n,-1);
	// cout<<frogJump(n-1,heights);        //	Simple Recursion Sollution
	// cout<<frogJump(n-1,heights,dp);     //	Recursion to DP
	// cout<<frogJump(n,heights,dp);          //	DP with Tabulation
	cout<<frogJump(n,heights,dp);
}