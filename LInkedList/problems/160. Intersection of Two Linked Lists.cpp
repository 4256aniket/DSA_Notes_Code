/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:

The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        while(l1!=nullptr && l2!=nullptr){
            l1= l1->next;
            l2= l2->next;
        }
        if(l1==nullptr){
            l1 = headB;
        }else{
            l2 = headA;
        }
        while(l1!=nullptr && l2!=nullptr){
            l1= l1->next;
            l2= l2->next;
        }
        if(l1==nullptr){
            l1 = headB;
        }else{
            l2 = headA;
        }
        while(l1!=nullptr && l2!=nullptr){
            if(l1==l2){
                return l1;
            }else{
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        return nullptr;
    }
};