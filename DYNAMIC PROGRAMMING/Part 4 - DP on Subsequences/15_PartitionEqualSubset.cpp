#include<iostream>
#include<vector>
using namespace std;

// ******************** RECURSION SOLLUTION ***************************************

// bool Partition(int n,int target,vector<int>&nums){
//     if(target==0){return true;}
// 	   if(n==0) return target==nums[0];
//     bool not_take = Partition(n-1,target,nums);
//     bool take = false;
//     if(target>=nums[n] && not_take==false){take = Partition(n-1,target-nums[n],nums);}
//     return take || not_take;
// }
    
// ****************** DP MEMOIZATION SOLLUTION **************************************

// bool Partition(int n,int target,vector<int>&nums,vector<vector<int>>&dp){
//     if(target==0){return true;}
	// if(n==0) return target==nums[0];
	//     if(dp[n][target]!=-1){return dp[n][target];}
	//     bool not_take = Partition(n-1,target,nums,dp);
	//     bool take = false;
	//     if(target>=nums[n] && not_take==false){take = Partition(n-1,target-nums[n],nums,dp);}
	//     return dp[n][target] = take || not_take;
// }


//**************Space Optimised Sollution (Most optimised sollution)********************

bool Partition(int n,int t,vector<int>vec){
    vector<bool>prev(t+1,false);
    prev[0] = true;
    prev[vec[0]] = true;
    for(int ind=1;ind<n;ind++){
        vector<bool>temp(t+1,false);
        for(int target=1;target<=t;target++){
            bool not_take = prev[target];
            bool take = false;
            if(target >= vec[ind]){
                take = prev[target-vec[ind]];
           }
            temp[target] = take || not_take;
        }	
        prev = temp;
    }
    return prev[t];  
}		
 
int main(){
	vector<int>nums{1,2,3,5};
	int sum =0 ;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
    }
    int n = nums.size();
    if(n==2){
        if(nums[0]!=nums[1])return false;
        else return true;
            }
    if(n<2 || sum%2!=0){return false;}
    int target = sum/2;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    cout<<Partition(n,target,nums);
}
