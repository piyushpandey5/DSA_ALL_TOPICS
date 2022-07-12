#include<iostream>
#include <vector>
using namespace std;

// ***************** Recursion Sollution *******************************
// int knapsack(int n,int maxWeight,vector<int>&profit,vector<int>&weight){
// 		if(n==0){
// 			if(maxWeight>=weight[0]){ return profit[0]*(maxWeight/weight[0]);}
// 			return 0;
// 		}
// 		int not_pick = knapsack(n-1,maxWeight,profit,weight);
// 		int pick = INT_MIN;
// 		if(weight[n]<=maxWeight){
// 		//NOTE -  Here Multiple Picks are allowed so don't decrease the index of pick and let the
// 			//statement only dependent on if statement	
// 			pick = profit[n] + knapsack(n,maxWeight-weight[n],profit,weight);
// 		}
// 		return max(pick,not_pick);
// }

// ***************** DP Memoization Sollution *******************************
// int knapsack(int n,int maxWeight,vector<int>&profit,vector<int>&weight,vector<vector<int>>&dp){
// 		if(n==0){
// 			if(maxWeight>=weight[0]){ return profit[0]*(maxWeight/weight[0]);}
// 			return 0;
// 		}
// 		if(dp[n][maxWeight]!=-1){return dp[n][maxWeight];}
// 		int not_pick = knapsack(n-1,maxWeight,profit,weight,dp);
// 		int pick = INT_MIN;
// 		if(weight[n]<=maxWeight){
// 		//NOTE -  Here Multiple Picks are allowed so don'd decrease the index of pick and let the
// 			//statement only dependent on if statement	
// 			pick = profit[n] + knapsack(n,maxWeight-weight[n],profit,weight,dp);
// 		}
// 		return dp[n][maxWeight] = max(pick,not_pick);
// }

// ***************** Tabulation Sollution *******************************
// int knapsack(int n,int maxWeight,vector<int>&profit,vector<int>&weight,vector<vector<int>>&dp){

// 		for(int i=weight[0];i<=maxWeight;i++){
// 			dp[0][i] = profit[0]*(i/weight[0]);
// 		}
// 		for(int ind=1;ind<n;ind++){
// 			for(int w=0;w<=maxWeight;w++){
// 				int not_pick = dp[ind-1][w];
// 				int pick = INT_MIN;
// 				if(weight[ind]<=w){
// 				//NOTE -  Here Multiple Picks are allowed so don'd decrease the index of pick and let the
// 					//statement only dependent on if statement	
// 					pick = profit[ind] + dp[ind][w-weight[ind]];
// 				}
// 				dp[ind][w] = max(pick,not_pick);
// 			}
// 		}
// 		return dp[n-1][maxWeight];			
// }

// ***************** Space Optmised Sollution Sollution *******************************
int knapsack(int n,int maxWeight,vector<int>&profit,vector<int>&weight){
		vector<int>prev(maxWeight+1,0);
		for(int i=weight[0];i<=maxWeight;i++){
			prev[i] = profit[0]*(i/weight[0]);
		}
		for(int ind=1;ind<n;ind++){
			vector<int>temp(maxWeight+1,0);
			for(int w=0;w<=maxWeight;w++){
				int not_pick = prev[w];
				int pick = INT_MIN;
				if(weight[ind]<=w){
				//NOTE -  Here Multiple Picks are allowed so don'd decrease the index of pick and let the
					//statement only dependent on if statement	
					pick = profit[ind] + temp[w-weight[ind]];
				}
				temp[w] = max(pick,not_pick);
			}
			prev=temp;
		}
		return prev[maxWeight];			
}

int main(){
	int t;cin>>t;
	while(t--){
		int n;
		cin>>n;
		int maxWeight;
		cin>>maxWeight;
		vector<int>weight(n);
		vector<int>profit(n);
		for(int i=0;i<n;i++){
			cin>>profit[i];
		}
		for(int i=0;i<n;i++){
			cin>>weight[i];
		}

		// cout<<"Recursion Sollution "<<knapsack(n-1,maxWeight,profit,weight)<<endl;
		// vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
		// cout<<"Dp Memoization Sollution "<<knapsack(n-1,maxWeight,profit,weight,dp)<<endl;	
		// vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
		// cout<<"Tabulation Sollution "<<knapsack(n,maxWeight,profit,weight,dp)<<endl;
		cout<<"Space Optimised Sollution "<<knapsack(n,maxWeight,profit,weight)<<endl;	
	}

}