#include<iostream>
#include<vector>
using namespace std;

// ********************* NORMAL RECURSION SOLLUTION **********************************

// bool target(int n,int t,vector<int>vec){
//     if(t==0) return true;
//     if(n==0) return t==vec[n];
//     bool not_take = target(n-1,t,vec);
//     bool take = false;
//     if(t >= vec[n]){
//         take = target(n-1,t-vec[n],vec);
//     }
//     return take ||  not_take;
// }

// ***************** DP ARRAY MEMOIZATION SOLLUTION *************************************

// bool target(int n,int t,vector<int>vec,vector<vector<int>>&dp){
//     if(t==0) return true;
//     if(n==0) return t==vec[n];
//     if(dp[n][t]!=-1){return dp[n][t];}
//     bool not_take = target(n-1,t,vec,dp);
//     bool take = false;
//     if(t >= vec[n]){
//         take = target(n-1,t-vec[n],vec,dp);
//     }
//     return dp[n][t] = (take ||  not_take);
// }

// ***************** TABULATION SOLLUTION **********************************************

// bool Sum(int n,int t,vector<int>vec){
//     vector<vector<bool>>dp(n,vector<bool>(t+1,false));
//     for(int ind=0;ind<n;ind++){
//         dp[ind][0] = true;
//     }
//     dp[0][vec[0]] = true;
//     for(int ind=1;ind<n;ind++){
//         for(int target=1;target<=t;target++){
//             bool not_take = dp[ind-1][target];
//             bool take = false;
//             if(target >= vec[ind]){
//                 take = dp[ind-1][target-vec[ind]];
//            }
//             dp[ind][target] = take || not_take;
//         }
//     }
//     return dp[n-1][t];  
// }

//****************** Space Optimised Sollution (Most optimised sollution) ****************

bool Sum(int n,int t,vector<int>vec){
    // vector<vector<bool>>dp(n,vector<bool>(t+1,false));
    vector<bool>prev(t+1,false);
    // for(int ind=0;ind<n;ind++){
    //     dp[ind][0] = true;
    // }
    prev[0] = true;
    prev[vec[0]] = true;
    for(int ind=1;ind<n;ind++){
        vector<bool>temp(t+1,false);
        temp[0] = true;
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
	int n;
	cin>>n;
	vector<int>vec(n,0);
	int t;
	cin>>t;
	for(int i=0;i<n;i++){
		cin>>vec[i];
	}

	// cout<<"Recursion Sollution "<<target(n-1,t,vec);
	// vector<vector<int>>dp(n,vector<int>(t+1,-1));
	cout<<"Memoization Sollution "<<Sum(n,t,vec);
}