// HOUSE ROBBER 2 (LEETCODE)
// HOUSE ROBBER (CODIE STUDIO)

#include<iostream>
#include<vector>
using namespace std;


// This is same as prev question (MaxSumOfNonAdjacent), the only difference here
// you can not rob first and last house at once because they are also adjacent because
// of circular houses 

// so we will take two different arrays temp 1 and temp2, in which one exclude first element
// and other will exclude the last element and get solve seperately then maximum of them 
// will be taken

int HouseRobMax(int ind, vector<int>&arr){
	int prev = arr[0];
	int prev2 = 0;
	for(int i=1;i<arr.size();i++){
		// if(i==arr.size()-1){continue;}
		int picked = arr[i];
		if(i>1)
			picked += prev2;
		int Not_picked = 0 + prev;
		int curr = max(picked,Not_picked);
		prev2 = prev;
		prev = curr;	
	}
	return prev;
}

int main(){
	vector<int>arr{2,3,2};
	vector<int>temp1;
	vector<int>temp2;
	for(int i=0;i<arr.size();i++){
		if(i!=0)temp1.push_back(arr[i]);
		if(i!=arr.size()-1)temp2.push_back(arr[i]);
	}
	int excFirst = HouseRobMax(18,temp1);
	int excLast = HouseRobMax(18,temp2);
	cout<<max(excFirst,excLast)<<endl;
}