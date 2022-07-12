#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// - find lcs
// - print the value of ith element of str1 or jth element of str2(whichever is moving
//   and if s1[i]==s2[j] than only add character once in the answer)
// - then reverse and return the string

string LCS(int i1,int i2,string str1,string str2,vector<vector<int>>&dp){
	//NOTE - for tabulation base cases are required but here the index is getting negative so we 
	//		 will do the shifting of index watch here if not understood(https://youtube.com/clip/UgkxVCeBhX0ZT0SSwFecxAfkbWmHFzppHBPX)

	for(int i=0;i<=i1;i++){dp[i][0] = 0;}
	for(int i=0;i<=i2;i++){dp[0][i] = 0;}

	for(int i=1;i<=i1;i++){
		for(int j=1;j<=i2;j++){
		if(str1[i-1] == str2[j-1]){dp[i][j] = 1 + dp[i-1][j-1];}
		else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int len = dp[i1][i2];
	int index = len-1;
	int i=i1;
	int j=i2;
	string ans = "";
	while(i>0 && j>0){
		if(str1[i-1]==str2[j-1]){
			ans+=str1[i-1];
			i--;
			j--;
		}

		else if(dp[i-1][j]>dp[i][j-1]){
			ans += str1[i-1];
			i--;
		}
		else{
			ans += str2[j-1];
			j--;
		}
	}
	while(i>0){ans+=str1[i-1];i--;}
	while(j>0){ans+=str2[j-1];j--;}
	// cout<<ans<<endl;
	reverse(ans.begin(),ans.end());
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string str1;
		string str2;
		cin>>str1;
		cin>>str2;
		int i1 = str1.size();
		int i2 = str2.size();
		vector<vector<int>>dp(i1+1,(vector<int>(i2+1,0)));
		cout<<LCS(i1,i2,str1,str2,dp);
	}
}