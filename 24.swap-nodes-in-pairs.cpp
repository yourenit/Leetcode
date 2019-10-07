/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
       if(!head)return NULL;
       ListNode* node = new ListNode(0);
       node->next=head;
       ListNode* pre=node;
       ListNode* cur=head;
       ListNode* next=head->next;
       while(cur && next){
           cur->next=next->next;
           next->next=cur;
           pre->next=next;

           pre = cur;
           cur=pre->next;
           if(!cur) return node->next;
           else next = cur->next;
       } 
       return node->next;
    }
};

