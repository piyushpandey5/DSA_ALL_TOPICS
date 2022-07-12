#include<iostream>
#include<vector>
using namespace std;

//******************** Tabulation Approach *****************************************

// void Target(int n,int t,vector<int>&vec,vector<vector<bool>>&dp){
//     for(int ind = 0; ind<n;ind++){
//         dp[ind][0] = true;
//     }
//     if(vec[0]<=t)dp[0][vec[0]] = true;
//     for(int ind=1;ind<n;ind++){
//         for(int target=1;target<=t;target++){
//             bool not_take = dp[ind-1][target];
//             bool take = false;
//             if(target>=vec[ind]){
//                 take = dp[ind-1][target-vec[ind]];    
//             }
//             dp[ind][target] = not_take||take;
//         }
//     } 
// }

// int minDiff(int n,vector<int>vec){
//     int target =0;
//     for(int i=0;i<n;i++) target+=vec[i];
//     vector<vector<bool>>dp(n,vector<bool>(target+1,false));
//     Target(n,target,vec,dp);
//     int mini = 1e9;
//     for(int s1=0;s1<=target;s1++){
//         if(dp[n-1][s1]==true){
//             mini = min(mini,abs((target-s1)-s1));
//         }
//     }
//     return mini;
// }


//*********************** Space Optimised Approach *********************************

void Target(int n,int t,vector<int>&vec,vector<bool>&prev){
    prev[0] = true;    
    prev[vec[0]] = true;
    for(int ind=1;ind<n;ind++){
        vector<bool>curr(t+1,false);
        curr[0] = true;
        for(int target=1;target<=t;target++){
            bool not_take = prev[target];
            bool take = false;
            if(target>=vec[ind]){
                take = prev[target-vec[ind]];    
            }
            curr[target] = not_take||take;
        }
        prev = curr;
    } 
}

int minDiff(int n,vector<int>&vec){
    int target =0;
    for(int i=0;i<n;i++) target+=vec[i];
    vector<bool>prev(target+1,false);
    Target(n-1,target,vec,prev);
    int mini = 1e9;
    for(int i=0;i<=target;i++){
        if(prev[i]==true){
            mini = min(mini,abs((target-i)-i));
        }
    }
    return mini;
}

int main(){
	vector<int>vec{3,9,7,3};
	int n = vec.size();
	cout<<minDiff(n,vec)<<endl;
}