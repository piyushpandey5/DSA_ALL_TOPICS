#include<iostream>
#include<vector>
using namespace std;

// *************************** RECURSION SOLLUTION ********************************************

// int Maxprofit(int ind,bool buy, vector<int>&prices){

// 	if(ind == prices.size()){
// 		return 0;
// 	}
// 	int profit = 0;
// 	if(buy){
// 		profit = max(-(prices[ind]) + Maxprofit(ind+1, false, prices), 0 + Maxprofit(ind+1, true, prices));
// 	}

// 	else {
// 		profit = max(prices[ind] + Maxprofit(ind+1, true, prices), 0 + Maxprofit(ind+1, false, prices));
// 	}
// 	return profit;
// }

// *************************** DP MEMOIZATION SOLLUTION ********************************************

// int Maxprofit(int ind,bool buy, vector<int>&prices,vector<vector<int>>&dp){

// 	if(ind == prices.size()){
// 		return 0;
// 	}
// if(dp[ind][buy] != -1){return dp[ind][buy];}
// 	int profit = 0;
// 	if(buy){
// 		profit = max(-(prices[ind]) + Maxprofit(ind+1, false, prices,dp), 0 + Maxprofit(ind+1, true, prices,dp));
// 	}

// 	else {
// 		profit = max(prices[ind] + Maxprofit(ind+1, true, prices,dp), 0 + Maxprofit(ind+1, false, prices,dp));
// 	}
// 	return dp[ind][buy] = profit;
// }

// *************************** TABULATION SOLLUTION ********************************************

// int Maxprofit(vector<int>&prices,vector<vector<int>>&dp){
// 	int n =prices.size();
// 	dp[n][0] = 0;
// 	dp[n][1] = 0;

// 	for(int i=n-1;i>=0;i--){
// 		for(int buy=0;buy<2;buy++){
// 			int profit = 0;
// 			if(buy){
// 				profit = max(-(prices[i]) + dp[i+1][0] , 0 + dp[i+1][1]);
// 			}

// 			else {
// 				profit = max(prices[i] + dp[i+1][1], 0 + dp[i+1][0]);
// 			}
// 			dp[i][buy] = profit;	
// 		}
// 	}
// 	return dp[0][1];
	
// }

// *************************** SPACE OPTIMISED SOLLUTION ********************************************

int Maxprofit(vector<int>&prices,vector<vector<int>>&dp){
	int n =prices.size();
	// dp[n][0] = 0;
	// dp[n][1] = 0;
	vector<int>ahead(2,0);
	vector<int>curr(2,0);
	for(int i=n-1;i>=0;i--){
		for(int buy=0;buy<2;buy++){
			int profit = 0;
			if(buy){
				profit = max(-(prices[i]) + ahead[0] , 0 + ahead[1]);
			}

			else {
				profit = max(prices[i] + ahead[1], 0 + ahead[0]);
			}
			curr[buy] = profit;	
		}
		ahead = curr;
	}
	return ahead[1];
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>prices(n);
		for(int i=0;i<n;i++){
			cin>>prices[i];
		}
		bool buy = true;
		// *************************** DP MEMOIZATION SOLLUTION ********************************************
  //       vector<vector<int>>dp(n,vector<int>(2,-1));
		// cout<<Maxprofit(0, buy, prices,dp);

		// *************************** TABULATION SOLLUTION ********************************************
        vector<vector<int>>dp(n+1,vector<int>(2,0));
		cout<<Maxprofit(prices,dp);
	}
}