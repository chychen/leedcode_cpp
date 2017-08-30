// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        if(temp==NULL)return head;
        while(temp!=NULL){
            if(temp->next==NULL)break;
            int current_val = temp->val;
            int next_val = temp->next->val;
            if(next_val==current_val){
                //delete next node
                //wont move next, continue to cmp current node to next node
                ListNode* delNode = temp->next;
                temp->next = temp->next->next;
                //delete delNode;
                //we cannot sure the sruct is created on heap or stack, should not make any assumption in interview
            }else{
                temp = temp->next;
            }
        }
        return head;
    }
};

// neat
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* cur = head;
        while (cur) {
            while (cur->next && cur->val == cur->next->val)
                cur->next = cur->next->next;
            cur = cur->next;
        }
        return head;
    }
};