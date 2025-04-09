// 单链表
class MyLinkedList {
    public:
        
        struct LinkedNode{
            int val;
            LinkedNode *next;
            LinkedNode(int val):val(val), next(nullptr){}
        };
    
        LinkedNode *dummyHead;
        int size;
    
        MyLinkedList() {
            dummyHead = new LinkedNode(0);
            size = 0; 
        }
        
        int get(int index) {
            if (index + 1 > size) {
                return -1;
            }
            LinkedNode *p = dummyHead->next;
            for (int i = 0; i < index; i++) {
                p = p->next;
            }
            return p->val;
        }
        
        void addAtHead(int val) {
            LinkedNode *node = new LinkedNode(val);
            node->next = dummyHead->next;
            dummyHead->next = node;
            size++;
        }
        
        void addAtTail(int val) {
            LinkedNode *p = dummyHead;
            while (p->next != nullptr) {
                p = p->next;
            }
    
            LinkedNode *node = new LinkedNode(val);
            p->next = node;
            size++;
        }
        
        void addAtIndex(int index, int val) {
            if (index > size) {
                return;
            }
    
            LinkedNode *p = dummyHead;
            for (int i = 0; i < index; i++) {
                p = p->next;
            }
            LinkedNode *node = new LinkedNode(val);
            node->next = p->next;
            p->next = node;
            size++;
        }
        
        void deleteAtIndex(int index) {
            if (index + 1 > size) {
                return;
            }
            LinkedNode *p = dummyHead;
            for (int i = 0; i < index; i++) {
                p = p->next;
            }
            LinkedNode *tmp = p->next;
            p->next = p->next->next;
            delete tmp;
            size--;
        }
    };
    
    /**
     * Your MyLinkedList object will be instantiated and called as such:
     * MyLinkedList* obj = new MyLinkedList();
     * int param_1 = obj->get(index);
     * obj->addAtHead(val);
     * obj->addAtTail(val);
     * obj->addAtIndex(index,val);
     * obj->deleteAtIndex(index);
     */