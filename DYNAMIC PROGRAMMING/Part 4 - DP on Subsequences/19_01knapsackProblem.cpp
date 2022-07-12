#include<iostream>
#include<vector>
using namespace std;

// ********************** Recursion Sollution **************************************

// int knapsack(vector<int>&weight,vector<int>&value,int n,int maxWeight){
// 	if(n==0){
// 		if(maxWeight>=weight[0]){return value[0];}
// 		else return 0;
// 	}
// 	int not_pick = 0 + knapsack(weight,value,n-1,maxWeight);
// 	int pick = INT_MIN;
// 	if(weight[n]<=maxWeight){
// 		pick = value[n] + knapsack(weight,value,n-1,maxWeight-weight[n]);  
// 	}
// 	return max(pick,not_pick);
// }

// ******************** Memoization Sollution ***************************************

// int knapsack(vector<int>&weight,vector<int>&value,int n,int maxWeight,vector<vector<int>>&dp){
// 	if(n==0){
// 		if(maxWeight>=weight[0]){return value[0];}
// 		else return 0;
// 	}
// 	if(dp[n][maxWeight]!=-1){return dp[n][maxWeight];}
// 	int not_pick = 0 + knapsack(weight,value,n-1,maxWeight,dp);
// 	int pick = INT_MIN;
// 	if(weight[n]<=maxWeight){
// 		pick = value[n] + knapsack(weight,value,n-1,maxWeight-weight[n],dp);  
// 	}
// 	return dp[n][maxWeight] =  max(pick,not_pick);
// }

// *********************** Tabulation **************************************************

// int knapsackAns(vector<int>&weight,vector<int>&value,int n,int maxWeight,vector<vector<int>>&dp){
//     for(int i=weight[0];i<=maxWeight;i++){
//         dp[0][i] = value[0];
//     }
//     for(int ind=1;ind<n;ind++){
//         for(int w = 0;w<=maxWeight;w++){
//             int not_pick = 0 + dp[ind-1][w];
//             int pick = INT_MIN;
//             if(weight[ind]<=w){
//                 pick = value[ind] + dp[ind-1][w-weight[ind]];  
//             }
//             dp[ind][w] =  max(pick,not_pick);
//         }
//     }
//     return dp[n-1][maxWeight];
// }

//  *************** Space Optimised Sollution *************************************

// int knapsack(vector<int>&weight,vector<int>&value,int n,int maxWeight){
// 	vector<int>prev(maxWeight+1,0);
// 	for(int i=weight[0];i<=maxWeight;i++){
// 		prev[i] = value[0];
// 	}
// 	for(int ind=1;ind<n;ind++){
// 		vector<int>temp(maxWeight+1,0);
// 		for(int w = 0;w<=maxWeight;w++){
// 			int not_pick = 0 + prev[w];
// 			int pick = INT_MIN;
// 			if(weight[ind]<=w){
// 				pick = value[ind] + prev[w-weight[ind]];  
// 			}
// 			temp[w] =  max(pick,not_pick);
// 		}
// 		prev=temp;
// 	}
// 	return prev[maxWeight];
// }

//  ************ Most Space Optimised Sollution(https://youtube.com/clip/UgkxHpehD2xA4PfPPe0T2P90aK2x7p1uVtmO) ****

int knapsack(vector<int>&weight,vector<int>&value,int n,int maxWeight){
	vector<int>prev(maxWeight+1,0);
	for(int i=weight[0];i<=maxWeight;i++){
		prev[i] = value[0];
	}
	for(int ind=1;ind<n;ind++){
		// vector<int>temp(maxWeight+1,0);
		for(int w = maxWeight;w>=0;w--){
			int not_pick = 0 + prev[w];
			int pick = INT_MIN;
			if(weight[ind]<=w){
				pick = value[ind] + prev[w-weight[ind]];  
			}
			prev[w] =  max(pick,not_pick);
		}
		// prev=temp;
	}
	return prev[maxWeight];
}

int main(){
	int n;
	cin>>n;
	vector<int>weight(n);
	vector<int>value(n);
	for(int i=0;i<n;i++){
		cin>>weight[i];
	}
	for(int i=0;i<n;i++){
		// cin>>weight[i];
		cin>>value[i];
	}

	int maxWeight;
	cin>>maxWeight;

	// cout<<"Recursion Sollution "<<knapsack(weight,value,n-1,maxWeight);
	// vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	// cout<<"Recursion Memoization Sollution "<<knapsack(weight,value,n-1,maxWeight,dp);
	// vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
	// cout<<"Tabulation Sollution "<<knapsack(weight,value,n,maxWeight,dp);
	cout<<"Space Optimised Sollution "<<knapsack(weight,value,n,maxWeight);
}