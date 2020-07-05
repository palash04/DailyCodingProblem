/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given an array of integers where every integer occurs three times except for one integer, which only occurs once, find and return the non-duplicated integer.

For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.

Do this in O(N) time and O(1) space.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // works for only positive integers
    // O(n), O(1)
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32,0);
        for (int i=0;i<nums.size();i++){
            int num = nums[i];
            for (int j=31;j>=0;j--){
                int x = (num >> j);
                if (x&1){
                    bits[j]++;
                }
            }
        }
        int res = 0;
        for (int i=0;i<=31;i++){
            if (bits[i]%3 != 0){
                res += pow(2,i);
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {13,19,13,13};
    Solution s;
    cout << s.singleNumber(nums) << "\n";
}
