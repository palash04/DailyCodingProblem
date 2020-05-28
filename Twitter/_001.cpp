/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Twitter.

Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
    struct TrieNode{
        TrieNode *child[26];
        bool isEnd;
        TrieNode(){
            for (int i=0;i<26;i++){
                child[i] = NULL;
            }
            isEnd = false;
        }
    };
    TrieNode *root;
    vector<string> res;
public:
    Solution(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode *node = root;
        for (auto c : word){
            if (!node->child[c-'a']){
                node->child[c-'a'] = new TrieNode();
            }
            node = node->child[c-'a'];
        }
        node->isEnd = true;
    }
    bool search(string key){
        TrieNode *node = root;
        for (auto c : key){
            if (!node->child[c-'a']){
                return false;
            }
            node = node->child[c-'a'];
        }
        return (node!=NULL && node->isEnd);
    }
    
    void displayHelper(TrieNode *node,string s){
        
        if (node->isEnd){
            cout << s << "\n";
        }
        for (int i=0;i<26;i++){
            if (node->child[i]){
                s += i + 'a';
                displayHelper(node->child[i], s);
                s.pop_back();
            }
        }
    }
    
    vector<string> autocomplete(string queryString){
        if (queryString.size() == 0) return res;
        TrieNode *node = root;
        for (auto c : queryString){
            if (node->child[c-'a']){
                node = node->child[c-'a'];
            }else{
                return res;
            }
        }
        displayHelper(node,queryString);
        return res;
    }
    
};

int main(){
    Solution s;
    string keys[] = {"there","the","those","win","won","art","artist","toe","tower","train"};
    for (auto key : keys){
        s.insert(key);
    }
    vector<string> res = s.autocomplete("");
    for (auto r : res){
        cout << r << "\n";
    }
}

