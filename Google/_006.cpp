/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors are not locked.

Design a binary tree node class with the following methods:

is_locked, which returns whether the node is locked
lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it and return true.
unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it and return true.
You may augment the node to add parent pointers or any other property you would like. You may assume the class is used in a single-threaded program, so there is no need for actual locks or mutexes. Each method should run in O(h), where h is the height of the tree.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    int countOfDescendants;
    Node *left,*right;
    Node(int x): val(x),left(NULL),right(NULL),countOfDescendants(0) {}
};

class Solution{
    Node *root;
    map<Node*,bool> mp;
public:
    Solution(Node *root){
        mp.clear();
        this->root = root;
    }
    
    bool isLocked(Node *node){
        if (mp.find(node) != mp.end()){
            return mp[node];
        }
        return false;
    }
    
    void conveyToAllAncestors(vector<Node*> &path,int c){
        for (auto p : path){
            p->countOfDescendants += c;
        }
    }
    
    bool lockHelper(Node *rnode,Node *dnode,vector<Node*> path){

        if (((mp.find(rnode) != mp.end()) && mp[rnode])){
            return false;
        }
        
        if (rnode == dnode){
            if (mp.find(dnode) == mp.end()){
                mp.insert({dnode,true});   // lock it
                conveyToAllAncestors(path,1);
                return true;
            }else{
                if (mp[dnode]){ // already locked
                    return false;
                }else{
                    mp[dnode] = true;   // lock it
                    conveyToAllAncestors(path,1);
                    return true;
                }
            }
        }
        
        path.push_back(rnode);
        bool found = false;
        if (rnode->left){
            found = lockHelper(rnode->left, dnode, path);
        }
        if (found) return true;
        if (rnode->right){
            found = lockHelper(rnode->right, dnode, path);
        }
        path.pop_back();
        return found;
    }
    
    bool lock(Node *node){
        if (node->countOfDescendants){
            return false;
        }
        vector<Node*> path;
        Node *rnode = root;
        return lockHelper(rnode,node,path);
    }
    
    bool unlockHelper(Node *rnode,Node *dnode,vector<Node*> path){
        if (rnode == dnode){
            if (mp.find(dnode) == mp.end()){
                return false;   // cannot be unlocked, as it is not locked
            }
            if (mp[dnode]){
                conveyToAllAncestors(path,-1);
                mp[dnode] = false;
                return true;    // unlocked successfully
            }
            return false;
        }
        
        path.push_back(rnode);
        bool found = false;
        if (rnode->left){
            found = unlockHelper(rnode->left,dnode,path);
        }
        if (!found && rnode->right){
            found = unlockHelper(rnode->right, dnode, path);
        }
        path.pop_back();
        return found;
    }
    
    bool unlock(Node *node){
        vector<Node*> path;
        Node *rnode = root;
        return unlockHelper(rnode,node,path);
    }
    
};

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);
    Solution s(root);
    cout << s.lock(root->left->right) << "\n";
    cout << s.lock(root->left->left->right) << "\n";
    cout << s.lock(root->right) << "\n";
    cout << s.lock(root) << "\n";
    cout << s.lock(root->right->right) << "\n";
    cout << s.unlock(root->right) << "\n";
    cout << s.lock(root->right) << "\n";
    cout << s.isLocked(root) << "\n";
    cout << s.lock(root);
}
