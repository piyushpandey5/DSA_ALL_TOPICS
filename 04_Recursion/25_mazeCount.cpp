#include<iostream>
#include<array>
using namespace std;

int count(int r, int c){
	if(r==1||c==1){
		return 1;
	}
	int left = count(r-1,c);
	int right = count(r, c-1);
	return left+right;
}

// FOR PRINTING PATH ACTUAL PASS

// void path(string p, int r, int c){
// 	if(r==1&&c==1){
// 		cout<<p<<endl;
// 		retlength
// 	}
// // INCUDING DIAGONAL PATH ALSO


// 	if(r>1&&c>1){
// 		path(p+"V", r-1,c-1);
// 	}

// 	if(r>1)
// 		path(p+"D", r-1,c);

// 	if(c>1)
// 		path(p+"R",r,c-1);
// }

int R=3;
int C=3;
// FOR PRINTING PATHS WITH HURDLES
void matrixWithHurdles(string p, bool maze[][3], int r, int c){
	if (r==R-1 && c == C-1){
		cout<<p<<endl;
	}
	if(!maze[r][c]){
		return;
	}
	if(r<R-1){
		matrixWithHurdles(p+"D",maze,r+1,c);
	}
	if(c<C-1){
		matrixWithHurdles(p+"R",maze,r,c+1);
	}
}


// FOR GETTING ALL PATHS

void allpaths(string p, bool maze[][3], int r, int c){
	if (r==R-1 && c == C-1){
		cout<<p<<endl;
	}
	if(!maze[r][c]){
		return;
	}
	maze[r][c]=false;
	if(r<R-1){
		allpaths(p+"D",maze,r+1,c);
	}
	if(c<C-1){
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





// PRINT PATH WITH SEQUEMCE NUMBER IN ARRAY
void allpathsprint(string p, bool maze[][3], int r, int c,int path[][3],int step){
	if (r==R-1 && c == C-1){
		path[r][c]=step;
		for(int i = 0; i < 9 ; i++)
    		{
	         
	        // Find row and column index
	        int row = i / 3;
	        int col = i % 3;
	 
	        // Print the element at
	        // current index
	        cout << to_string(path[row][col]) << " ";
	        if(i%3==2){cout<<endl;}

    		}
    	cout<<p<<endl;
	    cout<<endl;
	    return;
		}	
	if(!maze[r][c]){
		return;
	}
	maze[r][c]=false;
	path[r][c]=step;
	if(r<R-1){
		allpathsprint(p+"D",maze,r+1,c,path,step+1);
	}
	if(c<C-1){
		allpathsprint(p+"R",maze,r,c+1,path,step+1);
	}
	if(r>0){
		allpathsprint(p+"U",maze,r-1,c,path,step+1);
	}
	if(c>0){
		allpathsprint(p+"L",maze,r,c-1,path,step+1);
	}
	maze[r][c]=true;
	path[r][c]=0;
}



int main(){
//count the number of possible ways to reach from 3,3 to 1,1 whe you can only move right and down

	// cout<<count(3,3)<<endl;       //for finding the number of steps required to reach at the destination
	// path("",5,5);           //for finding the exact path  
	bool board[3][3] ={
		{true,true,true},
		{true,true,true},
		{true,true,true}
	} ;
	int path[3][3]={0};
	allpathsprint("", board , 0, 0,path,1);
}