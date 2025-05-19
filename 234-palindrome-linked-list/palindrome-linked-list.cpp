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
    bool isPalindrome(ListNode* head) {
        vector<int>temp;
        ListNode* t=head;
        while(t!=NULL){
            temp.push_back(t->val);
            t=t->next;
        }
        reverse(temp.begin(),temp.end());
        int i=0;
        t=head;
        while(t!=NULL){
            if(temp[i]!=t->val)return false;
            t=t->next;
            i++;
        }
        return true;
    }
};