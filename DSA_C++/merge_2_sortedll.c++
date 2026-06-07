//merge 2sorted linked list
class Solution {
public:
    Listnode*mergeTwoLists(Listnode* head1, Listnode* head2){
        if(head1=NULL || head2==NULL){
            return head1==NULL? head2:head1;
        }
        if(head1->val <= head2->val){
            head1->next=mergeTwoLists(head1->next,head2);
            return head1;
        }else{
            head2->next=mergeTwoLists(head1->next,head2);
            return head2;
        }
    }

};