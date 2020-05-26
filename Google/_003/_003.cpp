#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val(x),left(NULL),right(NULL) {}
};

class Solution{
public:
    int count = 0;
    
    bool isUni(TreeNode *node){
        if (!node->left && !node->right) {
            count++;
            return true;
        }
        
        bool isUniVal = true;
        
        if (node->left){
            isUniVal = isUni(node->left) && isUniVal && (node->val == node->left->val);
        }
        
        if (node->right){
            isUniVal = isUni(node->right) && isUniVal && (node->val == node->right->val);
        }
        
        if (!isUniVal){
            return false;
        }
        count++;
        return true;
    }
    
    int countUnivalSubtrees(TreeNode *root){
        if (!root) return 0;
        isUni(root);
        return count;
    }
};

int main(){
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(0);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(0);
    root->right->left->left = new TreeNode(1);
    root->right->left->right = new TreeNode(1);

    Solution s;
    cout << s.countUnivalSubtrees(root) << "\n";
    
}
