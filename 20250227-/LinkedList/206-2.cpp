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
    
        ListNode *reverse(ListNode *p1, ListNode *p2) {
            if (p2 == nullptr) {
                return p1;
            }
            ListNode *tmp = p2->next;
            p2->next = p1;
            return reverse(p2, tmp);
        }
    
        ListNode* reverseList(ListNode* head) {
            return reverse(nullptr, head);
        }
    };