#include <iostream>
#include <vector>
using namespace std;

int Maxprofit(vector<int>&prices){
	if(prices.size()<2){return 0;}
        
        int i=0;
        int j=1;
        int maxi = INT_MIN;
        int sum = 0;
    
    while(j<prices.size()){
        if(prices[j]<prices[i]){
            i=j;
        }
        sum = prices[j] - prices[i];
        maxi = max(maxi , sum);
        j++;
    }
    return maxi;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>prices(n);
		for(int i=0;i<n;i++){
			cin>>prices[i];
		}
		cout<<Maxprofit(prices);
	}
}