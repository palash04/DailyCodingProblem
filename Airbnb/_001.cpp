/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

#include <bits/stdc++.h>
using namespace std;

// O(n), O(n)
int solve(vector<int> &nums){
    int n = (int)nums.size();
    int dp[n];
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    
    for (int i=2;i<n;i++){
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[n-1];
}

// O(n),O(1)
int solve2(vector<int> &nums){
    int n = (int)nums.size();
    if (n == 1) return nums[0];
    nums[1] = max(nums[0],nums[1]);
    
    for (int i=2;i<n;i++){
        nums[i] = max(nums[i-1],nums[i]+nums[i-2]);
    }

    return nums[n-1];
}


int main(){
    vector<int> nums = {1,2,-5,0,8};
    cout << solve(nums) << "\n";
}
