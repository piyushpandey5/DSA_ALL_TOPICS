#include<iostream>
#include<vector>
using namespace std;

// *********************** Plain Recursion Sollution *****************************

// int NinzaTraining(vector<vector<int>>points, int day, int last){
// 	if(day==0){
// 		int maxi = 0;	
// 		for(int i=0;i<3;i++){
// 			if(i!=last){
// 				maxi = max(maxi,points[day][i]);
// 			}
// 		}
// 		return maxi;
// 	}

// 	int maxi = 0;
// 	for(int i=0;i<3;i++){
// 		if(i!=last){
// 			int currpoints = points[day][i] + NinzaTraining(points,day-1,i);
// 			maxi = max(maxi,currpoints);
// 		}
// 	}
// 	return maxi;
// }


// ******************* Memoization Sollution usind 2D dp array ********************

// int NinzaTraining(vector<vector<int>>points, int day, int last,vector<vector<int>>&dp){
// 	if(day==0){
// 		int maxi = 0;	
// 		for(int i=0;i<3;i++){
// 			if(i!=last){
// 				maxi = max(maxi,points[day][i]);
// 			}
// 		}
// 		return maxi;
// 	}
// 	if(dp[day][last] != -1){return dp[day][last];}

// 	int maxi = 0;
// 	for(int i=0;i<3;i++){
// 		if(i!=last){
// 			int currpoints = points[day][i] + NinzaTraining(points,day-1,i,dp);
// 			maxi = max(maxi,currpoints);
// 		}
// 	}
// 	return dp[day][last] = maxi;
// }


// ****************************** TABULTAION *****************************************

// int NinzaTraining(vector<vector<int>>points, int days, int last,vector<vector<int>>&dp){
// 	dp[0][0] = max(points[0][1],points[0][2]);
// 	dp[0][1] = max(points[0][0],points[0][2]);
// 	dp[0][2] = max(points[0][0],points[0][1]);
// 	dp[0][3] = max( max(points[0][0],points[0][1]) , points[0][2]);

// 	for(int day=1;day<days;day++){
// 		for(int last = 0;last<4;last++){
// 			dp[day][last] = 0;
// 			for(int task = 0;task<3;task++){
// 				if(task!=last){
// 					int currpoints = points[day][task] + dp[day-1][task];
// 					dp[day][last] = max(dp[day][last],currpoints);
// 				}
// 			}
// 		}
// 	}
// 	return dp[days-1][3];
// }


// ***************************** SPACE OPTIMISED SOLLUTION ***********************

int NinzaTraining(vector<vector<int>>points, int days, int last){
	vector<int>prev(4,0);
	prev[0] = max(points[0][1],points[0][2]);
	prev[1] = max(points[0][0],points[0][2]);
	prev[2] = max(points[0][0],points[0][1]);
	prev[3] = max( max(points[0][0],points[0][1]) , points[0][2]);

	for(int day=1;day<days;day++){
		vector<int>temp(4,0);
		for(int last = 0;last<4;last++){
			temp[last] = 0;
			for(int task = 0;task<3;task++){
				if(task!=last){
					temp[last] = max(temp[last], points[day][task] + prev[task]); 
				}
			}
		}
		prev=temp;
	}
	return prev[3];
}

int main(){
	vector<vector<int>>points{
		{1,2,5},
		{3,1,1},
		{3,3,3}
	};
	int n = points.size();
	vector<vector<int>>dp(n,vector<int>(4,-1));
	// int days = points.size()-1;
	// cout<<"Recursion Sollution"<<NinzaTraining(points,days,3);
	// cout<<" Memoization Sollution "<<NinzaTraining(points,days,3,dp);
	int days = points.size();
	// cout<<" Tabulation Sollution "<<NinzaTraining(points,days,3,dp);
	cout<<" Space Optimised Sollution "<<NinzaTraining(points,days,3);

}