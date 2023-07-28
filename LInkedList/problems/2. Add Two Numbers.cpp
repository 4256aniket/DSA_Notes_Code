/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = nullptr;
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* temp1 = nullptr;
        int c = 0;
        while(p!=nullptr && q!=nullptr){
            int sum = p->val + q->val + c;
            c = 0;
            if(sum/10 != 0){
                c = 1;
            }
            ListNode* temp2 = new ListNode(sum%10);
            if(temp1==nullptr){
                temp1 = temp2;
            }else{
                temp1->next = temp2;
                temp1 = temp2;
            }
            if(ans == nullptr){
                ans = temp1;
            }
            
                
            p = p->next;
            q = q->next;
        }
        while(p!=nullptr){
            int sum = p->val + c;
            c = 0;
            if(sum/10 != 0){
                c = 1;
            }
            ListNode* temp2 = new ListNode(sum%10);
            if(temp1==nullptr){
                temp1 = temp2;
            }else{
                temp1->next = temp2;
                temp1 = temp2;
            }
            if(ans == nullptr){
                ans = temp1;
            }
            p = p->next;   
            
        }
        while(q!=nullptr){
            int sum = q->val + c;
            c = 0;
            if(sum/10 != 0){
                c = 1;
            }
             ListNode* temp2 = new ListNode(sum%10);
            if(temp1==nullptr){
                temp1 = temp2;
            }else{
                temp1->next = temp2;
                temp1 = temp2;
            }
            if(ans == nullptr){
                ans = temp1;
            }
            q = q->next;
        }
    
        if(c==1){
            ListNode* temp2 = new ListNode(c);
            if(temp1==nullptr){
                temp1 = temp2;
            }else{
                temp1->next = temp2;
                temp1 = temp2;
            }
            if(ans == nullptr){
                ans = temp1;
            }
        }
        return ans;
    }
};