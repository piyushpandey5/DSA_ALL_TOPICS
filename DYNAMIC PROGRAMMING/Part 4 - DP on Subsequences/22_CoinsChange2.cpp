#include<iostream>
#include<vector>
using namespace std;

// ********************** Recursive Sollution *******************************

// int coinsCount(int n,vector<int>&coins,int target){
// 	if(n==0){
// 		if(target%coins[0]==0){
// 			return 1;
// 		}
// 		return 0;
// 	}
// 	int not_pick =  coinsCount(n-1,coins,target);
// 	int pick = 0;
// 	if(target>=coins[n]){
// // IMP NOTE - if you are free to use values infinite times then dont reduce 
// // 				index of picked statement while recursion just give the required condition
// 		pick = coinsCount(n,coins,target-coins[n]);
// 	}
// 	return pick+not_pick;
// }

//  ********************* DP Memoization SOllution *******************************

// int coinsCount(int n,vector<int>&coins,int target,vector<vector<int>>&dp){
// 	if(n==0){
// 		if(target%coins[0]==0){
// 			// return target/coins[0];
// 			return 1;
// 		}
// 		return 0;
// 	}
// 	if(dp[n][target] != -1){return dp[n][target];}
// 	int not_pick = coinsCount(n-1,coins,target,dp);
// 	int pick = 0;
// 	if(target>=coins[n]){
// 		pick = coinsCount(n,coins,target-coins[n],dp);
// 	}
// 	return dp[n][target] = pick+not_pick; 
// }

//  ********************* Tabulation Sollution ***********************

// int coinsCount(int n,vector<int>&coins,int target,vector<vector<int>>&dp){
// 	for(int t=0;t<=target;t++){
// 		if(t%coins[0]==0){
// 			dp[0][t] = 1;
// 		}
// 		else dp[0][t] = 0;
// 	} 
// 	for(int ind =1;ind<n;ind++){
// 		for(int t=0;t<=target;t++){
// 			int not_pick = 0 + dp[ind-1][t];
// 			int pick = 0;
// 			if(t>=coins[ind]){
// 				pick = dp[ind][t-coins[ind]];
// 			}
// 			dp[ind][t] = pick+not_pick;
// 		}
// 	}
// 	return dp[n-1][target];
// }

// **************** Space Optimised Sollution ******************************

int coinsCount(int n,vector<int>&coins,int target){
	vector<int>prev(target+1,0);
	for(int t=0;t<=target;t++){
		if(t%coins[0]==0){
			prev[t] = 1;
		}
		else prev[t] = 0;
	} 
	for(int ind =1;ind<n;ind++){
		vector<int>temp(target+1,0);
		for(int t=0;t<=target;t++){
			int not_pick = prev[t];
			int pick = 0;
			if(t>=coins[ind]){
				pick = temp[t-coins[ind]];
			}
			temp[t] = pick + not_pick;
		}
		prev = temp;
	}
	return prev[target];
}

int main(){
	int n;
	cin>>n;
	vector<int>coins(n);
	for(int i=0;i<n;i++){
		cin>>coins[i];
	}
	int target;
	cin>>target;

	//******   Recursive Sollution   ******
	// int ans = coinsCount(n-1,coins,target);
	// if(ans>=1e9){
	// 	cout<<-1<<endl;
	// }
	// else {
	// 	cout<<" Recursive Sollution "<<ans;
	// }

	//******   Dp Memoization Sollution  ******
	// vector<vector<int>>dp(n,vector<int>(target+1,-1));

	// int ans = coinsCount(n-1,coins,target,dp);
	// if(ans>=1e9){
	// 	cout<<-1<<endl;
	// }
	// else {
	// 	cout<<"Dp Memoization Sollution "<<ans<<endl;
	// }

	// ********  Tabulation Sollution  **************
	// vector<vector<int>>dp(n,vector<int>(target+1,0));
	// int ans = coinsCount(n,coins,target,dp);
	// if(ans>=1e9){
	// 	cout<<-1<<endl;
	// }
	// else {
	// 	cout<<"Tabulation Sollution "<<ans<<endl;
	// }

	int ans = coinsCount(n,coins,target);
	if(ans>=1e9){
		cout<<-1<<endl;
	}
	else {
		cout<<"Space Optimised "<<ans<<endl;
	}

}