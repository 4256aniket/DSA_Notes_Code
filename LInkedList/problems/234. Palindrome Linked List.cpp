/*
Given the head of a singly linked list, return true if it is a palindrome.

Input: head = [1,2,2,1]
Output: true

Input: head = [1,2]
Output: false
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
    bool isPalindrome(ListNode* head) {

        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = NULL;
        ListNode* nxt;
        while (slow != NULL) {
            nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }
        ListNode* j = prev;
        ListNode* i = head;
        while (j != NULL) {
            if (i->val != j->val)
                return false;
            i = i->next;
            j = j->next;

        }
        return true;
    }
};