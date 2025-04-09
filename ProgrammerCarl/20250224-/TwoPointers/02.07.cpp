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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            int sizeA = 0;
            int sizeB = 0;
            ListNode *p1 = headA;
            ListNode *p2 = headB;
            while (p1) {
                p1 = p1->next;
                sizeA++;
            }
            while (p2) {
                p2 = p2->next;
                sizeB++;
            }
    
            p1 = headA;
            p2 = headB;
            if (sizeA > sizeB) {
                for (int i = 0; i < sizeA - sizeB; i++) {
                    p1 = p1->next;
                }
            } else {
                for (int i = 0; i < sizeB - sizeA; i++) {
                    p2 = p2->next;
                }
            }
    
            while (p1 && p2) {
                if (p1 == p2) {
                    return p1;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
            return nullptr;
        }
    };