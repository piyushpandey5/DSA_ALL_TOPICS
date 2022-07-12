#include <bits/stdc++.h>
using namesapce std;

// *********NOT COMPLETED YET**********


bool issafe(vector<vector<bool>> board, int row, int col){
	// FOR CHECKING VERTICAL ROWS
	for(int i=0;i<row;i++){
		if(board[i][col]){
			return false;
		}
	}

	// FOR CHECKING DIAGONAL LEFT
	int maxleft = min(row,col);
	for(int i=0;i<=maxleft;i++){
		if(board[row-1][col-1]){return false;}
	}

	// FOR CHECKING DIAGONAL RIGHT
	int maxright = min(row, board.size()-col-1);
	for(int i=0;i<maxright;i++){
		if(board[row-1][col+1]){return false;}
	}

	return true;
}

int queen(vector<vector<bool>>board,int row){
	if(row==size()){
		display(board);
		return 1;
	}

	int count=0;

	// placing the queen checking for every row and col
	for(int col=0;col<board.size();col++){
		// placing the queen if it is safe to place it threr
		if issafe(board,row,col){
			board[row][col]=true;
			count + queen(board, row+1);
			board[row][col]=false;
		}
	}
	return count;

}
void display(vector<vector<bool>>board){
	for(bool row:board){
		for(bool elem:row){
			if(elem==true){
				cout<<"Q";
			}
			else{
				cout<<false;
			}
		}
	}
}


int main(){
	// int n=4;
	vector<vector<bool>>board1{
        {false, false, false},
        {false, false, false},
        {false, false, false}
    };
	queen(board1,0);
}