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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i = 1;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* forward = curr->next;

        int minD = INT_MAX;
        int maxD = -1;
        int first = -1;
        int prevCritical = -1;

        while(curr != NULL && curr->next != NULL){
            if((curr->val > prev->val && curr->val > forward->val) || (curr-> val < prev->val && curr->val < forward->val)){
                if(first == -1){
                    first = i;
                    prevCritical = i;
                }
                else{
                    minD = min(minD,i-prevCritical);
                    maxD = i - first;
                    prevCritical = i;
                }
            }

            i++;

            prev = curr;
            curr = forward;
            forward = forward->next;
        }

        if(first == -1 || minD == INT_MAX){
            return {-1,-1};
        }

        return {minD,maxD};
    }
};