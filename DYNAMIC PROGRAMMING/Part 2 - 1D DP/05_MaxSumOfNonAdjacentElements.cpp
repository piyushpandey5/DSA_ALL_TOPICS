// Maximum sum of non-adjacent elements [ CodingNizas ]

#include<iostream>
#include<vector>
using namespace std;

// ****** Simply Recursive ****** 

// int MaxNonAdjSum(int ind, vector<int>&arr){
// 	if(ind==0){return arr[0];}
// 	if(ind<0){return 0;}
// 	int picked = arr[ind] + MaxNonAdjSum(ind-2,arr);
// 	int Not_picked = 0 + MaxNonAdjSum(ind-1,arr);
// 	return  max(picked,Not_picked);
// }

// ****** Recursive to DP array memoization sollution ******
// int MaxNonAdjSum(int ind, vector<int>&arr,vector<int>&dp){
// 	if(ind==0){return arr[0];}
// 	if(ind<0){return 0;}
// 	if(dp[ind]!=-1){return dp[ind];}
// 	int picked = arr[ind] + MaxNonAdjSum(ind-2,arr,dp);
// 	int Not_picked = 0 + MaxNonAdjSum(ind-1,arr,dp);
// 	return dp[ind] = max(picked,Not_picked);
// }

// ****** memoization to tabultaion ******
// int MaxNonAdjSum(int ind, vector<int>&arr,vector<int>&dp){
// 	dp[0] = arr[0];
// 	for(int i=1;i<arr.size();i++){
// 		int picked = arr[i];
// 		if(i>1)
// 			picked += dp[i-2];
// 		int Not_picked = 0 + dp[i-1];
// 		dp[i] = max(picked,Not_picked);	
// 	}
// 	return dp[ind];
// }


// ****** FINAL SPACE OPTIMISED SOLLUTION ******
// int MaxNonAdjSum(int ind, vector<int>&arr){
// 	int prev = arr[0];
// 	int prev2 = 0;
// 	for(int i=1;i<arr.size();i++){
// 		int picked = arr[i];
// 		if(i>1)
// 			picked += prev2;
// 		int Not_picked = 0 + prev;
// 		int curr = max(picked,Not_picked);
// 		prev2 = prev;
// 		prev = curr;	
// 	}
// 	return prev;
// }

int main(){
	vector<int>arr{1,2,3,4,5,6,1,2,3,4,5,6,1,2,3,4,5,6,7};
	vector<int>dp(arr.size(),-1);
	// cout<<"This is the recursive sollution - "<<MaxNonAdjSum(3,arr);
	// cout<<"This is the recursive to dp array memoization sollution - "<<MaxNonAdjSum(3,arr,dp);
	// cout<<"This is the tabultation sollution - "<<MaxNonAdjSum(3,arr,dp);
	cout<<"This is the Space Optimised sollution - "<<RobMax(18,arr);
}