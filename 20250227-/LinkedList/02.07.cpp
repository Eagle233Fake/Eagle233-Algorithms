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
                sizeA++;
                p1 = p1->next;
            }
            while (p2) {
                sizeB++;
                p2 = p2->next;
            }
            p1 = headA;
            p2 = headB;
    
            int a;
            if (sizeA > sizeB) {
                a = sizeA - sizeB;
                for (int i = 0; i < a; i++) {
                    p1 = p1->next;
                }
            } else {
                a = sizeB - sizeA;
                for (int i = 0; i < a; i++) {
                    p2 = p2->next;
                }
            }
    
            while (p1) {
                if (p1 == p2) {
                    return p1;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
            return nullptr;
        }
    };