/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.

For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

You may also use a list or array to represent a set.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> res;
public:
    // O(2^n), O(n)
    void solve(vector<int> &nums,int index,int n,vector<int> &curr){
        res.push_back(curr);
        for (int i=index;i<n;i++){
            curr.push_back(nums[i]);
            solve(nums,i+1,n,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if ((int)nums.size() == 0) return res;
        vector<int> curr;
        solve(nums,0,(int)nums.size(),curr);
        return res;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    Solution s;
    vector<vector<int>> res = s.subsets(nums);
    for (auto vec : res){
        for (auto v : vec){
            cout << v << " ";
        }
        cout << "\n";
    }
}
