#include <iostream>
#include <vector>
using namespace std;

// *************************** RECURSION SOLLUTION ********************************************

// int Maxprofit(int ind,int buy, vector<int>&prices,int k){

// 	if(ind == prices.size()){
// 		return 0;
// 	}
// 	if(k==0){return 0;}
// 	int profit = 0;
// 	if(buy){
// 		profit = max(-(prices[ind]) + Maxprofit(ind+1, 0, prices,k) , 0 + Maxprofit(ind+1, 1, prices,k));
// 	}

// 	else {
// 		profit = max(prices[ind] + Maxprofit(ind+1, 1, prices,k-1), 0 + Maxprofit(ind+1, 0, prices,k));
// 	}
// 	return profit;
// }


// *************************** MEMOIZATION SOLLUTION ********************************************

int Maxprofit(int ind,int buy, vector<int>&prices,int k,vector<vector<vector<int>>>&dp){

	if(ind == prices.size()){
		return 0;
	}
	if(k==0){return 0;}
	if(dp[ind][buy][k]!=-1){return dp[ind][buy][k];}
	int profit = 0;
	if(buy){
		profit = max(-(prices[ind]) + Maxprofit(ind+1, 0, prices,k,dp), 0 + Maxprofit(ind+1, 1, prices,k,dp));
	}

	else {
		profit = max(prices[ind] + Maxprofit(ind+1, 1, prices,k-1,dp), 0 + Maxprofit(ind+1, 0, prices,k,dp));
	}
	return dp[ind][buy][k] = profit;
}


// *************************** TABULATION SOLLUTION ***************************************************

// int Maxprofit(vector<int>&prices,vector<vector<vector<int>>>&dp, int k){
// 	int n = prices.size();

// 	for(int ind =n-1;ind>=0;ind--){
// 		for(int buy=0;buy<2;buy++){
// 			for(int cap=1;cap<=k;cap++){
// 				int profit = 0;
// 				if(buy){
// 					profit = max(-(prices[ind]) + dp[ind+1][0][cap], 0 + dp[ind+1][1][cap]);
// 				}

// 				else {
// 					profit = max(prices[ind] + dp[ind+1][1][cap-1], 0 + dp[ind+1][0][cap]);
// 				}
// 				dp[ind][buy][cap] = profit;
// 			}
// 		}
// 	}
// 	return dp[0][1][k];

// }

// *************************** SPACE OPTIMISATION SOLLUTION ***************************************************

int Maxprofit(vector<int>&prices,int k){
	int n = prices.size();
	vector<vector<int>>ahead(2,vector<int>(k+1,0));
	vector<vector<int>>temp(2,vector<int>(k+1,0));
	for(int ind =n-1;ind>=0;ind--){
		for(int buy=0;buy<2;buy++){
			for(int cap=1;cap<=k;cap++){
				int profit = 0;
				if(buy){
					profit = max(-(prices[ind]) + ahead[0][cap], 0 + ahead[1][cap]);
				}

				else {
					profit = max(prices[ind] + ahead[1][cap-1], 0 + ahead[0][cap]);
				}
				temp[buy][cap] = profit;
			}
		}
		ahead = temp;
	}
	return ahead[1][k];

}

// ********************try to do the most optimsed sollution form striver by taking n*4 transaction
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int k;
		cin>>k;
		vector<int>prices(n);
		for(int i=0;i<n;i++){
			cin>>prices[i];
		}

		int buy  =	1;
		//RECURSION
		// cout<<Maxprofit(0,buy,prices,k);

		//DP MEMOIZATION
		// vector<vector<vector<int>>>dp(n,vector<vector<int>>(buy+1,vector<int>(k+1,-1)));
		// cout<<Maxprofit(0,buy,prices,k,dp);

		//TABULATION
		// vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(buy+1,vector<int>(k+1,0)));
		// cout<<Maxprofit(prices,dp,k)<<endl;

		// SPACE OPTIMSIED
		cout<<Maxprofit(prices,k);
	}
}