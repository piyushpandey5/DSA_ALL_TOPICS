#include <iostream>
#include <vector>
using namespace std;

// *************************** RECURSION SOLLUTION ********************************************

// int Maxprofit(int ind,int buy, vector<int>&prices){

// 	if(ind >= prices.size()){
// 		return 0;
// 	}
// 	// if(cap==0){return 0;}
// 	int profit = 0;
// 	if(buy){
// 		profit = max(-(prices[ind]) + Maxprofit(ind+1, 0, prices), 0 + Maxprofit(ind+1, 1, prices));
// 	}

// 	else {
// 		profit = max(prices[ind] + Maxprofit(ind+2, 1, prices), 0 + Maxprofit(ind+1, 0, prices));
// 	}
// 	return profit;
// }


// *************************** MEMOIZATION SOLLUTION ********************************************

// int Maxprofit(int ind,int buy, vector<int>&prices,vector<vector<int>>&dp){

// 	if(ind >= prices.size()){
// 		return 0;
// 	}
// 	// if(cap>=0){return 0;}
// 	if(dp[ind][buy]!=-1){return dp[ind][buy];}
// 	int profit = 0;
// 	if(buy){
// 		profit = max(-(prices[ind]) + Maxprofit(ind+1, 0, prices,dp), 0 + Maxprofit(ind+1, 1, prices,dp));
// 	}

// 	else {
// 		profit = max(prices[ind] + Maxprofit(ind+2, 1, prices,dp), 0 + Maxprofit(ind+1, 0, prices,dp));
// 	}
// 	return dp[ind][buy] = profit;
// }


// *************************** TABULATION SOLLUTION ***************************************************

// int Maxprofit(vector<int>&prices,vector<vector<int>>&dp){
// 	int n = prices.size();

// 	for(int ind =n-1;ind>=0;ind--){
// 		for(int buy=0;buy<2;buy++){
// 				int profit = 0;
// 				if(buy){
// 					profit = max(-(prices[ind]) + dp[ind+1][0], 0 + dp[ind+1][1]);
// 				}

// 				else {
// 					profit = max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);
// 				}
// 				dp[ind][buy] = profit;
// 		}
// 	}
// 	return dp[0][1];

// }

// *************************** TABULATION SOLLUTION ***************************************************


int Maxprofit(vector<int>&prices){
	int n = prices.size();
	vector<int>ahead(2,0);
	vector<int>curr(2,0);
	int twoahead = 0;
	for(int ind =n-1;ind>=0;ind--){
		for(int buy=0;buy<2;buy++){
				int profit = 0;
				if(buy){
					profit = max(-(prices[ind]) + ahead[0], 0 + ahead[1]);
				}

				else {
					profit = max(prices[ind] + twoahead, 0 + ahead[0]);
				}
				curr[buy] = profit;
		}
		twoahead = ahead[1];
		ahead = curr;
	}
	return ahead[1];

}

// ********************try to do the most optimsed sollution form striver by taking n*4 transaction
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

		int buy  =	1;
		//RECURSION
		// cout<<Maxprofit(0,buy,prices);

		//DP MEMOIZATION
		// vector<vector<int>>dp(n,vector<int>(2,-1));
		// cout<<Maxprofit(0,buy,prices,dp);

		//TABULATION
		// vector<vector<int>>dp(n+2,vector<int>(2,0));
		// cout<<Maxprofit(prices,dp)<<endl;

		// SPACE OPTIMSIED
		cout<<Maxprofit(prices);
	}
}