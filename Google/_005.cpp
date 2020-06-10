/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

You are given an M by N matrix consisting of booleans that represents a board. Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate, return the minimum number of steps required to reach the end coordinate from the start. If there is no possible path, then return null. You can move up, left, down, and right. You cannot move through walls. You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]
and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is 7, since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    vector<vector<bool>> visited;
public:
    bool isSafe(vector<vector<bool>> &board,int r,int c,int m,int n){
        return (r>=0 && r<m && c>=0 && c<n && board[r][c] == 0 && !visited[r][c]);
    }
    
    // O(rows.cols)
    int solve(vector<vector<bool>> &board,int row,int col,int r,int c,int m,int n){
        if (board[row][col] == 1 || board[r][c] == 1){
            // 1 represents wall
            // 0 represents tile
            return -1;  // no path exists
        }
        queue<pair<int,pair<int,int>>> bfsq;
        bfsq.push({0,{row,col}});
        visited[row][col] = true;
        while (!bfsq.empty()){
            int x = bfsq.front().second.first;
            int y = bfsq.front().second.second;
            int pC = bfsq.front().first;
            bfsq.pop();
            if (x == r && y == c){
                return pC;
            }
            if (isSafe(board,x-1,y,m,n)){
                bfsq.push({pC+1,{x-1,y}});
                visited[x-1][y] = true;
            }
            if (isSafe(board,x+1,y,m,n)){
                bfsq.push({pC+1,{x+1,y}});
                visited[x+1][y] = true;
            }
            if (isSafe(board,x,y-1,m,n)){
                bfsq.push({pC+1,{x,y-1}});
                visited[x][y-1] = true;
            }
            if (isSafe(board,x,y+1,m,n)){
                bfsq.push({pC+1,{x,y+1}});
                visited[x][y+1] = true;
            }
        }
        return -1;
    }
    
    int minSteps(vector<vector<bool>> &board,vector<vector<int>> coord){
        int m = (int)board.size();
        int n = (int)board[0].size();
        visited.resize(m,vector<bool>(n,false));
        int row = coord[0][0];
        int col = coord[0][1];
        int rdest = coord[1][0];
        int cdest = coord[1][1];
        return solve(board,row,col,rdest,cdest,m,n);
    }
};

int main(){
    vector<vector<int>> coord = {
        {3,0},
        {0,0}
    };
    
    vector<vector<bool>> board = {
        {0,0,0,0},
        {1,1,0,1},
        {0,0,0,0},
        {0,0,0,0},
    };
    Solution s;
    cout << s.minSteps(board, coord) << "\n";
}
