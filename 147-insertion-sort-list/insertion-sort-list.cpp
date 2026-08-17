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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode();

        while(head != NULL){
            ListNode* track = head->next;
            ListNode* temp = dummy;

            if(temp->next == NULL){
                temp->next = head;
                head->next = NULL;
            }

            else{
                while(temp->next != NULL){
                    if(temp->next->val > head->val){
                        ListNode* forward = temp->next;
                        temp->next = head;
                        head->next = forward;
                        break;
                    }
                    temp = temp->next;
                }

                if(temp->next==NULL){
                    temp->next = head;
                    head->next = NULL;
                }
            }
            head = track;
        }

        return dummy->next;
    }
};