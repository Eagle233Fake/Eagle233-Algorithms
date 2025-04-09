/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode *slow = head;
            ListNode *fast = head;
            while (fast && fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                    ListNode *p = head;
                    ListNode *p2 = fast;
                    while (p != p2) {
                        p = p->next;
                        p2 = p2->next;
                    }
                    return p2;
                }
            }
            return nullptr;
        }
    };