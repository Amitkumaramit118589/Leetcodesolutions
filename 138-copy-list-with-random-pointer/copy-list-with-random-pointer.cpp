/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        Node* dummy=new Node(0);
        Node* temp2=dummy;
        map<Node*,Node*>mp;
        while(temp){
            temp2->next=new Node(temp->val);
            mp[temp]=temp2->next;
            temp2=temp2->next;
            temp=temp->next;
            
        }
        temp=head;
        temp2=dummy->next;
        while(temp){
           temp2->random=mp[temp->random];
           temp2=temp2->next;
           temp=temp->next;
        }
        return dummy->next;


    }
};