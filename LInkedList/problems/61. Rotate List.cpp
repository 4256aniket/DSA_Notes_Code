/*
Given the head of a linked list, rotate the list to the right by k places.

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int length(ListNode *head)
    {
        if (head == NULL)
            return 0;
        ListNode *temp = head;
        int len = 0;
        while (temp)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return head;
        int len = length(head);
        k = k % len;
        while (k--)
        {
            ListNode *tail = head;
            ListNode *pre = NULL;
            while (tail->next)
            {
                pre = tail;
                tail = tail->next;
            }
            pre->next = NULL;
            tail->next = head;
            head = tail;
        }
        return head;
    }
};

// O(n) solution

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;
        ListNode *temp = head;
        int len = 1;
        while (temp->next)
        {
            len++;
            temp = temp->next;
        }
        temp->next = head;
        k = k % len;
        for (int i = 1; i <= len - k; i++)
        {
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
