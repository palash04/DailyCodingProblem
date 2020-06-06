/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // O(n), O(1)
    ListNode *solve(ListNode *headA,ListNode *headB){
        ListNode *p = headA;
        ListNode *q = headB;
        int plen = 0;
        int qlen = 0;
        while (p != NULL){
            plen++;
            p = p->next;
        }
        while (q != NULL){
            qlen++;
            q = q->next;
        }
        p = headA;
        q = headB;
        if (plen > qlen){
            int diff = plen - qlen;
            for (int i=1;i<=diff;i++){
                p = p->next;
            }
        }else{
            int diff = qlen - plen;
            for (int i=1;i<=diff;i++){
                q = q->next;
            }
        }
        while (p != q){
            p = p->next;
            q = q->next;
        }
        return p;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        return solve(headA,headB);
    }
};
