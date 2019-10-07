/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if( n == 0)return head;
       ListNode* first=head;
       ListNode* last=head;
       while(n){
           first=first->next;n--;
       } 
       if(!first)return head->next;
       while(first->next){
           first=first->next;
           last=last->next;
       }
       last->next = last->next->next;
       return head;
    }
};

