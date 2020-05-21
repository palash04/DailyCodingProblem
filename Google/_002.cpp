/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
    struct Tree{
        int val;
        Tree *left,*right;
        int uId;
        Tree(int x,int id) : val(x), uId(id), left(NULL), right(NULL) {}
    };
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root){
            return "X,";
        }
        string leftSerialized = serialize(root->left);
        string rightSerialized = serialize(root->right);
        return to_string(root->val) + "," + leftSerialized + rightSerialized;
    }

    vector<string> splitString(string s,char splitCharacter){
        stringstream ss(s);
        vector<string> v;
        while (ss.good()){
            string str;
            getline(ss,str,splitCharacter);
            v.push_back(str);
        }
        return v;
    }
    
    TreeNode *deserializeHelper(queue<string> &nodesLeft){
        string valueForNode = nodesLeft.front();nodesLeft.pop();
        if (valueForNode == "X"){
            return NULL;
        }
        TreeNode *newNode = new TreeNode(stoi(valueForNode));
        newNode->left = deserializeHelper(nodesLeft);
        newNode->right = deserializeHelper(nodesLeft);
        return newNode;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v = splitString(data, ',');
        queue<string> nodesLeft;
        for (auto &s : v){
            nodesLeft.push(s);
        }
        return deserializeHelper(nodesLeft);
    }
    
    void printTree(TreeNode *root){
        if (root){
            cout << root->val << " ";
            printTree(root->left);
            printTree(root->right);
        }
    }
    
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->left->left = new TreeNode(6);
    root->right->right->left = new TreeNode(7);
    root->right->left->left->left = new TreeNode(9);
    root->right->left->left->left->right = new TreeNode(10);
    
    Codec c;
    string data = c.serialize(root);
    //cout << data << "\n";
    TreeNode *node = c.deserialize(data);
    c.printTree(root);
    cout << "\n";
    c.printTree(node);
}
