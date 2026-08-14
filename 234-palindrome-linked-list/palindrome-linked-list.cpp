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
        int n = 0;

        ListNode* temp = head;

        while(temp != NULL){
            temp = temp->next;
            n++;
        }

        ListNode* middle = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            middle = middle->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = middle->next;
        ListNode* forward = NULL;

        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        temp = prev;

        while(temp != NULL){
            if(head->val != temp->val){
                return 0;
            }
            head = head->next;
            temp = temp->next;
        }

        return 1;
    }
};