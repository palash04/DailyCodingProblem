/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2
What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.

Leetcode link : https://leetcode.com/problems/climbing-stairs/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Recursive: TC: O(n), SC: O(n)
    unordered_map<string, int> dp;
    int solve(int curr,int n){
        string key = to_string(curr);
        if (curr == n){
            return 1;
        }
        if (curr > n){
            return 0;
        }
        if (dp.find(key) != dp.end()){
            return dp[key];
        }
        
        return dp[key] = solve(curr+1,n) + solve(curr+2,n);
    }
    
    
    // DP Solution: TC: O(n), SC: O(n)
    int solveDP(int n){
        if (n == 1) return 1;
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    
    int solve(int n){
        if (n == 1) return 1;
        int first = 1;
        int second = 2;
        for (int i=3;i<=n;i++){
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
    
    int climbStairs(int n) {
        return solve(n);
    }
};
