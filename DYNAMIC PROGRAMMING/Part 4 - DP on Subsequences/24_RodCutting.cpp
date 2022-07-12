#include <iostream>
#include <vector>
using namespace std;


// *************************  Recursion  *********************************************
// int maxCutRod(int n,vector<int>&price,int maxi){
// 	if(n==0){
// 		if(maxi>=1){return price[n]*(maxi/1);}
// 		return 0;
// 	}
// 	int not_pick = maxCutRod(n-1,price,maxi);
// 	int pick = INT_MIN;
// 	if(maxi>=n+1){
// 		pick = price[n] + maxCutRod(n,price,maxi-(n+1));
// 	}
// 	return max(not_pick,pick);
// }

//******************Dp Memoization Sollution*******************
// int maxCutRod(int n,vector<int>&price,int maxi,vector<vector<int>>&dp){
// 	if(n==0){
// 		if(maxi>=1){return price[n]*(maxi/1);}
// 		return 0;
// 	}
// 	if(dp[n][maxi] != -1){return dp[n][maxi];}
// 	int not_pick = maxCutRod(n-1,price,maxi,dp);
// 	int pick = INT_MIN;
// 	if(maxi>=n+1){
// 		pick = price[n] + maxCutRod(n,price,maxi-(n+1),dp);
// 	}
// 	return dp[n][maxi] = max(not_pick,pick);
// }

//******************Tabultaion Sollution*******************
// int maxCutRod(int n,vector<int>&price,int maxi,vector<vector<int>>&dp){
// 	for(int w=1;w<=maxi;w++){
// 		dp[0][w] = price[0]*(w/1);
// 	}
// 	for(int ind =1;ind<n;ind++){
// 		for(int w=1;w<=maxi;w++){
// 			int not_pick = dp[ind-1][w];
// 			int pick = INT_MIN;
// 			if(w>=ind+1){
// 				pick = price[ind] + dp[ind][w-(ind+1)];
// 			}
// 			dp[ind][w] = max(not_pick,pick);
// 		}
// 	}
// 	return dp[n-1][maxi];
// }

//******************Space Optimisation Sollution*******************
int maxCutRod(int n,vector<int>&price,int maxi){
	vector<int>prev(maxi+1,0);
	for(int w=1;w<=maxi;w++){
		prev[w] = price[0]*(w/1);
	}
	for(int ind =1;ind<n;ind++){
		vector<int>temp(maxi+1,0);
		for(int w=1;w<=maxi;w++){
			int not_pick = prev[w];
			int pick = INT_MIN;
			if(w>=ind+1){
				pick = price[ind] + temp[w-(ind+1)];
			}
			temp[w] = max(not_pick,pick);
		}
		prev = temp;
	}
	return prev[maxi];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>price(n);
		// vector<int>price(n);
		for(int i=0;i<n;i++){
			cin>>price[i];
		}
		int maxi = n;
		//**********************Recursion******************************
		// cout<<"Recursion Sollution "<<maxCutRod(n-1,price,maxi)<<endl;


		//******************Dp Memoization Sollution*******************
		// vector<vector<int>>dp(n,vector<int>(n+1,-1));
		// cout<<"DP Memoization Sollution "<<maxCutRod(n-1,price,maxi,dp)<<endl;


		//******************Tabulation Sollution************************
		// vector<vector<int>>dp(n,vector<int>(n+1,0));
		// cout<<"DP Memoization Sollution "<<maxCutRod(n,price,maxi,dp)<<endl;


		//******************Space Optimisation Sollution************************
		cout<<"DP Memoization Sollution "<<maxCutRod(n,price,maxi)<<endl;
	}
}