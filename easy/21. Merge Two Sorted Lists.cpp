// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
// input
// [1,3,5]
// [2,4,6,9]
// output
// [1,2,3,4,5,6,9]

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* iter = result;
        while(l1!=NULL || l2!=NULL){
            if(l1==NULL){
                iter->next = l2;
                break;
            }
            if(l2==NULL){
                iter->next = l1;
                break;
            }
            if(l1->val<l2->val){
                iter->next = new ListNode(l1->val);
                l1 = l1->next;
                iter = iter->next;
            }else{
                iter->next = new ListNode(l2->val);
                l2 = l2->next;
                iter = iter->next;
            }
        }
        return result->next;
    }
};

// better
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};