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
    
    // function to get the length of linked list
    int getLength(ListNode* head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    
    
    
    ListNode* middleNode(ListNode* head) {
        int len=getLength(head);
        
        int ans=(len/2);
        
        ListNode* temp=head;
        while(ans--){
            temp=temp->next;
        }
        
        return temp;
    }
};
