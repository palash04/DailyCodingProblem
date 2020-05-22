/*

Good morning! Here's your coding interview problem for today.

This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.

*/

class Solution {
public:
    // O(n),O(1)
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        while (i<nums.size()){
            if (nums[i] <= 0){
                i++;
                continue;
            }
            if (nums[i]-1 < nums.size() && nums[i] != nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }else{
                i++;
            }
        }
        for (int i=0;i<nums.size();i++){
            if (nums[i] != i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};
