/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.

Do this in constant space and in one pass.

Leetcode : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;
    Node(int x): val(x),next(NULL) {}
};

void insert(Node *&head,int value){
    Node *temp = head;
    Node *node = new Node(value);
    if (!head){
        head = node;
        return;
    }
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    return;
}

void printList(Node *head){
    Node *temp = head;
    while (temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// O(n) and O(1)
void removeKthLastElement(Node *&head,int k){
    // as k is guaranteed to be smaller than length of the list
    // so need to validate k
    if (k == 0) {
        return; // no any element to remove
    }
    Node *p = head;
    Node *q = NULL;
    Node *temp = head;
    for (int i=1;i<=k;i++){
        temp = temp->next;
    }
    if (!temp){
        head = p->next;
        return;
    }
    while (temp){
        q = p;
        p = p->next;
        temp = temp->next;
    }
    q->next = p->next;
}

int main(){
    Node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);
    insert(head, 9);
    insert(head, 10);
    insert(head, 11);
    insert(head, 12);
    insert(head, 13);
    int k = 5;
    printList(head);
    removeKthLastElement(head,k);
    printList(head);
}
