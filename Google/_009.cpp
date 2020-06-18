/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions required to change one string to the other. For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // O(3^n)
    int solveRec(string X,string Y,int m,int n){
        if (m == 0 || n == 0){
            return max(m,n);
        }
        int cost = 1;
        if (X[m-1] == Y[n-1]){
            cost = 0;
        }
        return min(min(solveRec(X,Y,m,n-1)+1 ,solveRec(X,Y,m-1,n)+1), solveRec(X,Y,m-1,n-1)+cost);
    }
    
    // O(mn)
    int solveDP(string X,string Y,int m,int n){
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for (int i=1;i<=m;i++){
            dp[i][0] = i;
        }
        for (int i=1;i<=n;i++){
            dp[0][n] = i;
        }
        int cost;
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                if (X[i-1] == Y[j-1]){
                    cost = 0;
                }else{
                    cost = 1;
                }
                dp[i][j] = min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+cost);
            }
        }
        return dp[m][n];
    }
    
    int editDistance(string X,string Y){
        int m = (int)X.size();
        int n = (int)Y.size();
        //int recAns = solveRec(X, Y, m, n);
        int dpAns = solveDP(X, Y, m, n);
        return dpAns;
    }
};

int main(){
    Solution s;
    cout << s.editDistance("kitten", "sitting") << "\n";
}
