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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *c1=headA;
        ListNode *c2=headB;
        int count1=0,count2=0,n=0;
        while(c1||c2){
            if(c1){
                count1++;
                c1=c1->next;
            }
            if(c2){
                count2++;
                c2=c2->next;
            }
        }
        c1=headA,c2=headB;
        n=abs(count1-count2);
        if(count1>count2){
            for(int i=1;i<=n;i++){
                c1=c1->next;
            }
        }else if(count1<count2){
            for(int i=1;i<=n;i++){
                c2=c2->next;
            }
        }
        while(c1!=c2){
            c1=c1->next;
            c2=c2->next;
        }
        return c1;
    }
};
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA != pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }
        return pA;
    }
};