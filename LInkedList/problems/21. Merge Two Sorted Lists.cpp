/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* fhead = nullptr;
        ListNode* ftail = nullptr;
        while(list1 && list2){
            if(list1->val <= list2->val){
                if(fhead==NULL){
                    fhead = list1;
                    ftail = list1;
                    list1 = list1->next;
                }else{
                    ftail->next = list1;
                    ftail = ftail->next;
                    list1 = list1->next;
                }
            }else{
                if(fhead==NULL){
                    fhead = list2;
                    ftail = list2;
                    list2 = list2->next;
                }else{
                    ftail->next = list2;
                    ftail = ftail->next;
                    list2 = list2->next;
                }
            }
        }
        
        while(list1){
            if(fhead==NULL){
                fhead = list1;
                return fhead;
            }
            ftail->next = list1;
            ftail = ftail->next;
            list1 = list1->next;
        }
        
        while(list2){
            if(fhead == NULL){
                fhead = list2;
                return fhead;
            }
            ftail->next = list2;
            ftail = ftail->next;
            list2 = list2->next;
        }
        return fhead;
    }
};