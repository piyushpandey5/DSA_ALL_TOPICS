#include<iostream>
#include<vector>
using namespace std;

// void allpathsprint(string p, bool maze[][3], int r, int c,int path[][3],int step){
// 	if (r==R-1 && c == C-1){
// 		path[r][c]=step;
// 		for(int i = 0; i < 9 ; i++)
//     	{
         
//         // Find row and column index
//         int row = i / 3;
//         int col = i % 3;
 
//         // Print the element at
//         // current index
//         cout << to_string(path[row][col]) << " ";
//         if(i%3==2){cout<<endl;}

//     	}
//     	cout<<p<<endl;
// 	    cout<<endl;
// 	    return;
// 	}
// 	if(!maze[r][c]){
// 		return;
// 	}
// 	maze[r][c]=false;
// 	path[r][c]=step;
// 	if(r<R-1){
// 		allpathsprint(p+"D",maze,r+1,c,path,step+1);
// 	}
// 	if(c<C-1){
// 		allpathsprint(p+"R",maze,r,c+1,path,step+1);
// 	}
// 	if(r>0){
// 		allpathsprint(p+"U",maze,r-1,c,path,step+1);
// 	}
// 	if(c>0){
// 		allpathsprint(p+"L",maze,r,c-1,path,step+1);
// 	}
// 	maze[r][c]=true;
// 	path[r][c]=0;
// }



void allpaths(string p, vector<vector<bool>>maze, int r, int c){
	if (r==maze.size()-1 && c == maze[0].size()-1){
		cout<<p<<endl;
	}
	if(!maze[r][c]){
		return;
	}
	maze[r][c]=false;
	if(r<maze.size()-1){
		allpaths(p+"D",maze,r+1,c);
	}
	if(c<maze[0].size()-1){
		allpaths(p+"R",maze,r,c+1);
	}
	if(r>0){
		allpaths(p+"U",maze,r-1,c);
	}
	if(c>0){
		allpaths(p+"L",maze,r,c-1);
	}
	maze[r][c]=true;
}



int main(){
//count the number of possible ways to reach from 3,3 to 1,1 whe you can only move right and down

	// cout<<count(3,3)<<endl;       //for finding the number of steps required to reach at the destination
	// path("",5,5);           //for finding the exact path  
	vector<vector<bool>>board ={
		{true,true,true},
		{true,true,true},
		{true,true,true}
	} ;
	// int path[3][3]={0};
	allpaths("", board , 0, 0);
}