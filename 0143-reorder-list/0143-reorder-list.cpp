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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;

        while(temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    ListNode* findMiddle(ListNode * head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next) {
             prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect first half
        if (prev) prev->next = NULL;

        return slow;
    }
    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL) return;
        // Find the middle point
        ListNode* middle = findMiddle(head);
        ListNode* reversed = reverse(middle);

        ListNode* p1 = head;
        ListNode* p2 = reversed;

        while (p1 && p2) {
            ListNode* p1front = p1->next;
            ListNode* p2front = p2->next;

            p1->next = p2;
            if (p1front) p2->next = p1front;

            p1 = p1front;
            p2 = p2front;
        }

    }
};