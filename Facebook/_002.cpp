/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

You are given an array of non-negative integers that represents a two-dimensional elevation map where each element is unit-width wall and the integer is the height. Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, and 3 in the fourth index (we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  
    // O(n), O(n)
    int trap(vector<int>& height) {
        int curr = 0;
        stack<int> st;
        int ans = 0;
        while (curr < height.size()){
            while (!st.empty() && height[curr] > height[st.top()]){
                int top = st.top();
                st.pop();
                if (st.empty()){
                    break;
                }
                int dist = curr - st.top() - 1;
                int bh = min(height[curr],height[st.top()])-height[top];
                ans += dist*bh;
            }
            st.push(curr++);
        }
        return ans;
    }
};

int main(){
    vector<int> height = {3, 0, 1, 3, 0, 5};
    Solution s;
    cout << s.trap(height) << "\n";
}
