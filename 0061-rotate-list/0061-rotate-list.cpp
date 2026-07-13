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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return head;
        int len=1;
        ListNode * tail=head;
        while(tail->next){
            tail=tail->next;
            len++;
        }
        ListNode *temp=head;
        k=k%len;
        if(k==0) return head;
        for(int i=1;i<len-k;i++){
            temp=temp->next;

        }
        ListNode* newhead=temp->next;
        temp->next=nullptr;
        tail->next=head;

        return newhead;
    }
};