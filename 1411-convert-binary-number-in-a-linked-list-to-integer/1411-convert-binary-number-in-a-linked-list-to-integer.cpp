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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int sizeOfLL = 0;

        while(temp != NULL) {
            sizeOfLL++;
            temp = temp->next;
        }

        int ans = 0;
        sizeOfLL -=1;

        temp = head;
        while(temp != NULL) {
            ans = ans + (pow(2, sizeOfLL) * temp->val);
            sizeOfLL--;
            temp = temp->next;
        }

        return ans;
    }
};