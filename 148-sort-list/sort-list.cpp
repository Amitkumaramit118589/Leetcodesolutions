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
 ListNode* find_mid(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list into two halves
    if (prev != NULL) prev->next = NULL;

    return slow; // mid
}
 ListNode* merge(ListNode* left,ListNode* right){
    if(left==NULL) return right;
    if(right==NULL) return left;

    ListNode* dummy=new ListNode(0);
    ListNode* temp=dummy;

    while(left!=NULL && right!=NULL){
        if(left->val > right->val){
            temp->next=right;
            //temp=right;
            right=right->next;
            
        }
        else{
            temp->next=left;
            //temp=left;
            left=left->next;
            
        }
        temp=temp->next;
    }
     if (left != NULL) temp->next = left;
    if (right != NULL) temp->next = right;
    return dummy->next;
 }
class Solution {
public:
     ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* mid = find_mid(head); // now the list is broken into 2 part

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        return merge(left, right);
    }
};