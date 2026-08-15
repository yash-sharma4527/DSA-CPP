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
        Node* dummy = new Node(0);

        Node* copy = dummy;

        Node* temp = head;

        unordered_map<Node*,Node*> mp;

        while(temp != NULL){
            copy->next = new Node(temp->val);
            copy = copy->next;
            mp[temp] = copy;
            temp = temp->next;
        }

        temp = head;
        copy = dummy->next;

        while(temp != NULL){
            copy->random = mp[temp->random];
            temp = temp->next;
            copy = copy->next;
        }

        return dummy->next;
    }
};