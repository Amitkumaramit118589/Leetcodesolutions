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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;
        ListNode* next = nullptr;

        // Count number of nodes
        int count = 0;
        while (curr) {
            count++;
            curr = curr->next;
        }

        curr = head;

        while (count >= k) {
            curr = prev->next;
            next = curr->next;

            // Reverse k nodes
            for (int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }

            // Move prev to curr (which is now the tail of reversed group)
            prev = curr;
            count -= k;
        }

        return dummy.next;
    }
};
