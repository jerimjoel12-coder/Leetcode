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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        add(l1, l2, carry, head, tail);
        if (carry) {
            tail->next = new ListNode(carry);
        }
        return head;
    }

private:
    void add(ListNode* l1, ListNode* l2, int& carry, ListNode*& head, ListNode*& tail) {
        if (l1 == nullptr && l2 == nullptr) return;
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        ListNode* node = new ListNode(sum%10);
        if (!head) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
        carry = sum/10;
        add(l1, l2, carry, head, tail);
    }
};