/*
 
 Good morning! Here's your coding interview problem for today.

 This problem was recently asked by Google.

 Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

 For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

 Bonus: Can you do this in one pass?
 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // O(n^2) approach, SC: O(1)
    bool solve1(vector<int> &nums,int k){
        int n = (int)nums.size();
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if (nums[i] + nums[j] == k){
                    return true;
                }
            }
        }
        return false;
    }
    
    // O(n) linear time approach, SC: O(n)
    unordered_set<int> st;
    bool solve2(vector<int> &nums, int k){
        for (int i=0;i<nums.size();i++){
            if (st.find(nums[i]) != st.end()){
                return true;
            }
            int target = k - nums[i];
            st.insert(target);
        }
        return false;
    }
};

int main(){
    vector<int> nums = {31,-312,54,66,-78,27,20,232,878,323,-4456,232,-90,45,12,56,};
    int k = 11;
    
    Solution s;
    cout << s.solve1(nums, k) << "\n";
    cout << s.solve2(nums, k) << "\n";
    
}
