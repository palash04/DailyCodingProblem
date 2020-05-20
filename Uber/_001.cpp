/*
 Good morning! Here's your coding interview problem for today.

 This problem was asked by Uber.

 Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

 For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

 Follow-up: what if you can't use division?
*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // TC: O(n) SC: O(n)
    vector<int> solve(vector<int> &nums){
        int n = (int)nums.size();
        vector<int> res(n);
        
        vector<int> l(n),r(n);
        l[0] = 1;
        r[n-1] = 1;
        
        for (int i=1;i<n;i++){
            l[i] = l[i-1] * nums[i-1];
        }
        for (int i=n-2;i>=0;i--){
            r[i] = r[i+1] * nums[i+1];
        }
        
        for (int i=0;i<n;i++){
            res[i] = l[i] * r[i];
        }
        return res;
    }
    
    // TC: O(n) SC: O(1)
    vector<int> solve2(vector<int> &nums){
        int n = (int)nums.size();
        
        vector<int> l(n);
        l[0] = 1;
        
        for (int i=1;i<n;i++){
            l[i] = l[i-1] * nums[i-1];
        }
        int r = 1;
        for (int i=n-1;i>=0;i--){
            l[i] = l[i] * r;
            r = r * nums[i];
        }
        return l;
    }
    
};

int main(){
    vector<int> nums = {1,3,5,6};
    Solution s;
    vector<int> res = s.solve(nums);
    for (auto &v : res){
        cout << v << " ";
    }
    cout << "\n";
}
