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
        ListNode* swapPairs(ListNode* head) {
            ListNode *dummyHead = new ListNode(0, head);
            ListNode *p1 = dummyHead;
            ListNode *p2 = p1->next;
            ListNode *tmp = nullptr;
            while (p2) {
                if (p2->next == nullptr) {
                    break;
                }
                tmp = p2->next;
                p2->next = tmp->next;
                p1->next = tmp;
                tmp->next = p2;
                p1 = p2;
                p2 = p2->next;
            }
            return dummyHead->next;
        }
    };