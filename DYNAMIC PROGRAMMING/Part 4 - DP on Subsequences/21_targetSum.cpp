#include<iostream>
#include<vector>
using namespace std;

// Same as Count subset with sum K (Here only the target gets changed)
// Note - for detailed program go to the Count subset with sum K(Code studion)

//******************** DP Memoization Sollution *************************************

// int count(int n,int tar,vector<int>&num,vector<vector<int>>&dp){
//     if(n==0){
//         //watch dp 18
//         if(tar==0 && num[n]==0){return 2;} //handling 0
//         if(tar==0 || tar==num[0]){return 1;}
//         else return 0;
//     }
//     if(dp[n][tar]!=-1){return dp[n][tar];}
//     int pick=0;
//     if(tar>=num[n]) pick = count(n-1,tar-num[n],num,dp);
//     int not_pick = count(n-1,tar,num,dp);
//     return dp[n][tar] = (pick+not_pick);
// }


//******************* Tabultaion Sollution ****************************************

// int count(int n,int tar,vector<int>num,vector<vector<int>>&dp){
//     if(num[0]==0) dp[0][0] = 2;
//     else dp[0][0]=1;
//     if(num[0]!=0 && num[0]<=tar)dp[0][num[0]]=1;
//     for(int ind=1;ind<n;ind++){
//         for(int target=0;target<=tar;target++){
//             int pick=0;
//             if(target>=num[ind]) pick = dp[ind-1][target-num[ind]];
//             int not_pick = dp[ind-1][target];
//             dp[ind][target] = (pick+not_pick);
//         }
//     }
//     return dp[n-1][tar];
// }
//***************** Space Optimised Sollution ************************************************

int count(int n,int tar,vector<int>num){
    vector<int>prev(tar+1,0);
    if(num[0]==0) prev[0] = 2;
    else prev[0]=1;
    if(num[0]!=0 && num[0]<=tar)prev[num[0]]=1;
    for(int ind=1;ind<n;ind++){
        vector<int>temp(tar+1,0);
        for(int target=0;target<=tar;target++){
            int pick=0;
            if(target>=num[ind]) pick = prev[target-num[ind]];
            int not_pick = prev[target];
            temp[target] = (pick+not_pick);
        }
        prev=temp;
    }
    return prev[tar];
}

int main(){
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	int target;
	cin>>target;
	int total = 0;
    for(int i=0;i<nums.size();i++)total+=nums[i];
    if((total-target)<0 || (total-target)%2){return false;}
    int d = (total-target)/2;  //because (total-s2)-s2 = d
    //    *** Memoization ***
//     vector<vector<int>>dp(n,vector<int>(d+1,-1));
//     return count(n-1,d,nums,dp);

    //    *** Tabulation ***
//     vector<vector<int>>dp(n,vector<int>(d+1,0));
//     return count(n,d,nums,dp);

    //   ***Space Optimised ***
    cout<<count(n,d,nums);
}