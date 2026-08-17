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
    ListNode* merge(ListNode* h1,ListNode* h2){
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        while(h1 != NULL && h2 != NULL){
            if(h1->val < h2->val){
                temp->next = h1;
                temp = temp->next;
                h1 = h1->next;
            }
            else{
                temp->next = h2;
                temp = temp->next;
                h2 = h2->next;
            }
        }

        if(h1 != NULL){
            temp->next = h1;
        }

        if(h2 != NULL){
            temp->next = h2;
        }

        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = slow->next;
        slow->next = NULL; 

        ListNode* h1 = mergeSort(head);
        ListNode* h2 = mergeSort(head2);
 
        return merge(h1,h2);
    }
public:
    ListNode* sortList(ListNode* head) {
        
        return mergeSort(head);

    }
};