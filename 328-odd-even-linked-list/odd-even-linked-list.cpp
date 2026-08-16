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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* odd = new ListNode();
        ListNode* even = new ListNode();

        ListNode* oddH = odd;
        ListNode* evenH = even;

        int n = 1;

        while(head != NULL){
            if(n&1){
                oddH->next = head;
                oddH = oddH->next;
            }
            else{
                evenH->next = head;
                evenH = evenH->next;
            }
            n++;
            head = head->next;
        }

        evenH->next = NULL;

        oddH->next = even->next;

        return odd->next;
    }
};