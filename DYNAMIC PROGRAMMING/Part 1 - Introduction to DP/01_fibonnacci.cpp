// First approcah will be using a dp array

#include<iostream>
#include<vector>
using namespace std;

// int fib(int n,vector<int>&dp){
// 	if(n<2){return n;}
// 	if(dp[n]!=-1){return dp[n];}\
// 	return dp[n] = fib(n-1,dp)+fib(n-2,dp);
// }

// int main(){
// 	int N;
// 	cin>>N;
// 	vector<int>dp(N+1,-1);
// 	cout<<fib(N,dp)<<endl;
// }

// Second approch will be tabular 
int main(){
	int N;
	cin>>N;
	int prev = 1, prev2 = 0;	
	for(int i=2;i<=N;i++){
		int curr = prev + prev2;
		prev2 = prev;
		prev=curr;
	}
	cout<<prev<<endl;
}