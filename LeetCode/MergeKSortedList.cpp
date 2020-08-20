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

// Custom Comparator for Priority Queue
bool myCmp(ListNode *a,ListNode *b){
    return a->val > b->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = NULL;
        // Custom Priority Queue
        priority_queue<
                ListNode*,
                vector<ListNode*>,
                function<bool(ListNode*,ListNode*)> 
            > pq(myCmp);
        
        // For each list node insert in the priority Queue
        for(ListNode* tmp:lists){
                ListNode* c = tmp;
                while(c != NULL){
                    pq.push(c); 
                    c = c->next;
                }
        }
        
        ListNode* tmp = NULL;
        
        while(!pq.empty()){
            ListNode* f = pq.top();
            pq.pop();
            
            if(tmp == NULL)
                tmp = f;
            else {
                tmp->next = f;
                tmp = tmp->next;
            }
            if(ans == NULL) ans = tmp;
        }
        
        if(tmp != NULL) tmp->next = NULL;
        
        return ans;
    }
};