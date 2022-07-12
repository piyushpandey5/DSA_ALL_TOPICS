#include<iostream>
#include <vector>
using namespace std;

//************************* RECURSIVE SOLLUTION ***********************************************

// int path(int i,int j,vector<vector<int>>&matrix){
//     if(i==matrix.size()-1){return matrix[i][j];}
//     int down = matrix[i][j] + path(i+1,j,matrix);
//     int diagleft =INT_MAX;
//     int diagright =INT_MAX;
//     if(j>0)diagleft = matrix[i][j] + path(i+1,j-1,matrix);
//     if(j<matrix.size()-1)diagright = matrix[i][j] + path(i+1,j+1,matrix);
//     return min(down,min(diagleft,diagright));
// }

//************************ MEMOIZATION SOLLUTION ************************************

// int path(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
//     // if(j<0 || j>=matrix[0].size()){return INT_MAX;}
//     if(i==0){return matrix[0][j];}
//     if(dp[i][j]!=-1){return dp[i][j];}
//     int up = matrix[i][j] + path(i-1,j,matrix,dp);
//     int diagleft =INT_MAX;
//     int diagright =INT_MAX;
//     if(j>0)diagleft = matrix[i][j] + path(i-1,j-1,matrix,dp);
//     if(j<matrix.size()-1)diagright = matrix[i][j] + path(i-1,j+1,matrix,dp);
//     return dp[i][j] = min(up,min(diagleft,diagright));
// }

//************************ TABULATION SOLLUTION ***************************************

// int path(vector<vector<int>>&matrix,vector<vector<int>>&dp){
//     int n = matrix.size();
//     int m = matrix[0].size();
//     for(int j=0;j<m;j++){
//         dp[0][j] = matrix[0][j];
//     }
//     for(int i = 1;i<n;i++){
//         for(int j =0;j<m;j++){
//             int up = matrix[i][j] + dp[i-1][j];
//             int diagleft =INT_MAX;
//             int diagright =INT_MAX;
//             if(j>0)diagleft = matrix[i][j] + dp[i-1][j-1];
//             if(j<matrix.size()-1)diagright = matrix[i][j] + dp[i-1][j+1];
//             dp[i][j] = min(up,min(diagleft,diagright));
//         }
//     }
//     int mini = INT_MAX;
//     for(int j=0;j<n;j++){
//         mini = min(mini,dp[n-1][j]);
//     }
//     return mini;
// }
//********************SPACE OPTIMISATION SOLLUTION**********************************

int path(vector<vector<int>>&matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>prev(m,0);
        for(int j=0;j<m;j++){
            prev[j] = matrix[0][j];
        }
        for(int i = 1;i<n;i++){
            vector<int>temp(m,0);
            for(int j =0;j<m;j++){
                int up = matrix[i][j] + prev[j];
                int diagleft =INT_MAX;
                int diagright =INT_MAX;
                if(j>0)diagleft = matrix[i][j] + prev[j-1];
                if(j<matrix.size()-1)diagright = matrix[i][j] + prev[j+1];
                temp[j] = min(up,min(diagleft,diagright));
            }
            prev=temp;
        }
        int mini = INT_MAX;
        for(int j=0;j<m;j++){
            mini = min(mini,prev[j]);
        }
        return mini;
}	

int main(){
        vector<vector<int>>matrix{
        	{{2,1,3},{6,5,4},{7,8,9}}
        };
        int mini = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
        // for(int j=0;j<n;j++){
        //         vector<vector<int>>dp(n,vector<int>(m,-1));
        //         mini = min(mini,path(n,j,matrix,dp))
        // }
        cout<<path(matrix);
}