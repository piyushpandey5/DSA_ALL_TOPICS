#include<iostream>
#include<vector>
using namespace std;

vector<int> findAllIndexes(int arr[],int target,int index,vector<int> x){
	if(index==6){return x;}
	if(arr[index]==target){
		x.push_back(index);
	}
	return findAllIndexes(arr,target,index+1,x);
}


int main(){
	int arr[] = {3,4,6,24,32,24,12};
	vector<int> ans=findAllIndexes(arr,24,0,vector<int>());
	cout<<ans[0]<<endl;
	cout<<ans[1];
}