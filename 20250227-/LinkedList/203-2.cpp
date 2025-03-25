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
        ListNode* removeElements(ListNode* head, int val) {
            while (head != nullptr && head->val == val) {
                ListNode* temp = head;
                head = head->next;
                delete temp;
            }
            ListNode* p = head;
            while (p != nullptr && p->next != nullptr) {
                if (p->next->val == val) {
                    ListNode* temp = p->next;
                    p->next = p->next->next;
                    delete temp;
                } else {
                    p = p->next;
                }
            }
    
            return head;
        }
    };