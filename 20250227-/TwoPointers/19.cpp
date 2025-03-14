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
            ListNode* dummyHead = new ListNode(0, head);
            ListNode* p1 = dummyHead;
            ListNode* p2 = dummyHead;
            for (int i = 0; i < n ;i++) {
                p2 = p2->next;
            }
            while (p2->next != nullptr) {
                p1 = p1->next;
                p2 = p2->next;
            }
            ListNode* tmp = p1->next;
            p1->next = tmp->next;
            delete tmp;
            return dummyHead->next;
        }
    };