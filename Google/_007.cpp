/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses.
*/



#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *npx;
    Node(int x):val(x) {}
};

class XORDLL{
    int len;
    Node *head;
public:
    XORDLL(){
        this->len = 0;
        head = NULL;
    }
    void add(int value){
        if (len == 0){
            // add head
            head = new Node(value);
            head->npx = (Node*) ((uintptr_t)(0) ^ (uintptr_t)(0));
            len++;
        }else{
            // traverse till end
            // add at end
            Node *pNode = NULL;
            Node *node = head;
            Node *prev = (Node*)(uintptr_t)0;
            for (int i=0;i<len-1;i++){
                pNode = node;
                node = (Node*) ((uintptr_t)(prev)^(uintptr_t)(node->npx));
                prev = pNode;
            }
            Node *nNode = new Node(value);
            nNode->npx = (Node*) ((uintptr_t)(node)^(uintptr_t)(0));
            node->npx = (Node*) ((uintptr_t)(prev)^(uintptr_t)(nNode));
            len++;
        }
    }
    
    int get(int index){
        // 0 based index
        if (index >= len){
            return -1;  // no node at this index
        }
        Node *prev = (Node*)(uintptr_t)0;
        Node *node = head;
        Node *pNode = NULL;
        for (int i=0;i<index;i++){
            pNode = node;
            node = (Node*) ((uintptr_t)(prev)^(uintptr_t)(node->npx));
            prev = pNode;
        }
        return node->val;
    }
    
    int getLast(){
        if (len == 0){
            return -1;
        }
        Node *prev = (Node*)(uintptr_t)0;
        Node *node = head;
        Node *pNode = NULL;
        for (int i=0;i<len-1;i++){
            //cout << node->val << " ";
            pNode = node;
            node = (Node*)((uintptr_t)(prev)^(uintptr_t)(node->npx));
            prev = pNode;
        }
        //cout << node->val << "\n";
        return node->val;
    }
    
};


int main(){
    
    XORDLL x;
    x.add(1);
    x.add(2);
    x.add(3);
    x.add(4);
    x.add(5);
    x.add(6);
    cout << x.get(4) << "\n";
    cout << x.getLast() << "\n";
}
