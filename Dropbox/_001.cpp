/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Dropbox.

Given the root to a binary search tree, find the second largest node in the tree. 
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

class Solution{
public:
    
    // O(k)
    void solve(TreeNode *root,int k,int &res,int &c){
        if (root){
            solve(root->right,k,res,c);
            c++;
            if (c == k){
                res = root->val;
                return;
            }
            solve(root->left,k,res,c);
        }
    }
    
    int kthMax(TreeNode *root,int k){
        int res = 0;
        int c = 0;
        solve(root,k,res,c);
        return res;
    }
    
    // O(k)
    void iterativeInorder(TreeNode *root,int k){
        stack<TreeNode*> st;
        int c = 0;
        while (true){
            while (root){
                st.push(root);
                root = root->right;
            }
            
            if (st.empty()){
                break;
            }
            root = st.top();
            st.pop();
            c++;
            if (c == k){
                cout << root->val << "\n";
                break;
            }
            root = root->left;
        }
    }
    
};

int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(20);
    root->right->right->right = new TreeNode(24);
    
    Solution s;
    cout << s.kthMax(root, 3) << "\n";
    s.iterativeInorder(root,3);
}
