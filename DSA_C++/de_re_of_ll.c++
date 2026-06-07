//detect cycle in a linked list
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
};

//starting point of the cycle in a linked list
class Solution {
public:
    Listnode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                isCycle = true;
                break;
        }
        if(!isCycle)
            return NULL;
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
        }
     
    }
};

//remove cycle in a linked list
class Solution {
public:
    void removeCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                isCycle = true;
                break;
        }
        if(!isCycle)
            return;
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow;
        while(temp->next != slow){
            temp = temp->next;
        }
        temp->next = NULL;
    }
};