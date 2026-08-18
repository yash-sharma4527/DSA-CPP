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
        if(head == NULL || k==1){
            return head;
        }

        int cnt = 0;
        ListNode* temp = head;

        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        if(cnt<k) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;

        cnt = 0;

        while(curr != NULL && cnt < k){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }

        ListNode* newhead = reverseKGroup(curr,k);

        head->next = newhead;

        return prev;
    }
};