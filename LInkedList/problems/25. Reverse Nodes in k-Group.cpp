/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
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
    
    int length(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
            len++;
            temp = temp->next;
        }
        return len;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = length(head);
        int count  = 0;
        if(k>len){
            return head;
        }else{
            ListNode* prev = nullptr;
            ListNode* curr = head;
            ListNode* future  = head->next;
            while(count<k){
                curr->next = prev;
                prev = curr;
                curr = future;
                count++;
                if(future!=nullptr)future = future->next;
            }
            ListNode* back = reverseKGroup(curr,k);
            head->next = back;
            return prev;
        }
    }
    
    
};