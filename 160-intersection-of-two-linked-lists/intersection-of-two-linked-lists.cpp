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
        ListNode *tempa=headA;
        ListNode *tempb=headB;
        int lenA=0;
        int lenB=0;
        while(tempa){
            lenA++;
            tempa=tempa->next;
        }
        while(tempb){
            lenB++;
            tempb=tempb->next;
        }
        tempa=headA;
        tempb=headB;

        if(lenA>lenB){
            for(int i=0;i<lenA-lenB;i++){
                tempa=tempa->next;
            }
        }
        else if(lenA<lenB){
            for(int i=0;i<lenB-lenA;i++){
                tempb=tempb->next;
            }
        }
        while(tempa!=NULL && tempb!=NULL){
              if(tempa==tempb) return tempa;
              tempa=tempa->next;
              tempb=tempb->next;
        }
        return NULL;
        
    }
};