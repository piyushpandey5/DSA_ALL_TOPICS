#include<bits/stdc++.h>
using namespace std;

void combinataionsum2(vector<int> array, int target,int c, vector<int> ans){
		
        
        
		if(target==0){
            for(int i=0;i<ans.size();i++){cout<<ans[i]<<" ";}
            cout<<endl;
            return;
        }
        // if(target<0){
        //     return;
        // }
    
        for(int i=c;i<array.size() && array[i]<=target; i++){
        	ans.push_back(array[i]);
            c=c+1;
            combinataionsum2(array,target-array[i],c,ans);
            ans.pop_back();
            
        }
}

int main(){

	vector<int> array = {2,5,2,1,2};
	int target= 5;
	sort(array.begin(),array.end());
    vector<int> ans;
	combinataionsum2(array,target,0,ans);
}

	// FOR LEETCODE

// void combinationsum(vector<int> &candidates, int target,int c, vector<int> &ans, vector<vector<int>>&mainans){
		
//         if(target==0){
//             // for(int i=0;i<ans.size();i++){cout<<ans[i]<<" ";}
//             // cout<<endl;
//             mainans.push_back(ans);
//             return;
//         }
//         // if(target<0){
//         //     return;
//         // }
//         if(c>=candidates.size()){return;}
    
//         if(target>=candidates[c]){
//         	ans.push_back(candidates[c]);
            
//             combinationsum(candidates,target-candidates[c],c+1,ans,mainans);
//             ans.pop_back();
//             while(c+1<candidates.size()&&candidates[c+1]==candidates[c])++c;
//             combinationsum(candidates,target,c+1,ans,mainans);
            
//         }

// }