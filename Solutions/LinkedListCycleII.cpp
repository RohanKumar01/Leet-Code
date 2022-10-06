class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast -> next != NULL){
            
            
            fast = fast -> next;
            if(fast -> next != NULL){
                fast = fast -> next;
            }
            slow = slow -> next;
            
            if(fast == slow && fast -> next != NULL){
                slow = head;
                while(fast != slow ){
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
            
        }
        
        return NULL;
        
    }
};
