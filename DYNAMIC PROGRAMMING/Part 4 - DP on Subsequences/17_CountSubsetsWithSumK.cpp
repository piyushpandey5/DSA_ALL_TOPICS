#include <iostream>
#include<vector>
using namespace std;

//********************** Normal Recursion Sollution **********************************

// int count(int n,int tar,vector<int>num){
//     if(tar==0){return 1;}
//     if(n==0){return tar==num[n];}
//     int pick=0;
//     if(tar>=num[n]) pick = count(n-1,tar-num[n],num);
//     int not_pick = count(n-1,tar,num);
//     return pick+not_pick;
// }

//********************* DP Memoization Sollution ************************************

// int count(int n,int tar,vector<int>num,vector<vector<int>>&dp){
//     if(tar==0){return 1;}
//     if(n==0){return tar==num[n];}
//     if(dp[n][tar]!=-1){return dp[n][tar];}
//     int pick=0;
//     if(tar>=num[n]) pick = count(n-1,tar-num[n],num,dp);
//     int not_pick = count(n-1,tar,num,dp);
//     return dp[n][tar] = pick+not_pick;
// }

//******************** Tabultaion Sollution **********************************************

// int count(int n,int tar,vector<int>num,vector<vector<int>>&dp){
//     for(int i=0;i<n;i++){dp[i][0]=1;}
//     if(num[0]<=tar)dp[0][num[0]]=1;
//     for(int ind=1;ind<n;ind++){
//         for(int target=1;target<=tar;target++){
//             int pick=0;
//             if(target>=num[ind]) pick = dp[ind-1][target-num[ind]];
//             int not_pick = dp[ind-1][target];
//             dp[ind][target] = pick+not_pick;
//         }
//     }
//     return dp[n-1][tar];
// }

//*************** Space Optimisation Sollution ****************************************

int count(int n,int tar,vector<int>num,vector<vector<int>>&dp){
    vector<int>prev(tar+1,0);
    for(int i=0;i<n;i++){prev[0]=1;}
    if(num[0]<=tar)prev[num[0]]=1;
    for(int ind=1;ind<n;ind++){
        vector<int>temp(tar+1,0);
        for(int target=0;target<=tar;target++){
            int pick=0;
            if(target>=num[ind]) pick = prev[target-num[ind]];
            int not_pick = prev[target];
            temp[target] = pick+not_pick;
        }
        prev=temp;
    }
    return prev[tar];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int target;
		cin>>target;
		vector<int>vec(n);
		for(int i=0;i<n;i++){cin>>vec[i];}
        vector<vector<int>>dp(n,vector<int>(target+1,0));
		cout<< count(n,target,vec,dp)<<endl;	
	}
}