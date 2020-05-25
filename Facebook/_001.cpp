/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string,int> dp;
public:
    // O(n),O(n)
    int solve(string s,int index){
        string key = to_string(index);
        if (index == s.size()){
            return 1;
        }
        if (s[index] == '0'){
            return 0;
        }
        if (dp.find(key) != dp.end()){
            return dp[key];
        }
        int decodeOneChar = solve(s,index+1);
        int decodeTwoChar = 0;
        
        if (index + 1 != s.size()){
            if ((s[index] == '1' && s[index+1] >= '0' && s[index+1] <= '9') || (s[index] == '2' && s[index+1] >= '0' && s[index+1] <= '6')){
                decodeTwoChar = solve(s, index+2);
            }
        }
        return dp[key] = decodeOneChar + decodeTwoChar;
    }
    
    int numDecodings(string s) {
        return solve(s,0);
    }
};
