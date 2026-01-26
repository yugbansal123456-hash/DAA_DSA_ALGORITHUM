/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        ListNode dummy(0,head);
        ListNode*a=&dummy;
        ListNode*p=&dummy;
        for(int i=1;i<=n;i++){
            a=a->next;
        }
        while(a->next){
            a=a->next;
            p=p->next;
        }
        p->next=p->next->next;
        return dummy.next;
    }
};