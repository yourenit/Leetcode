/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//此方法开辟另一条链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p= new ListNode(0);
        ListNode* q=p;
        //ListNode* a=l1;
        
        while(l1 && l2){
            if(l1->val > l2->val){
                p->next=l2;
                l2=l2->next;
            }else{
                p->next=l1;
                l1=l1->next;
            }
            p=p->next;
        }
        //连接较长的链表
        if(l1!=nullptr)
            p->next=l1;
        if(l2!=nullptr)
            p->next=l2;
        
        return q->next;
    }
};