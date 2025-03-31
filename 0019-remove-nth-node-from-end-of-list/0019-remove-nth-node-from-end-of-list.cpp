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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;

        ListNode* temp = head;

        while(temp)
        {
            size++;
            temp = temp->next;
        }

         if (size == n) {
        ListNode* newHead = head->next;
        delete head; 
        return newHead;
    }

        int actualSize = size - n - 1;

        temp = head;
        while(actualSize--)
        {
            temp = temp->next;
        }

        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        return head;
    }
};