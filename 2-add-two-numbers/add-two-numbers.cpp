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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        int carry = 0;
        int a;
        int b;

        while(l1 != NULL || l2 != NULL || carry != 0){
            if(l1 != NULL){
                a = l1 -> val; 
                l1 = l1->next;
            }
            else  a = 0;

            if(l2 != NULL){
                b = l2->val;
                l2 = l2->next;
            }
            else b = 0;

            int sum = a+b+carry;

            if(sum>9){
                carry = sum/10;
                sum = sum%10;
            }
            else carry = 0;

            ListNode* l3 = new ListNode(sum);
            temp->next = l3;
            temp = temp->next;
        }

        return dummy->next;
    }
};