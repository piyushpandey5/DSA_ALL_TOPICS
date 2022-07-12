//this question is like nijas and his friends on leetcode

#include<iostream>
#include<vector>
using namespace std;


//********************SIMPLE RECURSIVE SOLLUTION*********************************** 

// int total(int i,int j1,int j2,vector<vector<int>>&matrix){
// 	int n = matrix.size();
// 	int m = matrix[0].size();
// 	if(j1<0 || j1>m-1 || j2<0 || j2>m-1){
// 		return -1e8;
// 	}

// 	if(i==n-1){
// 		if(j1==j2){ //If overlap only return single value
// 			return matrix[i][j1];
// 		}
// 		else{
// 			return matrix[i][j1] + matrix[i][j2];
// 		}
// 	}
// 	int maxi = 0;
// 	for(int dj1 = -1;dj1<=1;dj1++){
// 		for(int dj2 = -1;dj2<=1;dj2++){
// 			if(j1==j2){maxi = max(maxi, matrix[i][j1]+total(i+1,j1+dj1,j2+dj2,matrix));}
// 			else{ maxi = max(maxi,matrix[i][j1] + matrix[i][j2] + total(i+1,j1+dj1,j2+dj2,matrix));}	
// 		}	
// 	}
// 	return maxi;
// }

//**********************MEMOIZATION DP SOLLUTION*********************************** 

// int total(int i,int j1,int j2,vector<vector<int>>&matrix,vector<vector<vector<int>>>&dp){
// 	int n = matrix.size();
// 	int m = matrix[0].size();
// 	if(j1<0 || j1>m-1 || j2<0 || j2>m-1){
// 		return -1e8;
// 	}

// 	if(i==n-1){
// 		if(j1==j2){ //If overlap only return single value
// 			return matrix[i][j1];
// 		}
// 		else{
// 			return matrix[i][j1] + matrix[i][j2];
// 		}
// 	}
// 	if(dp[i][j1][j2]!=-1){return dp[i][j1][j2];}
// 	int maxi = 0;
// 	for(int dj1 = -1;dj1<=1;dj1++){
// 		for(int dj2 = -1;dj2<=1;dj2++){
// 			if(j1==j2){maxi = max(maxi, matrix[i][j1]+total(i+1,j1+dj1,j2+dj2,matrix,dp));}
// 			else{ maxi = max(maxi,matrix[i][j1] + matrix[i][j2] + total(i+1,j1+dj1,j2+dj2,matrix,dp));}	
// 		}	
// 	}
// 	return dp[i][j1][j2] = maxi;
// }

//***********************TABULATION DP SOLLUTION************************************* 

// int total(int n,int m,vector<vector<int>>&matrix,vector<vector<vector<int>>>&dp){
// 	for(int j1= 0;j1<m;j1++){
// 		for(int j2 = 0;j2<m;j2++){
// 			if(j1==j2) dp[n-1][j1][j2] = matrix[n-1][j1];
// 			else dp[n-1][j1][j2] = matrix[n-1][j1] + matrix[n-1][j2];
// 		}
// 	}
// 	for(int i=n-2;i>=0;i--){
// 		for(int j1 = 0;j1<m;j1++){
// 			for(int j2 =0;j2<m;j2++){
// 				int maxi = -1e8;	
// 				for(int dj1 = -1;dj1<=1;dj1++){
// 					for(int dj2 = -1;dj2<=1;dj2++){
// 						int val = 0;
// 						if(j1==j2){
// 							val = matrix[i][j1];
// 						}
// 						else{
// 							val = matrix[i][j1] + matrix[i][j2];
// 						}
// 						if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m){
// 							val += dp[i+1][j1+dj1][j2+dj2];
// 						}
// 						else{
// 							val += -1e8;
// 						}
// 						maxi = max(maxi,val);
// 					}
// 				}
// 					dp[i][j1][j2] = maxi;		
// 			}
// 		}
// 	}
// 	return dp[0][0][m-1];
// }


//************************SPACE OPTIMISED DP SOLLUTION**************************** 

int total(int n,int m,vector<vector<int>>&matrix,vector<vector<vector<int>>>&dp){
	vector<vector<int>>front(m,vector<int>(m,0));
	vector<vector<int>>curr(m,vector<int>(m,0));
	for(int j1= 0;j1<m;j1++){
		for(int j2 = 0;j2<m;j2++){
			if(j1==j2) front[j1][j2] = matrix[n-1][j1];
			else front[j1][j2] = matrix[n-1][j1] + matrix[n-1][j2];
		}
	}
	for(int i=n-2;i>=0;i--){
		for(int j1 = 0;j1<m;j1++){
			for(int j2 =0;j2<m;j2++){
				int maxi = -1e8;	
				for(int dj1 = -1;dj1<=1;dj1++){
					for(int dj2 = -1;dj2<=1;dj2++){
						int val = 0;
						if(j1==j2){
							val = matrix[i][j1];
						}
						else{
							val = matrix[i][j1] + matrix[i][j2];
						}
						if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m){
							val += front[j1+dj1][j2+dj2];
						}
						else{
							val += -1e8;
						}
						maxi = max(maxi,val);
					}
				}
					curr[j1][j2] = maxi;		
			}
		}
		front = curr;
	}
	return front[0][m-1];
}

int main(){
	vector<vector<int>>matrix{
		{2, 3, 1, 2},
		{3, 4, 2, 2},
		{5, 6, 3, 5}
	};
	int n = matrix.size();
	int m = matrix[0].size();
	// cout<<"Recursive Sollution"<<total(0, 0, n-1, matrix);
	vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
	// cout<<"Recursive Sollution "<<total(0, 0, m-1, matrix);
	// cout<<"DP MEMOIZATION SOLLUTION "<<total(0,0,m-1, matrix,dp);
	// cout<<"TABULATION SOLLUTION "<<total(n,m, matrix,dp);
	cout<<"SAPCE OPTIMISED SOLLUTION "<<total(n,m, matrix,dp);
}
