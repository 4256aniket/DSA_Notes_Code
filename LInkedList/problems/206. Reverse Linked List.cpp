/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)return head;
        if(head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* future = head->next;
        while(curr!=NULL){
            curr->next = prev;
            prev = curr;
            curr = future;
            if(future!=nullptr)future = future->next;
        }
        return prev;
    }
};