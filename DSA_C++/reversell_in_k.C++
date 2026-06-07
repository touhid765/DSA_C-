//reverse node in k group
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* end = dummy;
        while(end->next != NULL){
            for(int i = 0; i < k && end != NULL; i++){
                end = end->next;
            }
            if(end == NULL) break;
            ListNode* start = pre->next;
            ListNode* next = end->next;
            end->next = NULL;
            pre->next = reverse(start);
            start->next = next;
            pre = start;
            end = pre;
        }
        return dummy->next;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* pre = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* nextTemp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nextTemp;
        }
        return pre;
    }
};