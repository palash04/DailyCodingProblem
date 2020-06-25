/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

You have an N by N board. Write a function that, given N, returns the number of possible arrangements of the board where N queens can be placed on the board without threatening each other, i.e. no two queens share the same row, column, or diagonal.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> res;
    int count=0;
public:
    
    bool isSafe(vector<vector<char>> &board,int row,int col,int n){
        for (int i=0;i<row;i++){
            if (board[i][col] == 'Q') return false;
        }
        
        int i = row-1;
        int j = col-1;
        while (i>=0 && j>=0){
            if (board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }
        i = row-1;
        j = col+1;
        while (i>=0 && j<n){
            if (board[i][j] == 'Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    
    
    void printBoard(vector<vector<char>> &board,int n){
        vector<string> subres;
        for (int i=0;i<n;i++){
            string s = "";
            for (int j=0;j<n;j++){
                s += board[i][j];
            }
            subres.push_back(s);
        }
        res.push_back(subres);
    }
    
    // O(n^n)
    void solve(vector<vector<char>> &board,int row,int n){
        
        if (row == n){
            // successfully created the board
            printBoard(board, n);
            count++;
        }
        
        for (int col=0;col<n;col++){
            if (isSafe(board,row,col,n)){
                board[row][col] = 'Q';
                solve(board,row+1,n);
                board[row][col] = '.';
            }
        }
    }
    
    int solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        solve(board,0,n);
        return count;
    }
};

int main(){
    Solution s;
    cout << s.solveNQueens(8) << "\n";
}
