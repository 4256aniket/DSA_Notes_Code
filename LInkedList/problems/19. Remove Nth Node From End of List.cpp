/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
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
        ListNode* temp = head;
        int count  = 0;
        while(temp){
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        int cnt = len - n;
        ListNode* temp = head;
        ListNode* pre = nullptr;
        if(cnt == 0){
            ListNode*a = head->next;
            ListNode*b = head;
            delete b;
            return a;
        }
        while(cnt){
            pre = temp;
            temp = temp->next;
            cnt--;
        }
        ListNode* a = temp;
        pre->next = temp->next;
        delete a;
        return head;
    }
};