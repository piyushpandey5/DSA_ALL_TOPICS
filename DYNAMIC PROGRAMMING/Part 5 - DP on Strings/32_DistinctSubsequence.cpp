#include <iostream>
#include <vector>
using namespace std;


//*******************RECURSION SOLLUTION*****************************************************

// int DistinctSubsequence(int i,int j,string s,string t){
// 	if(j<0){return 1;}
// 	if(i<0){return 0;}
// 	if(s[i] == t[j]){
// 		return DistinctSubsequence(i-1,j-1,s,t) + DistinctSubsequence(i-1,j,s,t);
// 	}
// 	else
// 		return DistinctSubsequence(i-1,j,s,t);
// }

//*******************MEMOIZATION SOLLUTION*****************************************************

// int DistinctSubsequence(int i,int j,string &s,string &t, vector<vector<int>>&dp){
//         if(j<0){return 1;}
//         if(i<0){return 0;}
//         if(dp[i][j]!=-1){return dp[i][j];}
//         if(s[i] == t[j]){
//             return dp[i][j] =  DistinctSubsequence(i-1,j-1,s,t,dp) + DistinctSubsequence(i-1,j,s,t,dp);
//         }
//         else
//             return dp[i][j] = DistinctSubsequence(i-1,j,s,t,dp);
// }

//*******************MEMOIZATION SOLLUTION*****************************************************

// NOTE - Here we are doing tabultation but with shift indexing method,for more(https://youtube.com/clip/UgkxVCeBhX0ZT0SSwFecxAfkbWmHFzppHBPX)

// int DistinctSubsequence(int n,int m,string s,string t,vector<vector<int>>&dp){
// 	for(int i=0;i<=n;i++){dp[i][0] = 1;} //if t string reches to -1 index fill it with 1 because it means that we found an subsequence of s which is equals to t
// 	for(int j=1;j<=m;j++){dp[0][j] = 0;} //here the j will start from zero else it will be overwritten
// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=m;j++){
// 			if(s[i-1] == t[j-1]){
// 	            dp[i][j] =  dp[i-1][j-1] + dp[i-1][j];
// 	        }
// 	        else
// 	            dp[i][j] = dp[i-1][j];
// 		}
// 	}
// 	return dp[n][m];
// }

//*******************SPACE OPTIMISATION SOLLUTION*****************************************************

// NOTE - Here we are doing tabultation but with shift indexing method,for more(https://youtube.com/clip/UgkxVCeBhX0ZT0SSwFecxAfkbWmHFzppHBPX)

// int DistinctSubsequence(int n,int m,string s,string t,vector<vector<int>>&dp){
// 	// for(int i=0;i<=n;i++){dp[i][0] = 1;} //if t string reches to -1 index fill it with 1 because it means that we found an subsequence of s which is equals to t
// 	// for(int j=1;j<=m;j++){dp[0][j] = 0;} //here the j will start from zero else it will be overwritten
// 	vector<int>prev(m+1,0);
// 	vector<int>temp(m+1,0);
// 	prev[0] = temp[0] =1;
// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=m;j++){
// 			if(s[i-1] == t[j-1]){
// 	            temp[j] =  prev[j-1] + prev[j];
// 	        }
// 	        else
// 	            temp[j] = prev[j];
// 		}
// 		prev = temp;
// 	}
// 	return prev[m];
// }


//*******************MORE SPACE OPTIMISATION SOLLUTION*****************************************************

// NOTE - Here we are doing tabultation but with shift indexing method,for more(https://youtube.com/clip/UgkxVCeBhX0ZT0SSwFecxAfkbWmHFzppHBPX)
int DistinctSubsequence(int n,int m,string s,string t,vector<vector<int>>&dp){
	// for(int i=0;i<=n;i++){dp[i][0] = 1;} //if t string reches to -1 index fill it with 1 because it means that we found an subsequence of s which is equals to t
	// for(int j=1;j<=m;j++){dp[0][j] = 0;} //here the j will start from zero else it will be overwritten
	vector<int>prev(m+1,0);
	prev[0] =  1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(s[i-1] == t[j-1]){
	            prev[j] =  prev[j-1] + prev[j];
	        }
	        else
	            prev[j] = prev[j];
		}
	}
	return prev[m];
}
int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		string t;
		cin>>s;
		cin>>t;
		int i1 = s.size();
		int i2 = t.size();
		//*******************RECURSION SOLLUTION*****************************************************

		// cout<<DistinctSubsequence(i1-1,i2-1,s,t);

		//*******************MEMOIZATION SOLLUTION*****************************************************

		// vector<vector<int>>dp(i1,(vector<int>(i2,-1)));
		// cout<<DistinctSubsequence(i1-1,i2-1,s,t,dp);

		//*******************MEMOIZATION SOLLUTION*****************************************************

		vector<vector<int>>dp(i1+1,(vector<int>(i2+1,0)));
		cout<<DistinctSubsequence(i1,i2,s,t,dp);
	}
}
