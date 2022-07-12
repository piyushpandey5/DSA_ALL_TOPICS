#include<iostream>
#include <vector>
using namespace std;

//********************* RECURSION APPROACH ******************************************

// bool WCMatching(int n,int m,string p,string s){
// 	if(n < 0 && m < 0) return true;
// 	if(n < 0 && m >= 0) return false;
// 	if(m < 0 && n>=0 ){
// 		for(int i=0;i<=n;i++){
// 			if(p[i] != '*'){return false;}
// 		}
// 		return true;	
// 	}
// 	if(p[n]==s[m] || p[n]=='?'){
// 		return WCMatching(n-1,m-1,p,s);
// 	}
// 	if(p[n]=='*'){
// 		return WCMatching(n-1,m,p,s) || WCMatching(n,m-1,p,s);
// 	}
// 	return false;
// }

//********************* DP MEMOIZATION ******************************************

// bool WCMatching(int n,int m,string p,string s,vector<vector<int>>&dp){
// 	if(n < 0 && m < 0) return true;
// 	if(n < 0 && m >= 0) return false;
// 	if(m < 0 && n>=0 ){
// 		for(int i=0;i<=n;i++){
// 			if(p[i] != '*'){return false;}
// 		}
// 		return true;	
// 	}
// 	if(dp[n][m] != -1){return dp[n][m];}
// 	if(p[n]==s[m] || p[n]=='?'){
// 		return dp[n][m] = WCMatching(n-1,m-1,p,s,dp);
// 	}
// 	if(p[n]=='*'){
// 		return dp[n][m] = WCMatching(n-1,m,p,s,dp) || WCMatching(n,m-1,p,s,dp);
// 	}
// 	return dp[n][m] = false;
// }

//********************* TABULATION MEMOIZATION ******************************************

// bool WCMatching(string p,string s,vector<vector<bool>>&dp){
// 	int n = p.size();
// 	int m = s.size();
// 	dp[0][0] = true;

// 	for(int j=1;j<=m;j++){
// 		dp[0][j] = false;
// 	}
// 	for(int i=1;i<=n;i++){
// 		bool flag = true;
// 		for(int ii=1;ii<=i;ii++){
// 			if(p[ii-1] != '*') {
// 				flag = false;
// 				break;
// 			}
// 		}
// 		dp[i][0] = flag;

// 	}

// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=m;j++){
// 			if(p[i-1]==s[j-1] || p[i-1]=='?'){
// 				dp[i][j] = dp[i-1][j-1];
// 			}
// 			else if(p[i-1]=='*'){
// 				dp[i][j] = dp[i-1][j] || dp[i][j-1];
// 			}
// 			else dp[i][j] = false;
// 		}
// 	}
// 	for(int i=0;i<=n;i++){
// 		for(int j=0;j<=m;j++){
// 			cout<<dp[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// 	return dp[n][m];
// }


//********************* SPACE OPTIMIZATION ******************************************

bool WCMatching(string p,string s){
	int n = p.size();
	int m = s.size();
	// dp[0][0] = true;

	vector<bool>prev(m+1,false);
	vector<bool>curr(m+1,false);
	prev[0] = true;
	for(int j=1;j<=m;j++){
		prev[j] = false;
	}
	// for(int i=1;i<=n;i++){
	// 	bool flag = true;
	// 	for(int ii=1;ii<=i;ii++){
	// 		if(p[ii-1] != '*') {
	// 			flag = false;
	// 			break;
	// 		}
	// 	}
		//for every row
		//you are assigning the column 0
		// dp[i][0] = flag;

	// }

	for(int i=1;i<=n;i++){
		//here assign the 0th column for every column
		bool flag = true;
		for(int ii=1;ii<=i;ii++){
			if(p[ii-1] != '*') {
				flag = false;
				break;
			}
		}
		curr[0] = flag;
		for(int j=1;j<=m;j++){
			if(p[i-1]==s[j-1] || p[i-1]=='?'){
				curr[j] = prev[j-1];
			}
			else if(p[i-1]=='*'){
				curr[j] = prev[j] || curr[j-1];
			}
			else curr[j] = false;
		}
		prev = curr;
	}
	return prev[m];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string str1;
		string str2;
		cin>>str1;
		cin>>str2;

		int n = str1.size();
		int m = str2.size();

		//********************* RECURSION APPROACH ******************************************
		// cout<<WCMatching(n-1,m-1,str1,str2)<<endl;

		//********************* DPMEMOIZATION APPROACH ******************************************
		// vector<vector<int>> dp (n,vector<int>(m, -1));
		// cout<<WCMatching(n-1,m-1,str1,str2,dp)<<endl;

		//********************* TABULATION APPROACH ******************************************
		// vector<vector<bool>> dp (n+1,vector<bool>(m+1, false));
		// cout<<WCMatching(str1,str2,dp)<<endl;

		//********************* SPACE OPTIMISATION ******************************************
		cout<<WCMatching(str1,str2)<<endl;


	}
}