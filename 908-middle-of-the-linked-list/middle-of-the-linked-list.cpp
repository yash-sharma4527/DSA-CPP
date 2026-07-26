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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;

        int n = 0;

        while(head != NULL){
            n++;
            head = head -> next;
        }

        int count = n/2 + 1;

        int i = 0;

        while(i<count-1){
            temp = temp->next;
            i++;
        }

        return temp;
    }
};