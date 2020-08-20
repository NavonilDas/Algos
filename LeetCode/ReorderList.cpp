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
    void reorderList(ListNode* head) {
        ListNode* tmpHead = head;
        if(head == NULL || head->next == NULL || head->next->next == NULL) return;
        
        while((tmpHead != NULL && tmpHead->next != NULL)){
            ListNode* tail = tmpHead;        
            ListNode* prev = NULL;
            while(tail->next != NULL) {
                prev = tail;
                tail = tail->next;
            }
            // cout<<tmpHead->val<<" "<<tail->val<<endl;
            if(tail==tmpHead || tmpHead->next == tail) break;
            tail->next = tmpHead->next;
            tmpHead->next = tail;
            tmpHead = tail->next;
            prev->next = NULL;
            if(tail==tmpHead) break;
        }
        // cout<<tmpHead->val<<endl;
    }
};